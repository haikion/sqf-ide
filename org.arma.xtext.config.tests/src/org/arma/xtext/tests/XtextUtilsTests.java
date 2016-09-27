/**
 * generated by Xtext 2.10.0
 */
package org.arma.xtext.tests;

import com.google.inject.Inject;

import org.arma.xtext.config.Model;
import org.arma.xtext.tests.ConfigInjectorProvider;
import org.eclipse.xtend2.lib.StringConcatenation;
import org.eclipse.xtext.junit4.InjectWith;
import org.eclipse.xtext.junit4.XtextRunner;
import org.eclipse.xtext.junit4.util.ParseHelper;
import org.eclipse.xtext.xbase.lib.Exceptions;
import org.junit.Assert;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.eclipselabs.xtext.utils.unittesting.XtextRunner2;
import org.eclipselabs.xtext.utils.unittesting.XtextTest;


@RunWith(XtextRunner2.class)
@InjectWith(ConfigInjectorProvider.class)
@SuppressWarnings("all")
public class XtextUtilsTests extends XtextTest
{
    public XtextUtilsTests()
    {
        super("sqfFiles");
    }
    
    @Test
    public void emptyClass()
    {
        testParserRule("class ok{}", "Class");
    }
    
    @Test
    public void parameterInt()
    {
    	testParserRule("ok = 1", "ParameterDefinition");
    }
    
    @Test
    public void parameterFloat()
    {
    	testParserRule("ok = 1.0", "ParameterDefinition");
    }
    
    @Test
    public void parameterString()
    {
    	testParserRule("ok = \"ok\"", "ParameterDefinition");
    }
    
    @Test
    public void arrayName()
    {
    	testTerminal("ok[]", "ARRAY_NAME");
    }
    
    @Test
    public void arrayDefinition()
    {
    	testParserRule("ok[] = {1,2,3}", "ArrayDefinition");
    }
    
    @Test
    public void expFloat()
    {
    	testTerminal("3.8146973e-006", "FLOAT");
    }
    
    @Test
    public void expFloatPos()
    {
    	testTerminal("8.4581253e+034", "FLOAT");
    }
    
    @Test
    public void include()
    {
    	testParserRule("#include \"include\\defines.hpp\"", "Include");
    }
    
    @Test
    public void hex()
    {
    	testTerminal("0x20", "HEX");
    }
    
    @Test
    public void unrecstr()
    {
    	testTerminal("x", "UNRECOGNIZED_STRING");
    }
    
    @Test
    public void gameVar()
    {
    	testParserRule("coop", "GameVar");
    }
    
    @Test
    public void gameVarCapital()
    {
    	testParserRule("Coop", "GameVar");
    }
}
