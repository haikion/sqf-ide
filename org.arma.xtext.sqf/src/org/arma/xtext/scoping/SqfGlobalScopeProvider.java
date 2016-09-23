package org.arma.xtext.scoping;

import org.eclipse.emf.ecore.EReference;
import org.arma.xtext.sqf.GlobalVariableReference;
import org.eclipse.emf.ecore.resource.Resource;
import org.eclipse.xtext.scoping.impl.DefaultGlobalScopeProvider;
import org.eclipse.xtext.resource.IEObjectDescription;
import org.eclipse.xtext.scoping.IScope;

import com.google.common.base.Predicate;

@SuppressWarnings("restriction")
public class SqfGlobalScopeProvider extends DefaultGlobalScopeProvider
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