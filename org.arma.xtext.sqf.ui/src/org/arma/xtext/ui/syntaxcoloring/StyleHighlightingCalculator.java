package org.arma.xtext.ui.syntaxcoloring;

import org.eclipse.emf.ecore.EObject;
import org.eclipse.xtext.ide.editor.syntaxcoloring.IHighlightedPositionAcceptor;
import org.eclipse.xtext.ide.editor.syntaxcoloring.ISemanticHighlightingCalculator;
import org.eclipse.xtext.nodemodel.INode;
import org.eclipse.xtext.resource.XtextResource;
import org.eclipse.xtext.util.CancelIndicator;
import org.arma.xtext.KeywordHandler;
import org.arma.xtext.sqf.CommandLeft;
import org.arma.xtext.sqf.GlobalVariableReference;
import org.arma.xtext.sqf.LineMiddle;
import org.eclipse.xtext.ui.editor.hover.AbstractEObjectHover;

public class StyleHighlightingCalculator
        implements ISemanticHighlightingCalculator
{
    @Override
    public void provideHighlightingFor(XtextResource resource,
            IHighlightedPositionAcceptor acceptor, CancelIndicator arg2)
    {
        if (resource == null || resource.getParseResult() == null)
            return;

        //System.out.println("provideHighlightFor called: resource=" + resource
        //        + " acceptor=" + acceptor + "arg2=" + arg2);

        INode root = resource.getParseResult().getRootNode();
        for (INode node : root.getAsTreeIterable())
        {
            //Semantic Element of parameter is in some cases same as commandleft's. Hence check that
            //We are only working parent CommandLeft.
            EObject semanticElement = node.getSemanticElement();
            if (! (node.getParent() != null && 
                    node.getParent().getSemanticElement() instanceof CommandLeft)
                    && semanticElement instanceof CommandLeft)
            {
                CommandLeft cmd = (CommandLeft) semanticElement;
                if (cmd.getName() == null)
                {
                    return; //Happens when the word isn't complete
                }
                try 
                {
                    acceptor.addPosition(node.getOffset(), cmd.getName().getName().getName().length(),
                            DefaultHighlightingConfiguration.KEYWORD_ID);
                }
                catch (NullPointerException e)
                {
                }

            }
            
            if (semanticElement instanceof GlobalVariableReference)
            {
            	String name = ((GlobalVariableReference) semanticElement).getName().getName();
            	if (name != null && KeywordHandler.getKeywordsUpper().contains(name.toUpperCase()))
            	{
            		acceptor.addPosition(node.getOffset(), name.length(), DefaultHighlightingConfiguration.KEYWORD_ID);
            	}
            }
            
            //Middle Command
            else if (! (node.getParent() != null && 
                    node.getParent().getSemanticElement() instanceof LineMiddle)
                    && node.getSemanticElement() instanceof LineMiddle)
            {
                LineMiddle cmd = (LineMiddle) node.getSemanticElement();                
                //System.out.println("name=" + cmd.getName() + " offset="
                //        + node.getOffset());
                acceptor.addPosition(node.getOffset(), cmd.getName().length(),
                        DefaultHighlightingConfiguration.KEYWORD_ID);                
            }
        }
    }
}
