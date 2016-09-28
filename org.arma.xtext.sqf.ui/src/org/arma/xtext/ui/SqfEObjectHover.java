package org.arma.xtext.ui;

import org.arma.xtext.KeywordHandler;
import org.arma.xtext.config.Variable;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.jface.text.IRegion;
import org.eclipse.jface.text.ITextViewer;
import org.eclipse.jface.text.Region;
import org.eclipse.xtext.nodemodel.ILeafNode;
import org.eclipse.xtext.nodemodel.util.NodeModelUtils;
import org.eclipse.xtext.parser.IParseResult;
import org.eclipse.xtext.resource.EObjectAtOffsetHelper;
import org.eclipse.xtext.resource.ILocationInFileProvider;
import org.eclipse.xtext.resource.XtextResource;
import org.eclipse.xtext.ui.editor.hover.DispatchingEObjectTextHover;
import org.eclipse.xtext.util.Pair;
import org.eclipse.xtext.util.Tuples;

import com.google.inject.Inject;

public class SqfEObjectHover extends DispatchingEObjectTextHover
{
	@Inject
	private EObjectAtOffsetHelper eObjectAtOffsetHelper;

	@Inject
	private ILocationInFileProvider locationInFileProvider;
	
	@Override
	protected Pair<EObject, IRegion> getXtextElementAt(XtextResource resource, int offset)
	{
		EObject o = eObjectAtOffsetHelper.resolveElementAt(resource, offset);
		if (o instanceof Variable)
		{
			Variable var = (Variable) o;
			String name = var.getName();
			System.out.println(name);
			if (KeywordHandler.getKeywordsUpper().contains(name.toUpperCase()))
			{
				EObject o2 = internalResolveElementAt(resource, offset);
				
				final IRegion region2 = new Region(offset-1, name.length());
				System.out.println("Return " + region2.getOffset() + " " + region2.getLength());
				return Tuples.create(o2, region2);
			}
			
		}
		// TODO Auto-generated method stub
		return super.getXtextElementAt(resource, offset);
	}
	
	protected EObject internalResolveElementAt(XtextResource resource, int offset)
	{
		IParseResult parseResult = resource.getParseResult();
		if (parseResult != null) {
			ILeafNode leaf = NodeModelUtils.findLeafNodeAtOffset(parseResult.getRootNode(), offset);
			if (leaf != null && leaf.isHidden() && leaf.getOffset() == offset) {
				leaf = NodeModelUtils.findLeafNodeAtOffset(parseResult.getRootNode(), offset - 1);
			}
			if (leaf != null) {
				return NodeModelUtils.findActualSemanticObjectFor(leaf);
			}
		}
		return null;
	}
	
	@Override
	public Object getHoverInfo(EObject first, ITextViewer textViewer, IRegion hoverRegion)
	{
		if (first instanceof Variable)
		{
			Variable var = (Variable) first;
			String name = var.getName();
			if ("preprocessFileLineNumbers".equals(name))
			{
				//return lastCreatorProvider.getInfo();
			}				
		}
		return super.getHoverInfo(first, textViewer, hoverRegion);
	}
	
	
}
