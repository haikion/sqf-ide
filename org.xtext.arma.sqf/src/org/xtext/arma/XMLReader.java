/*
 * @Author Niko Häikiö
 * @Description 
 * Reads commands.xml and constructs data structures according to it.
 */
package org.xtext.arma;

import java.io.IOException;
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

import org.w3c.dom.Document;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

public class XMLReader
{
    static final String XML_FILE_PATH = "commands.xml";

    static private ArrayList<String> commandLefts_ = new ArrayList<String>();
    static private ArrayList<String> commandMiddles_ = new ArrayList<String>();
    static private ArrayList<String> commandParentlesses_ = new ArrayList<String>();
    static private XPath xpath_ = XPathFactory.newInstance().newXPath();
    static private Document document_;
    static private HashMap<String, String> docs_ = new HashMap<String, String>();
    
    static private void readXML()
    {
        //Run only once.
        if (document_ != null)
        {
            return;
        }
        
        DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
        factory.setNamespaceAware(true);
        DocumentBuilder builder;
        try {
            builder = factory.newDocumentBuilder();
            document_ = builder.parse(XML_FILE_PATH);

        } catch (ParserConfigurationException | SAXException | IOException e) {
            e.printStackTrace();
        }
        commandLefts_ = getCommandsByType("commandLefts");
        commandMiddles_ = getCommandsByType("commandMiddles");
        commandParentlesses_ = getCommandsByType("commandParentlesses");
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

    static private ArrayList<String> toUpperArray(ArrayList<String> input)
    {
        ArrayList<String> output = new ArrayList<String>();
        
        for (String value : input)
        {
            output.add(value.toUpperCase());
        }
        return output;
    }
    
    static public String getCommandDoc(String command)
    {
        readXML();
        String key = command.toUpperCase();
        String doc = docs_.get(key);
        return doc;
    }
    
    static public ArrayList<String> getCommandLefts()
    {
        readXML();
        return commandLefts_;
    }
    
    static public ArrayList<String> getCommandMiddles()
    {
        readXML();
        return commandMiddles_;
    }
    
    static public ArrayList<String> getCommandParentlesses()
    {
        readXML();
        return commandParentlesses_;
    }
    
    static public ArrayList<String> getCommandMiddlesUpper()
    {
        return toUpperArray(getCommandMiddles());
    }

    static public ArrayList<String> getCommandLeftsUpper()
    {
        return toUpperArray(getCommandLefts());
    }
}
