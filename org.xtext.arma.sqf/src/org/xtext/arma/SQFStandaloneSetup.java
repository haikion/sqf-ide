/*
 * generated by Xtext
 */
package org.xtext.arma;

/**
 * Initialization support for running Xtext languages 
 * without equinox extension registry
 */
public class SQFStandaloneSetup extends SQFStandaloneSetupGenerated 
{

    public static void doSetup() {
    	new SQFStandaloneSetup().createInjectorAndDoEMFRegistration();
    }
}

