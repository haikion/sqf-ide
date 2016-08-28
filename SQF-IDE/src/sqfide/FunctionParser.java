/*
 * Parses Function introductions from directories and Arma config files
 */

package sqfide;

import org.arma.sqmparser.SQMParser;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.apache.commons.io.FileUtils;
import org.arma.sqmparser.ClassNode;
import org.arma.sqmparser.Parameter;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;

import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class FunctionParser 
{
	//Used to filter files for performance reasons when reading whole folders. 
	public static final List<String> ALLOWED_EXTENSIONS = Collections.unmodifiableList(Arrays.asList("cpp", "hpp", "h"));

	public static boolean parseToXml(File folder)
	{
		Set<String> functionsSet = parseFolder(folder);
		DocumentBuilderFactory docFactory = DocumentBuilderFactory.newInstance();
		try {
			DocumentBuilder docBuilder = docFactory.newDocumentBuilder();
			// root elements
			Document doc = docBuilder.newDocument();
			Element rootElement = doc.createElement("commands");
			doc.appendChild(rootElement);
			
			Element functions = doc.createElement("functions");
			rootElement.appendChild(functions);
			
			for (String func : functionsSet)
			{
				Element cmd = doc.createElement("command");
				Element name = doc.createElement("name");
				name.appendChild(doc.createTextNode(func));
				cmd.appendChild(name);
				functions.appendChild(cmd);
			}

			// write the content into xml file
			TransformerFactory transformerFactory = TransformerFactory.newInstance();
			Transformer transformer = transformerFactory.newTransformer();
			DOMSource source = new DOMSource(doc);
			StreamResult result = new StreamResult(new File(folder.getAbsolutePath() + "/functions.xml"));

			// Output to console for testing
			// StreamResult result = new StreamResult(System.out);

			transformer.transform(source, result);			
		}
		catch (Exception e)
		{
			e.printStackTrace();
			return false;
		}
		
		return true;
	}
	
	public static Set<String> parseFile(File file) throws IOException
	{	
		Set<String> rVal = new HashSet<String>();
		String content = FileUtils.readFileToString(file);
		//Case insensitive contains
		Pattern p = Pattern.compile("cfgfunctions", Pattern.CASE_INSENSITIVE);
		if (!p.matcher(content).find())
		{
			return rVal;
		}
		content = combineIncludes(content, file);
		SQMParser parser = new SQMParser();
		parser.parseString(content);
		ArrayList<ClassNode> cfgfuncs = parser.getClassesByName("CfgFunctions");
		for (ClassNode node : cfgfuncs)
		{
			rVal.addAll(parseCfgFunctions(node));
		}
		
		//ToDo
		return rVal;
	}
	
	//Recursively parses folder
	public static Set<String> parseFolder(File folder)
	{
		Set<String> rVal = new HashSet<String>();
		for (File file2 : folder.listFiles())
		{
			String extension = getExtensions(file2.getName());
			
			if (file2.isFile() &&  ALLOWED_EXTENSIONS.contains(extension))
				try {
					rVal.addAll(parseFile(file2));
				} catch (IOException e) {
					e.printStackTrace();
				}
			else if (file2.isDirectory())
			{
				rVal.addAll(parseFolder(file2));
			}
		}
		return rVal;
	}
	
	private static String getExtensions(String fileName)
	{
		String extension = "";

		int i = fileName.lastIndexOf('.');
		if (i > 0) {
		    extension = fileName.substring(i+1);
		}
		
		return extension;
	}
	
	private static ArrayList<String> parseCfgFunctions(ClassNode node)
	{
		ArrayList<String> rVal = new ArrayList<String>();
		for (ClassNode child : node.getChildren())
		{
			rVal.addAll(parseTag(child));
		}
		
		return rVal;
	}
	
	private static ArrayList<String> parseTag(ClassNode node)
	{
		ArrayList<String> rVal = new ArrayList<String>();
		
		Parameter param = node.getParameter("tag");
		String tag;
		if (param == null || (tag = param.getValue()) == null || tag.isEmpty())
			tag = node.getName();
		
		tag = tag.replaceAll("\"", "");
		for (ClassNode category : node.getChildren())
		{
			for (ClassNode function : category.getChildren())
			{
				rVal.add(tag + "_fnc_" + function.getName());
			}
		}
		
		return rVal;
	}
	
	private static String file2String(String path)
	{
		Path filePath = Paths.get(path);

		byte[] contentBytes;
		try {
			contentBytes = Files.readAllBytes(filePath);
		} catch (IOException e) {
			e.printStackTrace();
			return null;
		}
		String content = new String(contentBytes, StandardCharsets.ISO_8859_1);
		return content;
	}
	
	private static String replaceRange(String orig, int start, int end, String replacement)
	{
		String part1 = orig.substring(0, start);
		String part2 = orig.substring(end);
		return (part1 + replacement + part2);
	}
	
	//Replaces #include statement with copy paste
	private static String combineIncludes(String content, File includeFile)
	{
		final Pattern INCLUDE_REGEX = Pattern.compile("#include\\s*\"(.*)\"");

		String rVal = new String(content);
		Matcher m = INCLUDE_REGEX.matcher(content);
			
		while (m.find())
		{
			File includedFile = new File(includeFile.getParentFile().getAbsolutePath() + "/" + m.group(1));
			String includeText;
			try {
				includeText = FileUtils.readFileToString(includedFile);
			} catch (IOException e) {
				includeText = "";
			}
			includeText = combineIncludes(includeText, includedFile);
			
			rVal = replaceRange(rVal, m.start(), m.end(), content);
		}
		return rVal;
	}
}
