//TODO: Terminal testing (lexer)
package org.xtext.arma.sqf.tests;

import com.google.inject.Inject;
import com.google.inject.Injector;
import java.util.List;
import org.antlr.runtime.ANTLRStringStream;
import org.antlr.runtime.CharStream;
import org.antlr.runtime.Token;
import org.eclipse.xtext.junit4.AbstractXtextTests;
import org.eclipse.xtext.junit4.InjectWith;
import org.eclipse.xtext.junit4.XtextRunner;
import org.eclipse.xtext.junit4.util.ParseHelper;
import org.eclipse.xtext.junit4.validation.ValidatorTester;
import org.eclipse.xtext.parser.antlr.Lexer;
import org.eclipse.xtext.parser.antlr.TokenDefProvider;
import org.eclipse.xtext.parser.antlr.XtextTokenStream;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.xtext.arma.sQF.Model;
import org.xtext.arma.validation.SQFJavaValidator;

//TODO: Move to XtextUtils?
//import org.eclipselabs.xtext.utils.unittesting.XtextRunner2;

@RunWith(XtextRunner.class)
@InjectWith(org.xtext.arma.SQFInjectorProvider.class)

public class SQFTests extends AbstractXtextTests
{

    @Inject
    SQFJavaValidator validator;
    
    @Inject
    Injector injector;
    
    @Inject
    ParseHelper<Model> parser_;
    
    private ValidatorTester<SQFJavaValidator> tester;
    private Lexer lexer_;
    private TokenDefProvider tokenDefProvider_;
    
    @Override
    public void setUp() throws Exception
    {
        super.setUp();
        tester = new ValidatorTester<SQFJavaValidator>(validator, injector);
    }

    /**
     * return the list of tokens created by the lexer from the given input
     * */
    protected List<Token> getTokens(String input) {
      CharStream stream = new ANTLRStringStream(input);
      lexer_.setCharStream(stream);
      XtextTokenStream tokenStream = new XtextTokenStream(lexer_,
              tokenDefProvider_);
      @SuppressWarnings("unchecked")
      List<Token> tokens = tokenStream.getTokens();
      return tokens;
    }
    
    /**
     * return the name of the terminal rule for a given token
     * */
    protected String getTokenType(Token token) {
      return tokenDefProvider_.getTokenDefMap().get(token.getType());
    }
    
    @Test
    public void hint() throws Exception
    {
        //ValidatorTester<SQFJavaValidator> 
        Model model = parser_.parse("hint \"hello\"");
        tester.validate(model).assertOK();
    }
    
    @Test
    public void IfExitWith() throws Exception
    {
        Model model = parser_.parse(
            "if (!isNil \"A3L_RunCode\") exitwith {" +
            "    player setvariable [\"okay\",true,true];" +
            "};"
        );
        tester.validate(model).assertOK();
    }
    
    @Test
    public void diag_log() throws Exception
    {
        Model model = parser_.parse("dia_log \"hello\"");
        tester.validate(model).assertOK();
    }    
    
    @Test
    public void forVar() throws Exception
    {
        Model model = parser_.parse("for \"_i\" from 0 to 3 do {hint _i};");
        tester.validate(model).assertOK();
    }
    
    @Test
    public void percentage() throws Exception
    {
        Model model = parser_.parse("_ok = 30 % 2;");
        tester.validate(model).assertOK();
    }
    
    @Test
    public void IfExitWithSimple() throws Exception
    {
        Model model = parser_.parse(
                "if (true) exitwith {" +
                "    hint \"hello\"" +
                "};"
        );
        tester.validate(model).assertOK();
    }
    
    @Test
    public void ifExitWithEmpty() throws Exception
    {
        Model model = parser_.parse("if (true) exitwith {};");
        tester.validate(model).assertOK();
    }
    
    @Test
    public void testSwitch() throws Exception
    {
        Model model = parser_.parse(
                  "_variable = west;"
                + "switch(_variable) do {"
                + "    case west:"
                + "    {"
                + "       hint \"str\""
                + "    };"
                + "};");
        tester.validate(model).assertOK();    
    }
    
    @Test 
    public void macroInclude() throws Exception
    {
        Model model = parser_.parse("#include <macro.h>");
        tester.validate(model).assertOK();        
    }
    
    @Test
    public void multiMacroInclude() throws Exception
    {
        Model model = parser_.parse(
                "#include <macro1.h>"+
                "#include <macro2.h>"
        );
        tester.validate(model).assertOK();
    }
    
    
    @Test
    public void waitUntilScriptDone() throws Exception
    {
        Model model = parser_.parse("_handle = 0; waitUntil {scriptDone _handle};");
        tester.validate(model).assertOK();
    }
    
    @Test
    public void specialVarX() throws Exception
    {
        Model model = parser_.parse("_var = _x;");
        tester.validate(model).assertOK();        
    }
    
    @Test
    public void specialVarThisGlobal() throws Exception
    {
        Model model = parser_.parse("_var = this;");
        tester.validate(model).assertOK();        
    }
    
    @Test
    public void specialVarThisLocal() throws Exception
    {
        Model model = parser_.parse("_var = _this;");
        tester.validate(model).assertOK();        
    }
    
    @Test
    public void testTrue() throws Exception
    {
        Model model = parser_.parse("true");
        tester.validate(model).assertOK();
    }
    
    @Test
    public void array() throws Exception
    {
        Model model = parser_.parse("[1,[2,[3,4],5],6] select 1 select 1 select 0");
        tester.validate(model).assertOK();
    }
    
    @Test
    public void arrayNegative() throws Exception
    {
        Model model = parser_.parse("[1,[2,[3,4],5],6] select 1 hint 1 select 0");
        tester.validate(model).assertError(0);
    }
    
    @Test
    public void arrayCode() throws Exception
    {
        Model model = parser_.parse("_ok = [1+1];");
        tester.validate(model).assertOK();
    }
    
    @Test
    public void varReference() throws Exception
    {
        Model model = parser_.parse("_local = 1; hint _local;");
        tester.validate(model).assertOK();
    }
}
