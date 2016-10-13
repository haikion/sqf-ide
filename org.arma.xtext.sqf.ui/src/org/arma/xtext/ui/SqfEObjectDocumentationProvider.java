/*
 * Defines documentation for each command or function.
 */

package org.arma.xtext.ui;

import org.arma.xtext.XmlReader;
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
        String name = "";
        if (o instanceof CommandLeft)
        {
            name = ((CommandLeft) o).getName().getName().getName();
        }
        else if (o instanceof LineMiddle)
        {
            name = ((LineMiddle) o).getName();
        }
        else if (o instanceof CommandParameterless)
        {
            name = ((CommandParameterless) o).getName();
        }
        else if (o instanceof GlobalFunction)
        {
            name = ((GlobalFunction) o).getName();
        }
        else if (o instanceof GlobalVariableReference)
        {
        	name = ((GlobalVariableReference) o).getName().getName();
        }
        System.out.println("callable = " + name);
        String doc = XmlReader.getCallableDoc(name);
        
        return doc;
    }
}
