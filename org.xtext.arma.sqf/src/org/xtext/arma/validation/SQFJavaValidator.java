/*
 * @Author Niko Häikiö
 * SQF syntax validator. Check commands with parameters.
 * Parameterless commands are checked through grammar definitions.
 * FIXME: NullPointerException during Eclipse startup due to not being defined. Works never the less.
 * Could be due to not being injected early enough...
 */
package org.xtext.arma.validation;

import java.util.ArrayList;
import java.util.HashSet;

import org.eclipse.emf.common.util.EList;
import org.eclipse.emf.ecore.resource.Resource.Diagnostic;
import org.eclipse.xtext.validation.Check;
import org.xtext.arma.sQF.CommandLeft;
import org.xtext.arma.sQF.GlobalVariableReference;
import org.xtext.arma.sQF.LineMiddle;
import org.xtext.arma.sQF.SQFPackage;
import org.xtext.arma.XMLReader;

/**
 * This class contains custom validation rules. 
 *
 * See https://www.eclipse.org/Xtext/documentation/303_runtime_concepts.html#validation
 */
public class SQFJavaValidator extends org.xtext.arma.validation.AbstractSQFJavaValidator
{
    HashSet<String> validMiddleCommands_ = new HashSet<String>();
    HashSet<String> validLeftCommands_ = new HashSet<String>();
    HashSet<String> validParentlessCommands_ = new HashSet<String>();

    
    SQFJavaValidator() 
    {
        populateValidCommands();
    }

    @Check
    public void checkGlobalVariableReference(GlobalVariableReference object)
    {
        System.out.println("Executing GlobalVarCheck");
        EList<Diagnostic> errors = object.eResource().getErrors();
        for (Diagnostic error : errors)
        {
            System.out.println("Error: " + error.getMessage());
        }
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
    public void checkMiddleName(LineMiddle line) 
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
        ArrayList<String> validMiddles = XMLReader.getCommandMiddles();
        ArrayList<String> validLefts = XMLReader.getCommandLefts();
        ArrayList<String> validParentlesses = XMLReader.getCommandParentlesses();
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
