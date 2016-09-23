/*
 * @Author Niko Häikiö
 * Defines documentation for each command or function.
 * TODO: Rename command to callable
 */
package org.arma.xtext.ui;

import org.arma.xtext.XMLReader;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.xtext.documentation.IEObjectDocumentationProvider;
import org.arma.xtext.sqf.CommandLeft;
import org.arma.xtext.sqf.CommandParameterless;
import org.arma.xtext.sqf.GlobalFunction;
import org.arma.xtext.sqf.LineMiddle;

public class SQFEObjectDocumentationProvider implements IEObjectDocumentationProvider
{
    @Override
    public String getDocumentation(EObject o)
    {
        String command = "";
        if (o instanceof CommandLeft)
        {
            command = ((CommandLeft) o).getName();
        }
        else if (o instanceof LineMiddle)
        {
            command = ((LineMiddle) o).getName();
        }
        else if (o instanceof CommandParameterless)
        {
            command = ((CommandParameterless) o).getName();
        }
        else if (o instanceof GlobalFunction)
        {
            command = ((GlobalFunction) o).getName();
        }
        String doc = XMLReader.getCommandDoc(command);
        
        return doc;
    }
}
