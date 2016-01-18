/*
 * @Author Niko Häikiö
 * @Description 
 * Reads commands.xml and constructs data structures according to it.
 */
package org.xtext.arma;

import java.io.IOException;
import java.util.ArrayList;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.xpath.XPath;
import javax.xml.xpath.XPathConstants;
import javax.xml.xpath.XPathExpression;
import javax.xml.xpath.XPathExpressionException;
import javax.xml.xpath.XPathFactory;

import org.w3c.dom.Document;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

public class XMLReader
{
    static final String XML_FILE_PATH = "commands.xml";

    ArrayList<String> commandMiddles_ = new ArrayList<String>();
    ArrayList<String> commandLefts_ = new ArrayList<String>();
    ArrayList<String> commandParentlesses_ = new ArrayList<String>();
    static XPath xpath_ = XPathFactory.newInstance().newXPath();
    static Document document_;


    public XMLReader(String filePath)
    {
        readXML(filePath);
    }

    public XMLReader()
    {
        readXML(XML_FILE_PATH);
    }

    private void readXML(String filePath)
    {
        DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
        factory.setNamespaceAware(true);
        DocumentBuilder builder;
        try {
            builder = factory.newDocumentBuilder();
            document_ = builder.parse(filePath);

        } catch (ParserConfigurationException | SAXException | IOException e) {
            e.printStackTrace();
        }
    }
    
    private static ArrayList<String> getCommandsByType(String type)
    {
        ArrayList<String> list = new ArrayList<>();
        try {
            //create XPathExpression object
            XPathExpression expr =
                xpath_.compile("/commands/" + type + "/command/name/text()");
            //evaluate expression result on XML document
            NodeList nodes = (NodeList) expr.evaluate(document_, XPathConstants.NODESET);
            for (int i = 0; i < nodes.getLength(); i++)
                list.add(nodes.item(i).getNodeValue());
        } catch (XPathExpressionException e) {
            e.printStackTrace();
        }
        
        return list;
    }

    private ArrayList<String> toUpperArray(ArrayList<String> input)
    {
        ArrayList<String> output = new ArrayList<String>();
        
        for (String value : input)
        {
            output.add(value.toUpperCase());
        }
        return output;
    }
    
    public ArrayList<String> getCommandLefts()
    {
        return getCommandsByType("commandLefts");
    }
    
    public ArrayList<String> getCommandMiddles()
    {
        return getCommandsByType("commandMiddles");
    }
    
    public ArrayList<String> getCommandMiddlesUpper()
    {
        return toUpperArray(getCommandsByType("commandMiddles"));
    }
    
    public ArrayList<String> getCommandParentlesses()
    {
        return getCommandsByType("commandParentlesses");
    }

    public ArrayList<String> getCommandLeftsUpper()
    {
        return toUpperArray(getCommandLefts());
    }
}
