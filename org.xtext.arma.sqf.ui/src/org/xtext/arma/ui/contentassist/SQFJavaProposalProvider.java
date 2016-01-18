/**
 * @Author Niko Häikiö
 * Implements auto completion
 */
package org.xtext.arma.ui.contentassist;

import java.util.ArrayList;
import java.util.Collection;
import org.apache.commons.collections4.trie.PatriciaTrie;
import org.eclipse.emf.common.util.EList;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.xtext.Assignment;
import org.eclipse.xtext.RuleCall;
import org.eclipse.xtext.ui.editor.contentassist.ContentAssistContext;
import org.eclipse.xtext.ui.editor.contentassist.ICompletionProposalAcceptor;
import org.xtext.arma.ui.contentassist.AbstractSQFProposalProvider;
import org.xtext.arma.XMLReader;
import org.xtext.arma.sQF.*;

/**
 * See https:www.eclipse.org/Xtext/documentation/304_ide_concepts.html#content-assist
 * on how to customize the content assistant.
 */
public class SQFJavaProposalProvider extends AbstractSQFProposalProvider 
{
    private PatriciaTrie<String> middles_ = new PatriciaTrie<String>();
    private PatriciaTrie<String> lefts_ = new PatriciaTrie<String>();
    
    SQFJavaProposalProvider()
    {
        super();
        populateValidCommands();
        System.out.println("SQFJavaProposalProvider: Constructing SQFProposalProvider.");
    }
    
    //Reads XML file and populates tries
    private void populateValidCommands()
    {
        XMLReader xmlReader = new XMLReader();
        ArrayList<String> proposalMiddles = xmlReader.getCommandMiddles();
        ArrayList<String> keyMiddles = xmlReader.getCommandMiddlesUpper();
        for (int i = 0; i < keyMiddles.size(); ++i)
        {
            middles_.put(keyMiddles.get(i), proposalMiddles.get(i));
        }
        ArrayList<String> proposalLefts = xmlReader.getCommandLefts();
        ArrayList<String> keyLefts = xmlReader.getCommandLeftsUpper();
        for (int i = 0; i < keyLefts.size(); ++i)
        {
            lefts_.put(keyLefts.get(i), proposalLefts.get(i));
        }
        
    }
    
    //Auto completion for middle commands
    @Override
    public void completeLineMiddle_Name(EObject model, Assignment assignment, ContentAssistContext context, 
            ICompletionProposalAcceptor acceptor)
    {
        System.out.println("SQFJavaProposalProvider: Proposing line middle...");
        if (!(model instanceof AssignableLineOfCode))
        {
            return;
        }
        AssignableLineOfCode lineMiddle = (AssignableLineOfCode) model;
        EList<EObject> middles = lineMiddle.getMiddles();
        if (middles.size() == 0)
        {
            return;
        }
        EObject currentMiddle = middles.get(middles.size() -1);
        if (! (currentMiddle instanceof LineMiddle))
        {
            return;
        }
        LineMiddle middle = (LineMiddle) currentMiddle;
        String query = middle.getName().toUpperCase();
        System.out.println("SQFJavaProposalProvider: Proposing line middle...query=" + query);
        Collection<String> result = middles_.prefixMap(query).values();
        for (String proposal : result)
        {
            acceptor.accept(createCompletionProposal(proposal, context));            
        }
    }

    public void complete_LocalVariableDefinition(EObject model, RuleCall ruleCall, ContentAssistContext context, 
            ICompletionProposalAcceptor acceptor) 
    {
        System.out.println("SQFJavaProposalProvider: LocalVaribaleDeifnition called. "
                + "It is: " + model.getClass().getName());    
    }
    
    public void complete_GlobalVariableDefinition(EObject model, RuleCall ruleCall,
            ContentAssistContext context, ICompletionProposalAcceptor acceptor) 
    {
        if (!(model instanceof GlobalVariableDefinition))
        {
            return;
        }
        AssignableLineOfCode lineOfCode = (AssignableLineOfCode) model;
        VariableValue value = lineOfCode.getFrontParameter();
        if (!(value instanceof CommandLeft))
        {
            System.out.println("SQFJavaProposalProvider: value is not CommandLeft. "
                    + "It is: " + value.getClass().getName());
            return;
        }
        CommandLeft commandLeft = (CommandLeft) value;
        if (commandLeft.getName() == null)
        {
            System.out.println("SQFJavaProposalProvider: name=null");
            System.out.println("SQFJavaProposalProvider: Var=" + commandLeft.getVar().getName());
            System.out.println("SQFJavaProposalProvider: Parameter=" + commandLeft.getParameter());
            return;
        }
        String query = commandLeft.getName().toUpperCase();
        System.out.println("SQFJavaProposalProvider: Proposing command left...query=" + query);
        Collection<String> result = lefts_.prefixMap(query).values();
        for (String proposal : result)
        {
            acceptor.accept(createCompletionProposal(proposal, context));
        }
    }
    
    //FIXME: No way to get typed text...
    //At the moment this function only contains attempts to extract typed text.
    @Override
    public void complete_CommandLeft(EObject model, RuleCall ruleCall, 
            ContentAssistContext context, ICompletionProposalAcceptor acceptor) 
    {
        System.out.println("SQFJavaProposalProvider: Proposing commandLeft...");
        if (model instanceof Model)
        {
            Model mo = (Model) model;
            System.out.println("SQFJavaProposalProvider: Line class: " + mo.getLines().get(0).getClass().getName());
            System.out.println("SQFJavaProposalProvider: Model is not GlobalVariableDefinition. "
                    + "It is: " + model.getClass().getName());
        }
        if (!(model instanceof AssignableLineOfCode))
        {
            System.out.println("SQFJavaProposalProvider: Model is not AssignableLineOfCodeImpl. "
                    + "It is: " + model.getClass().getName());
            return;
        }
        AssignableLineOfCode lineOfCode = (AssignableLineOfCode) model;
        VariableValue value = lineOfCode.getFrontParameter();
        if (!(value instanceof CommandLeft))
        {
            System.out.println("SQFJavaProposalProvider: value is not CommandLeft. "
                    + "It is: " + value.getClass().getName());
            return;
        }
        CommandLeft commandLeft = (CommandLeft) value;
        if (commandLeft.getName() == null)
        {
            System.out.println("SQFJavaProposalProvider: name=null");
            System.out.println("SQFJavaProposalProvider: Var=" + commandLeft.getVar().getName());
            System.out.println("SQFJavaProposalProvider: Parameter=" + commandLeft.getParameter());
            return;
        }
        String query = commandLeft.getName().toUpperCase();
        System.out.println("SQFJavaProposalProvider: Proposing command left...query=" + query);
        Collection<String> result = lefts_.prefixMap(query).values();
        for (String proposal : result)
        {
            acceptor.accept(createCompletionProposal(proposal, context));
        }
    }
}
