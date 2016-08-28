/**
 * Implements auto completion
 */
package org.xtext.arma.ui.contentassist;

import java.io.File;
import java.util.Arrays;
import java.util.Collection;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;

import org.apache.commons.collections4.trie.PatriciaTrie;
import org.eclipse.core.resources.IProject;
import org.eclipse.core.resources.ProjectScope;
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.core.runtime.IAdaptable;
import org.eclipse.core.runtime.IPath;
import org.eclipse.core.runtime.Preferences;
import org.eclipse.core.runtime.preferences.IEclipsePreferences;
import org.eclipse.core.runtime.preferences.IScopeContext;
import org.eclipse.emf.common.util.EList;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.jface.text.TextSelection;
import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.ui.IEditorInput;
import org.eclipse.ui.IFileEditorInput;
import org.eclipse.ui.IWorkbenchWindow;
import org.eclipse.ui.PlatformUI;
import org.eclipse.ui.actions.GlobalBuildAction;
import org.eclipse.xtext.Assignment;
import org.eclipse.xtext.RuleCall;
import org.eclipse.xtext.nodemodel.util.NodeModelUtils;
import org.eclipse.xtext.ui.editor.contentassist.ContentAssistContext;
import org.eclipse.xtext.ui.editor.contentassist.ICompletionProposalAcceptor;
import org.osgi.service.prefs.BackingStoreException;
import org.xtext.arma.ui.contentassist.AbstractSQFProposalProvider;
import org.xtext.arma.XMLReader;
import org.xtext.arma.sQF.*;

/**
 * See https:www.eclipse.org/Xtext/documentation/304_ide_concepts.html#content-assist
 * on how to customize the content assistant.
 */
public class SQFJavaProposalProvider extends AbstractSQFProposalProvider 
{
	private final static String PREF_CONST = "functions";
	private final static String CUSTOM_FUNCTIONS_PATH = "/includes/customFunctions.xml";
	
    private PatriciaTrie<String> middles_;
    private PatriciaTrie<String> lefts_;
    private PatriciaTrie<String> functions_;
    
    SQFJavaProposalProvider()
    {
        super();
        System.out.println("SQFJavaProposalProvider: Constructing SQFProposalProvider.");
        lefts_ = setListToTrie(XMLReader.getCommandLefts());
        middles_ = setListToTrie(XMLReader.getCommandMiddles());
        functions_ = setListToTrie(XMLReader.getFunctions());
        System.out.println("functions_ size: " + functions_.size());
    }
    
    public IProject getCurrentProject()
    {
        IEditorInput input = PlatformUI.getWorkbench().getActiveWorkbenchWindow().getActivePage().getActiveEditor().getEditorInput();
        if (input instanceof IFileEditorInput)
        {
        	IFileEditorInput ifei = (IFileEditorInput) input;
        	return ifei.getFile().getProject();
        }
        return null;

    }
    
    private List<String> getMissionFunctions(IProject project)
    {    	
    	IScopeContext projectScope = new ProjectScope(project);
    	IEclipsePreferences prefs = projectScope.getNode(PREF_CONST);
    	try {
			prefs.sync();
		} catch (BackingStoreException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

    	System.out.println(prefs.get(PREF_CONST, "failure"));
    	String str = prefs.get(PREF_CONST, "[]");
    	if ( "[]".equals(str) )
    		return new LinkedList<String>();
    		
    	str = str.replace("[", "").replace("]", "");
    	if (!str.contains(","))
    	{
    		List<String> list = new LinkedList<String>();
    		list.add(str);
    		System.out.println(list.toString() + " " + str);
    		return list;
    	}
    		
    	List<String> missionFunctions = Arrays.asList(str.split(","));
    	System.out.println(missionFunctions.toString() + " size=" + missionFunctions.size());
    	return missionFunctions;
    }
    
    //Function completion
    @Override
    public void completeGlobalFunction_Name(EObject model, Assignment assignment, 
            ContentAssistContext context, ICompletionProposalAcceptor acceptor)
    {
        IProject project = getCurrentProject();
    	
    	System.out.println("SQFJavaProposalProvider: Proposing global function. "
                + "Model class = " + model.getClass().getName() + " project=" + project.getFullPath());
        if (!(model instanceof LineMiddle))
        {
            return;
        }

        Set<String> funcs = XMLReader.getFunctions(new File(project.getLocation().toOSString() + CUSTOM_FUNCTIONS_PATH));
    	List<String> missionFunctions = getMissionFunctions(project);
        funcs.addAll(missionFunctions);
        setToProposal(funcs, context, acceptor);
    };
    
    //Middle command auto completion
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
    
    //Left commands auto completion.
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
    
    private PatriciaTrie<String> setListToTrie(final Set<String> set)
    {
        PatriciaTrie<String> trie = new PatriciaTrie<String>();
        for (String value : set)
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
    
    private void setToProposal(Set<String> set, 
            ContentAssistContext context, ICompletionProposalAcceptor acceptor) 
    {
        for (String proposal : set)
        {
            acceptor.accept(createCompletionProposal(proposal, context));            
        }
    }
    
    private String getEObjectText(EObject eobject)
    {
        return NodeModelUtils.getTokenText(NodeModelUtils.getNode(eobject));
    }
}