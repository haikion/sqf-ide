/*
 * @Author Niko Häikiö
 * Defines documentation for each command or function.
 * TODO: Rename command to callable
 */
package org.xtext.arma.ui;

import org.eclipse.emf.ecore.EObject;
import org.eclipse.xtext.documentation.IEObjectDocumentationProvider;
import org.xtext.arma.XMLReader;
import org.xtext.arma.sQF.CommandLeft;
import org.xtext.arma.sQF.CommandParameterless;
import org.xtext.arma.sQF.GlobalFunction;
import org.xtext.arma.sQF.LineMiddle;

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
