package org.arma.xtext.ui;

import org.arma.xtext.KeywordHandler;
import org.arma.xtext.sqf.GlobalVariableReference;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.xtext.ui.editor.hover.html.DefaultEObjectHoverProvider;

public class SqfEObjectHoverProvider extends DefaultEObjectHoverProvider
{
	//Bypasses the check for keyword tooltips
	@Override
	protected boolean hasHover(EObject o)
	{
		if (o instanceof GlobalVariableReference)
		{
			GlobalVariableReference ref = (GlobalVariableReference) o;
			String name = ref.getName().getName();
			if (KeywordHandler.getKeywordsUpper().contains(name.toUpperCase()))
			{
				return true;
			}
		}
		return super.hasHover(o);
	}
}
