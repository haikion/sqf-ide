/*
 * @Author Niko Häikiö
 * SQF syntax validator. Check commands with parameters.
 * Parameterless commands are check the grammar level.
 */
package org.xtext.arma.validation;

import java.util.ArrayList;
import java.util.HashSet;

import org.eclipse.xtext.validation.Check;
import org.xtext.arma.sQF.CommandLeft;
import org.xtext.arma.sQF.LineMiddle;
import org.xtext.arma.sQF.SQFPackage;

/**
 * This class contains custom validation rules. 
 *
 * See https://www.eclipse.org/Xtext/documentation/303_runtime_concepts.html#validation
 */
public class SQFJavaValidator extends org.xtext.arma.validation.AbstractSQFJavaValidator {
    final String XML_FILE_PATH = "/home/niko/test.xml";
    //HashSet<String> validCommands_ = new HashSet<String>();
    HashSet<String> validMiddleCommands_ = new HashSet<String>();
    HashSet<String> validLeftCommands_ = new HashSet<String>();
    HashSet<String> validParentlessCommands_ = new HashSet<String>();

    
    SQFJavaValidator() 
    {
        populateValidCommands();
    }

    @Check
    public void checkLeftName(CommandLeft command) 
    {
        if (!validLeftCommands_.contains(command.getName().toUpperCase())) 
        {
            error("Invalid left command.", 
                    SQFPackage.Literals.COMMAND_LEFT__NAME);
        }
    }
    
    @Check
    public void checMiddleName(LineMiddle line) 
    {
        if (!validMiddleCommands_.contains(line.getName().toUpperCase())) 
        {
            error("Invalid middle command.",
                    SQFPackage.Literals.LINE_MIDDLE__NAME);
        }
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
    
    private void populateValidCommands()
    {
        //FIXME: Something gets lost. Only Around 900 commands instead 
        //of 1700
        XMLReader xmlReader = new XMLReader(XML_FILE_PATH);
        ArrayList<String> validMiddles = xmlReader.getCommandMiddles();
        ArrayList<String> validLefts = xmlReader.getCommandLefts();
        ArrayList<String> validParentlesses = xmlReader.getCommandParentlesses();
        validMiddles = toUpperArray(validMiddles);
        validLefts = toUpperArray(validLefts);
        validParentlesses = toUpperArray(validParentlesses);
        
        validMiddleCommands_.addAll(validMiddles);
        validLeftCommands_.addAll(validLefts);
        validParentlessCommands_.addAll(validParentlesses);
        System.out.println("validMiddleCommands size: " + validMiddleCommands_.size() + 
                " validLeftCommands size: " + validLeftCommands_.size() + 
                " validParentlessCommands size: " + validParentlessCommands_.size());
    }
}
