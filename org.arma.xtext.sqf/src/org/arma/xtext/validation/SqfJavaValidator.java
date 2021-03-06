/*
 * SQF syntax validator. Check commands with parameters.
 * Parameterless commands are checked through grammar definitions.
 * FIXME: NullPointerException during Eclipse startup due to not being defined. Works never the less.
 * Could be due to not being injected early enough...
 */
package org.arma.xtext.validation;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

import org.arma.xtext.XmlReader;
import org.eclipse.xtext.validation.Check;
import org.arma.xtext.sqf.CommandLeft;
import org.arma.xtext.sqf.LineMiddle;
import org.arma.xtext.sqf.SqfPackage;;

/**
 * This class contains custom validation rules. 
 *
 * See https://www.eclipse.org/Xtext/documentation/303_runtime_concepts.html#validation
 */
public class SqfJavaValidator extends org.arma.xtext.validation.AbstractSqfJavaValidator
{
    HashSet<String> validMiddleCommands_ = new HashSet<String>();
    HashSet<String> validLeftCommands_ = new HashSet<String>();
    HashSet<String> validParentlessCommands_ = new HashSet<String>();

    
    SqfJavaValidator() 
    {
        populateValidCommands();
    }

    @Check
    public void checkMiddleName(LineMiddle line) 
    {
        if (!validMiddleCommands_.contains(line.getName().toUpperCase())) 
        {
            error("Invalid middle command.",
            		SqfPackage.Literals.LINE_MIDDLE__NAME);
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
        Set<String> validMiddles = XmlReader.getCommandMiddlesUpper();
        Set<String> validLefts = XmlReader.getCommandLeftsUpper();
        Set<String> validParentlesses = XmlReader.getCommandParentlessesUpper();
        
        validMiddleCommands_.addAll(validMiddles);
        validLeftCommands_.addAll(validLefts);
        validParentlessCommands_.addAll(validParentlesses);
        System.out.println("validMiddleCommands size: " + validMiddleCommands_.size() + 
                " validLeftCommands size: " + validLeftCommands_.size() + 
                " validParentlessCommands size: " + validParentlessCommands_.size());
    }
}
