/*
 * generated by Xtext
 */
package org.xtext.arma.ui;

import org.eclipse.ui.plugin.AbstractUIPlugin;
import org.eclipse.xtext.ide.editor.syntaxcoloring.ISemanticHighlightingCalculator;
import org.eclipse.xtext.ui.editor.syntaxcoloring.AbstractAntlrTokenToAttributeIdMapper;
import org.eclipse.xtext.ui.editor.syntaxcoloring.IHighlightingConfiguration;
import org.xtext.arma.ui.syntaxcoloring.DefaultHighlightingConfiguration;
import org.xtext.arma.ui.syntaxcoloring.StyleHighlightingCalculator;
import org.xtext.arma.ui.syntaxcoloring.StyleTokenToAttributeIdMapper;

/**
 * Use this class to register components to be used within the IDE.
 */
public class SQFUiModule extends org.xtext.arma.ui.AbstractSQFUiModule 
{
	public SQFUiModule(AbstractUIPlugin plugin) 
	{
		super(plugin);
	}
	
	public Class<? extends IHighlightingConfiguration> bindIHighlightingConfiguration () 
	{
	     return DefaultHighlightingConfiguration.class;
	}
	
	public Class<? extends AbstractAntlrTokenToAttributeIdMapper> bindAbstractAntlrTokenToAttributeIdMapper()
	{
	    return StyleTokenToAttributeIdMapper.class;
	}
	
    public Class<? extends ISemanticHighlightingCalculator> bindISemanticHighlightingCalculator()
	{
	    return StyleHighlightingCalculator.class;
	}
	
	// contributed by org.eclipse.xtext.ui.generator.contentAssist.ContentAssistFragment
    @Override
	public Class<? extends org.eclipse.xtext.ui.editor.contentassist.IContentProposalProvider> bindIContentProposalProvider() {
        return org.xtext.arma.ui.contentassist.SQFJavaProposalProvider.class;
    }

}
