/*
 * generated by Xtext
 */
package org.xtext.arma;

import org.eclipse.xtext.scoping.IGlobalScopeProvider;

/**
 * Use this class to register components to be used at runtime / without the Equinox extension registry.
 */
public class SQFRuntimeModule extends org.xtext.arma.AbstractSQFRuntimeModule
{
    @Override
    public Class<? extends org.eclipse.xtext.scoping.IScopeProvider> bindIScopeProvider() {
        return org.xtext.arma.scoping.SQFJavaScopeProvider.class;
    }
}
