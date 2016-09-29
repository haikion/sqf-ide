package org.arma.xtext;

import org.arma.xtext.config.Variable;
import org.eclipse.xtext.naming.QualifiedName;
import org.eclipse.xtext.naming.SimpleNameProvider;

public class ConfigQualifiedNameProvider extends SimpleNameProvider
{
	QualifiedName qualifiedName(Variable var)
	{
		return QualifiedName.create(var.getName());
	}
}
