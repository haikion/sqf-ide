/*
 * Defines documentation for each command or function.
 */

package org.arma.xtext.ui;

import org.arma.xtext.XMLReader;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.xtext.documentation.IEObjectDocumentationProvider;
import org.arma.xtext.sqf.CommandLeft;
import org.arma.xtext.sqf.CommandParameterless;
import org.arma.xtext.sqf.GlobalFunction;
import org.arma.xtext.sqf.GlobalVariableReference;
import org.arma.xtext.sqf.LineMiddle;

public class SqfEObjectDocumentationProvider implements IEObjectDocumentationProvider
{
    @Override
    public String getDocumentation(EObject o)
    {
        String callable = "";
        if (o instanceof CommandLeft)
        {
            callable = ((CommandLeft) o).getName().getName().getName();
        }
        else if (o instanceof LineMiddle)
        {
            callable = ((LineMiddle) o).getName();
        }
        else if (o instanceof CommandParameterless)
        {
            callable = ((CommandParameterless) o).getName();
        }
        else if (o instanceof GlobalFunction)
        {
            callable = ((GlobalFunction) o).getName();
        }
        else if (o instanceof GlobalVariableReference)
        {
        	callable = ((GlobalVariableReference) o).getName().getName();
        }
        System.out.println("callable = " + callable);
        String doc = XMLReader.getCommandDoc(callable);
        
        return doc;
    }
}
