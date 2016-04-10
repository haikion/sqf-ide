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
import org.eclipse.xtext.nodemodel.util.NodeModelUtils;
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
    private PatriciaTrie<String> middles_ = null;
    private PatriciaTrie<String> lefts_ = null;
    
    SQFJavaProposalProvider()
    {
        super();
        System.out.println("SQFJavaProposalProvider: Constructing SQFProposalProvider.");
        lefts_ = arrayListToTrie(XMLReader.getCommandLefts());
        middles_ = arrayListToTrie(XMLReader.getCommandMiddles());
    }
    
    //Auto completion for middle commands
    @Override
    public void completeLineMiddle_Name(EObject model, Assignment assignment, ContentAssistContext context, 
            ICompletionProposalAcceptor acceptor)
    {        
        System.out.println("SQFJavaProposalProvider: Proposing line middle... "
                + "Model class = " + model.getClass().getName());
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
        EObject currentMiddle = middles.get(middles.size() - 1);
        if (!(currentMiddle instanceof LineMiddle))
        {
            return;
        }
        LineMiddle middle = (LineMiddle) currentMiddle;
        trieToProposal(middle.getName(), middles_, context, acceptor);
    }
    
    //Implements left commands auto completion.
    @Override 
    public void complete_CommandLeft(EObject model, RuleCall ruleCall, 
            ContentAssistContext context, ICompletionProposalAcceptor acceptor) 
    {
        System.out.println("CommandLeft: model=" + model);
        if (!(model instanceof Model))
        {
            //Only model EObject provides correct context
            return;
        }
        Model mdl = (Model) model;
        LineOfCode lastLine = mdl.getLines().get(mdl.getLines().size() - 1);
        String query = getEObjectText(lastLine);
        trieToProposal(query, lefts_, context, acceptor);
    }
    
    private PatriciaTrie<String> arrayListToTrie(final ArrayList<String> arrayList)
    {
        PatriciaTrie<String> trie = new PatriciaTrie<String>();
        for (String value : arrayList)
        {
            trie.put(value.toUpperCase(), value);
        }
        return trie;
    }
    
    private void trieToProposal(String query, PatriciaTrie<String> trie, 
            ContentAssistContext context, ICompletionProposalAcceptor acceptor) 
    {
        query = query.toUpperCase();
        Collection<String> result = trie.prefixMap(query).values();
        for (String proposal : result)
        {
            acceptor.accept(createCompletionProposal(proposal, context));            
        }
    }
    
    private String getEObjectText(EObject eobject)
    {
        return NodeModelUtils.getTokenText(NodeModelUtils.getNode(eobject));
    }
}