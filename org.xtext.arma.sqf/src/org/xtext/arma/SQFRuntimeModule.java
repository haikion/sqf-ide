/*
 * generated by Xtext
 */
package org.xtext.arma;
import org.eclipse.xtext.scoping.IGlobalScopeProvider;
import org.xtext.arma.scoping.NullGlobalScopeProvider;
import org.xtext.arma.scoping.SQFJavaScopeProvider;

/**
 * Use this class to register components to be used at runtime / without the Equinox extension registry.
 */
public class SQFRuntimeModule extends org.xtext.arma.AbstractSQFRuntimeModule
{
    @Override
    public Class<? extends org.eclipse.xtext.scoping.IScopeProvider> bindIScopeProvider()
    {
        return SQFJavaScopeProvider.class;
    }
    
    @Override
    public Class<? extends IGlobalScopeProvider> bindIGlobalScopeProvider()
    {
        return NullGlobalScopeProvider.class;
    }
}
