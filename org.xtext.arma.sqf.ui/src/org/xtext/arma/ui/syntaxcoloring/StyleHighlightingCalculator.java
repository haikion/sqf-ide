package org.xtext.arma.ui.syntaxcoloring;

import org.eclipse.xtext.ide.editor.syntaxcoloring.IHighlightedPositionAcceptor;
import org.eclipse.xtext.ide.editor.syntaxcoloring.ISemanticHighlightingCalculator;
import org.eclipse.xtext.nodemodel.INode;
import org.eclipse.xtext.resource.XtextResource;
import org.eclipse.xtext.util.CancelIndicator;
import org.xtext.arma.sQF.CommandLeft;
import org.xtext.arma.sQF.LineMiddle;
import org.xtext.arma.sQF.LocalVariableDefinition;
import org.xtext.arma.sQF.LocalVariableReference;

@SuppressWarnings("restriction")
public class StyleHighlightingCalculator
        implements ISemanticHighlightingCalculator
{
    @Override
    public void provideHighlightingFor(XtextResource resource,
            IHighlightedPositionAcceptor acceptor, CancelIndicator arg2)
    {
        if (resource == null || resource.getParseResult() == null)
            return;

        System.out.println("provideHighlightFor called: resource=" + resource
                + " acceptor=" + acceptor + "arg2=" + arg2);

        INode root = resource.getParseResult().getRootNode();
        for (INode node : root.getAsTreeIterable())
        {
            //Semantic Element of parameter is in some cases same as commandleft's. Hence check that
            //We are only working parent CommandLeft.
            if (! (node.getParent() != null && 
                    node.getParent().getSemanticElement() instanceof CommandLeft)
                    && node.getSemanticElement() instanceof CommandLeft)
            {
                // for (ILeafNode nameNode : node.getLeafNodes())
                // {
                // System.out.println("nameNode=" + nameNode.getText());
                // }
                // FIXME: Happens 3 times per commandleft... pls halp :|
                CommandLeft cmd = (CommandLeft) node.getSemanticElement();
                acceptor.addPosition(node.getOffset(), cmd.getName().length(),
                        DefaultHighlightingConfiguration.KEYWORD_ID);
            }
            //Middle Command
            else if (! (node.getParent() != null && 
                    node.getParent().getSemanticElement() instanceof LineMiddle)
                    && node.getSemanticElement() instanceof LineMiddle)
            {
                LineMiddle cmd = (LineMiddle) node.getSemanticElement();                
                System.out.println("name=" + cmd.getName() + " offset="
                        + node.getOffset());
                acceptor.addPosition(node.getOffset(), cmd.getName().length(),
                        DefaultHighlightingConfiguration.KEYWORD_ID);                
            }
        }
    }
}
