package org.arma.xtext.linking;


import java.io.IOException;

import org.eclipse.emf.common.util.URI;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.emf.ecore.resource.Resource;
import org.eclipse.xtext.diagnostics.IDiagnosticConsumer;
import org.eclipse.xtext.linking.lazy.LazyLinker;

public class SqfLazyLinker extends LazyLinker
{
	@Override
	protected void beforeModelLinked(EObject model, IDiagnosticConsumer diagnosticsConsumer)
	{
	    super.beforeModelLinked(model, diagnosticsConsumer);
	    Resource res = model.eResource().getResourceSet().getResource(URI.createURI("dummy.projectionsatisfier"), false);
	    if (res != null) 
	    {
	        try {
	            res.delete(null);
	        } catch (IOException e) {}
	  }
	}
}
