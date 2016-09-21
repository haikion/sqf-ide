package org.arma.xtext.scoping;

import org.eclipse.emf.ecore.EReference;
import org.arma.xtext.sQF.GlobalVariableReference;
import org.eclipse.emf.ecore.resource.Resource;
import org.eclipse.xtext.common.types.xtext.TypesAwareDefaultGlobalScopeProvider;
import org.eclipse.xtext.resource.IEObjectDescription;
import org.eclipse.xtext.scoping.IScope;

import com.google.common.base.Predicate;

@SuppressWarnings("restriction")
public class SqfGlobalScopeProvider  extends TypesAwareDefaultGlobalScopeProvider
{
    @Override
    public IScope getScope(Resource context, EReference reference,
            Predicate<IEObjectDescription> filter) 
    {
        if (reference.getContainerClass() == GlobalVariableReference.class)
            return super.getScope(context, reference, filter);
        
        return IScope.NULLSCOPE;
    }
}