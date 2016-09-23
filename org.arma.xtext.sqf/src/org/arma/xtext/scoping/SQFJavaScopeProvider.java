/**
 * generated by Xtext
 */
package org.arma.xtext.scoping;

import org.eclipse.emf.common.util.ECollections;
import org.eclipse.emf.common.util.EList;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.emf.ecore.EReference;
import org.eclipse.xtext.scoping.IScope;
import org.eclipse.xtext.scoping.Scopes;
import org.eclipse.xtext.scoping.impl.AbstractDeclarativeScopeProvider;
import org.arma.xtext.sqf.LocalVariableReference;

/**
 * This class contains custom scoping description.
 * 
 * See https://www.eclipse.org/Xtext/documentation/303_runtime_concepts.html#scoping
 * on how and when to use it.
 */
public class SQFJavaScopeProvider extends AbstractDeclarativeScopeProvider
{
    public IScope scope_LocalVariableReference_name(final LocalVariableReference ref, 
            final EReference eReference) 
    {
    	//Search for top model.
    	EObject container = ref;
    	while (container.eContainer() != null)
    	{
    		container = container.eContainer();
    	}
    	//Return top model in EList
        EList<EObject> lines = ECollections.emptyEList();
        lines.add(container);
        return Scopes.scopeFor(lines);
    }
}
