/*
 * @Author Niko Häikiö
 * @Description 
 * Reads commands.xml and constructs data structures according to it.
 */
package org.xtext.arma;

import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.util.HashMap;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.xpath.XPath;
import javax.xml.xpath.XPathConstants;
import javax.xml.xpath.XPathExpression;
import javax.xml.xpath.XPathExpressionException;
import javax.xml.xpath.XPathFactory;

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

    private static ArrayList<String> commandLefts_ = new ArrayList<String>();
    private static ArrayList<String> commandMiddles_ = new ArrayList<String>();
    private static ArrayList<String> commandParentlesses_ = new ArrayList<String>();
    private static ArrayList<String> functions_ = new ArrayList<String>();
    private static XPath xpath_ = XPathFactory.newInstance().newXPath();
    private static Document document_;
    private static HashMap<String, String> docs_ = new HashMap<String, String>();
    
    private static void readXML()
    {
        //Run only once.
        if (document_ != null)
        {
            return;
        }
        
        DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
        factory.setNamespaceAware(true);
        DocumentBuilder builder;
        try
        {
        	//Unit testing path
            File sourceFile  = new File("..\\org.xtext.arma.sqf\\" + XML_FILE_PATH);
            System.out.println("sourceFile = " + sourceFile.getAbsolutePath());
            builder = factory.newDocumentBuilder();
            //Installation path
            if (!sourceFile.isFile())
            {
            	System.out.println("Using installation path");
            	URL url = FileLocator.find(Platform.getBundle("org.xtext.arma.sqf"), new Path(XML_FILE_PATH), null);
                String jarPath = FileLocator.resolve(url).getPath();
                sourceFile = new File(jarPath);
            }
            document_ = builder.parse(sourceFile);

        }
        catch (ParserConfigurationException | SAXException | IOException e) 
        {
            e.printStackTrace();
            return;
        }
        commandLefts_ = getCommandsByType("commandLefts");
        commandMiddles_ = getCommandsByType("commandMiddles");
        commandParentlesses_ = getCommandsByType("commandParentlesses");
        functions_ = parseFunctions();
    }
    
    private static ArrayList<String> parseFunctions()
    {
        ArrayList<String> list = new ArrayList<>();
        try 
        {
            XPathExpression expr =
                    xpath_.compile("/commands/functions/command");
            //evaluate expression result on XML document
            NodeList nodes = (NodeList) expr.evaluate(document_, XPathConstants.NODESET);
            for (int i = 0; i < nodes.getLength(); i++)
            {
                Node item = nodes.item(i);
                String name = (String) xpath_.compile("name/text()").evaluate(item, XPathConstants.STRING);
                String doc = (String) xpath_.compile("doc/text()").evaluate(item, XPathConstants.STRING);
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

    private static ArrayList<String> getCommandsByType(String type)
    {
        ArrayList<String> list = new ArrayList<>();
        try {
            XPathExpression expr =
                    xpath_.compile("/commands/" + type + "/command");
            //evaluate expression result on XML document
            NodeList nodes = (NodeList) expr.evaluate(document_, XPathConstants.NODESET);
            for (int i = 0; i < nodes.getLength(); i++)
            {
                Node item = nodes.item(i);
                String name = (String) xpath_.compile("name/text()").evaluate(item, XPathConstants.STRING);
                String doc = (String) xpath_.compile("doc/text()").evaluate(item, XPathConstants.STRING);
                list.add(name);
                if (doc != null)
                {
                    docs_.put(name.toUpperCase(), doc);
                }
            }
        } catch (XPathExpressionException e) {
            e.printStackTrace();
        }
        
        return list;
    }

    private static ArrayList<String> toUpperArray(ArrayList<String> input)
    {
        ArrayList<String> output = new ArrayList<String>();
        
        for (String value : input)
        {
            output.add(value.toUpperCase());
        }
        return output;
    }
    
    public static String getCommandDoc(String command)
    {
        readXML();
        String key = command.toUpperCase();
        String doc = docs_.get(key);
        return doc;
    }
    
    public static ArrayList<String> getCommandLefts()
    {
        readXML();
        return commandLefts_;
    }
    
    public static ArrayList<String> getCommandMiddles()
    {
        readXML();
        return commandMiddles_;
    }
    
    public static ArrayList<String> getCommandParentlesses()
    {
        readXML();
        return commandParentlesses_;
    }
    
    public static ArrayList<String> getFunctions()
    {
        readXML();
        return functions_;
    }
    
    public static ArrayList<String> getCommandMiddlesUpper()
    {
        return toUpperArray(getCommandMiddles());
    }

    public static ArrayList<String> getCommandLeftsUpper()
    {
        return toUpperArray(getCommandLefts());
    }
}
