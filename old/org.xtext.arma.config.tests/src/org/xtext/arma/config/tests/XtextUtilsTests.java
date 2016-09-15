package org.xtext.arma.config.tests;

import org.eclipse.xtext.junit4.InjectWith;
import org.eclipselabs.xtext.utils.unittesting.XtextRunner2;
import org.eclipselabs.xtext.utils.unittesting.XtextTest;
import org.xtext.arma.ConfigInjectorProvider;
import org.junit.Test;
import org.junit.runner.RunWith;

@RunWith(XtextRunner2.class)
@InjectWith(ConfigInjectorProvider.class)
public class XtextUtilsTests extends XtextTest
{
    public XtextUtilsTests()
    {
        super("ConfigFiles");
    }
    
    @Test
    public void emptyClass() {
        testParserRule("class test {}", "Class");
    }
    
    @Test
    public void classInsideClass() {
        testParserRule("class test {"
                + "    class test2 {};"
                + "}", "Class");
    }
    
    @Test
    public void classWithParameter() {
        testParserRule("class test {"
                + "tag = \"life\";"
                + "}", "Class");
    }
    
    @Test
    public void simpleString() {
        testParserRule("\"Hello\"", "String");
    }
    
    @Test
    public void slashString() {
        testParserRule("\"hello/ok\"", "String");
    }
}
