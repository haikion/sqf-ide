/*
 * @Description 
 * Reads commands.xml and constructs data structures according to it.
 */

package org.xtext.arma;

import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.xpath.XPath;
import javax.xml.xpath.XPathConstants;
import javax.xml.xpath.XPathExpression;
import javax.xml.xpath.XPathExpressionException;
import javax.xml.xpath.XPathFactory;

import org.eclipse.core.resources.IProject;
import org.eclipse.core.resources.IWorkspace;
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.core.runtime.FileLocator;
import org.eclipse.core.runtime.Path;
import org.eclipse.core.runtime.Platform;
import org.w3c.dom.Document;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

public class XMLReader
{
    static final String XML_FILE_PATH = "commands.xml";

    private static Set<String> commandLefts_ = new HashSet<String>();
    private static Set<String> commandMiddles_ = new HashSet<String>();
    private static Set<String> commandParentlesses_ = new HashSet<String>();
    private static Set<String> functions_ = new HashSet<String>();
    private static XPath xpath_ = XPathFactory.newInstance().newXPath();
    private static HashMap<String, String> docs_ = new HashMap<String, String>();
    private static Map<String, Long> cache_ = new HashMap<String, Long>();
    private static DocumentBuilder builder_;
    private static XPathExpression nameText_;
    private static XPathExpression docText_;
    
    public static String getCommandDoc(String command)
    {
        readCoreXml();
        String key = command.toUpperCase();
        String doc = docs_.get(key);
        return doc;
    }
    
    public static Set<String> getCommandLefts()
    {
        readCoreXml();
        return commandLefts_;
    }
    
    public static Set<String> getCommandMiddles()
    {
        readCoreXml();
        return commandMiddles_;
    }
    
    public static Set<String> getCommandParentlesses()
    {
        readCoreXml();
        return commandParentlesses_;
    }
    
    public static Set<String> getFunctions(IProject project)
    {
        readXml(project);
        return functions_;
    }
    
    public static Set<String> getFunctions()
    {
        readCoreXml();
        return functions_;
    }
    
    public static Set<String> getFunctions(File xmlFile)
    {
        readCoreXml();
        readXMLFile(xmlFile);
        return functions_;
    }
    
    public static Set<String> getCommandMiddlesUpper()
    {
        return toUpperSet(getCommandMiddles());
    }

    public static Set<String> getCommandLeftsUpper()
    {
        return toUpperSet(getCommandLefts());
    }
    
	public static Set<String> getCommandParentlessesUpper() {
		return toUpperSet(getCommandParentlesses());
	}
    
	public static void createBuilder()
	{
        
        DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
        factory.setNamespaceAware(false);
        factory.setValidating(false);
        try
        {
            factory.setFeature("http://xml.org/sax/features/namespaces", false);
            factory.setFeature("http://xml.org/sax/features/validation", false);
            factory.setFeature("http://apache.org/xml/features/nonvalidating/load-dtd-grammar", false);
            factory.setFeature("http://apache.org/xml/features/nonvalidating/load-external-dtd", false);
        	//Unit testing path
            builder_ = factory.newDocumentBuilder();
        }
        catch (ParserConfigurationException e) 
        {
            e.printStackTrace();
            return;
        }
	}
	
    private static void readXMLFile(final File sourceFile)
    {
        //Run only once.
    	Long size = new Long(sourceFile.length());
    	Long cacheSize = cache_.get(sourceFile.getAbsolutePath());
        if (size.equals(cacheSize))
        {
        	System.out.println("Using cached " + sourceFile.getAbsolutePath());
            return;
        }
        if (builder_ == null)
        	createBuilder();
        	
        Document document;
        try
        {
        	//Unit testing path
            document = builder_.parse(sourceFile);

        }
        catch (SAXException | IOException e) 
        {
            e.printStackTrace();
            return;
        }
        commandLefts_.addAll(getCommandsByType("commandLefts", document));
        commandMiddles_.addAll(getCommandsByType("commandMiddles", document));
        commandParentlesses_.addAll(getCommandsByType("commandParentlesses", document));
        functions_.addAll(getCommandsByType("functions", document));
        cache_.put(sourceFile.getAbsolutePath(), sourceFile.length());
    }
    
    private static void readCoreXml()
    {
        File sourceFile  = new File("..\\org.xtext.arma.sqf\\" + XML_FILE_PATH);
        //Installation path
        if (!sourceFile.isFile())
        {
        	System.out.println("Using installation path");
        	URL url = FileLocator.find(Platform.getBundle("org.xtext.arma.sqf"), new Path(XML_FILE_PATH), null);
			try {
				String jarPath = FileLocator.resolve(url).getPath();
	            sourceFile = new File(jarPath);
			} catch (IOException e) {
				e.printStackTrace();
				return;
			}
        }
        System.out.println("sourceFile = " + sourceFile.getAbsolutePath());
		readXMLFile(sourceFile);
    }
    
    private static void readModsXml(IProject project)
    {
		System.out.println("Parsing functions from " + project.getName());
		File projectDir = project.getLocation().toFile();
		File includesDir = new File(projectDir.getAbsolutePath() + "/includes");
		if (!includesDir.isDirectory())
		{
			System.out.println("Warning: Includes directory " + includesDir.getAbsolutePath() + " does not exist");
			return;
		}
		for (File modDir : includesDir.listFiles())
		{
			File functionsXml = new File(modDir.getAbsolutePath() + "/functions.xml");
			if (functionsXml.isFile())
			{
				readXMLFile(functionsXml);
			}
		}
    }
    
    private static void readXml(IProject project)
    {
        readCoreXml();
        readModsXml(project);
    }

    private static ArrayList<String> getCommandsByType(String type, Document document)
    {
        ArrayList<String> list = new ArrayList<>();

        try 
        {
            XPathExpression expr =
                    xpath_.compile("/commands/" + type + "/command");
            //evaluate expression result on XML document
            NodeList nodes = (NodeList) expr.evaluate(document, XPathConstants.NODESET);
            if (nameText_ == null)
            {
                nameText_ = xpath_.compile("name/text()");
                docText_ = xpath_.compile("doc/text()");
            }
            for (int i = 0; i < nodes.getLength(); i++)
            {
                Node item = nodes.item(i);
                String name = (String) nameText_.evaluate(item, XPathConstants.STRING);
                String doc = (String) docText_.evaluate(item, XPathConstants.STRING);
                list.add(name);
                if (doc != null)
                {
                    docs_.put(name.toUpperCase(), doc);
                }
            }
        } 
        catch (XPathExpressionException e) 
        {
            e.printStackTrace();
        }
        
        return list;
    }
    
    private static Set<String> toUpperSet(Set<String> input)
    {
        Set<String> output = new HashSet<String>();
        
        for (String value : input)
        {
            output.add(value.toUpperCase());
        }
        return output;
    }
}
