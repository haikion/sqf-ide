/*
 * In SQF global variable references are (in some cases) syntactically identical to command calls.
 * This class avoids such problem by by-passing references that are in fact commands.
 */
package org.arma.xtext.linking;

import java.util.Collections;
import java.util.List;
import java.util.Set;

import org.arma.xtext.KeywordHandler;
import org.arma.xtext.config.Variable;
import org.arma.xtext.config.impl.ConfigFactoryImpl;
import org.eclipse.emf.common.util.URI;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.emf.ecore.EReference;
import org.eclipse.emf.ecore.resource.Resource;
import org.eclipse.xtext.linking.impl.DefaultLinkingService;
import org.eclipse.xtext.linking.impl.IllegalNodeException;
import org.eclipse.xtext.nodemodel.INode;

public class SqfLinkingService extends DefaultLinkingService
{	
	@Override
    public List<EObject> getLinkedObjects(EObject context, EReference ref, INode node) throws IllegalNodeException
    {
		//Check if keyword is being cross referenced.

		final String crossRefString = getCrossRefNodeAsString(node);	
		if (KeywordHandler.getKeywordsUpper().contains(crossRefString.toUpperCase()))
		{
			//If reference is keyword, ignore it and provide dummy target in order to avoid errors.
            Variable newVariable = ConfigFactoryImpl.eINSTANCE.createVariable();
            newVariable.setName(crossRefString);

            URI uri = URI.createURI("dummy.projectionsatisfier");
            Resource r = context.eResource().getResourceSet().getResource(uri, false);
            if (r == null)
            {
                r = context.eResource().getResourceSet().createResource(uri);
            }
            r.getContents().add(newVariable);
            
            List<EObject> list = Collections.singletonList((EObject)newVariable);
            return list;
		}
		//Not keyword, has to be real reference.
		return super.getLinkedObjects(context, ref, node);
    }
}
