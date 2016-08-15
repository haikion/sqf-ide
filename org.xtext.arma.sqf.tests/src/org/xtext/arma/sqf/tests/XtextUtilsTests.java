//TODO: Macro tests

package org.xtext.arma.sqf.tests;

import org.eclipse.xtext.junit4.InjectWith;
import org.eclipselabs.xtext.utils.unittesting.XtextRunner2;
import org.eclipselabs.xtext.utils.unittesting.XtextTest;
import org.xtext.arma.SQFInjectorProvider;
import org.xtext.arma.sQF.Model;
import org.junit.Test;
import org.junit.runner.RunWith;

@RunWith(XtextRunner2.class)
@InjectWith(SQFInjectorProvider.class)
public class XtextUtilsTests extends XtextTest
{
    public XtextUtilsTests()
    {
        super("sqfFiles");
    }
    
    @Test
    public void localVarTest()
    {
        testTerminal("_yeah", "LOCAL_VARIABLE");
    }
    
    @Test
    public void testUnrecognizedString()
    {
        testTerminal("ddsadsad", "UNRECOGNIZED_STRING");
    }
    
    @Test
    public void testUnrecognizedStringNegative()
    {
        testNotTerminal("dsadsad", "UNRECOGNIZED_STRING");
    }
    
    @Test
    public void objNull()
    {
        testParserRule("objNull", "CommandParameterless");
    }
    
    @Test
    public void inverseOperator()
    {
        testParserRule("! isNil \"A3L_RunCode\"", "LineOfCode");
    }
    
    @Test
    public void objNullNegative()
    {
        testNotTerminal("objNullooooooo", "UNRECOGNIZED_STRING");
    }
    
    @Test
    public void ifCaseInsenstiveLower()
    {
        testParserRule("if (true) exitwith {}", "If");
    }
    
    @Test
    public void ifCaseInsenstiveMixed()
    {
        testParserRule("if (true) exitWith {}", "If");
    }
    
    @Test
    public void doubleQuetoTest()
    {
        testParserRule("\"testing double \"\"quetos\"\" \"", "StringV");
    }
    
    @Test
    public void slashString()
    {
        testParserRule("\"core\\fsm\\core_time.fsm\"", "StringV");
    }
    
    @Test
    public void string()
    {
        testParserRule("\"simple String test\"", "StringV");
    }
    
    @Test
    public void execVM()
    {
        testParserRule("[] execVM \"A3L_Stuff\\jailsystem.sqf\"", "LineOfCode");
    }
    
    @Test
    public void getNumber()
    {
        testParserRule("getNumber (configFile)", "CommandLeft");
    }
    
    @Test
    public void configFileArrow()
    {
        testParserRule("configFile >> \"CfgVehicles\" >> \"Thing\" >> \"maxSpeed\"", "LineOfCode");
    }
    
    @Test
    public void configFileSlash()
    {
        testParserRule("configFile / \"CfgVehicles\" / \"Thing\" / \"maxSpeed\"", "LineOfCode");
    }
    
    @Test
    public void diagLog()
    {
        testParserRule("diag_log \"hello\"", "CommandLeft");
    }
    
    @Test
    public void select()
    {
        testParserRule("[1,2] select 2", "LineOfCode");
    }
    
    @Test
    public void cutTextMiddle()
    {
        testParserRule("1000 cutText [\"In The Centre\",\"PLAIN\"]", "LineOfCode");
    }
    
    @Test
    public void createVehicleMiddle() throws Exception
    {
        testParserRule("\"RoadCone_F\" createVehicle [0,0,0]", "LineOfCode");
    }
    
    @Test
    public void cutFadeOutMiddle()
    {
        testParserRule("0 cutFadeOut 2", "LineOfCode");
    }
    
    @Test
    public void execFSM()
    {
        testParserRule("[] execFSM \"core\\fsm\\client.fsm\"", "LineOfCode");
    }
    
    @Test
    public void switchTest()
    {
        testParserRule("switch (playerSide) do { case west: {}; }", "Switch");
    }
    
    @Test
    public void switchTestDefault()
    {
        testParserRule("switch (playerSide) do { case west: {}; default {};}", "Switch");
    }
    
    @Test
    public void switchTestCaseDefault()
    {
        testParserRule("switch (playerSide) do { case west: {};  case default {};}", "Switch");
    }    
    
    @Test
    public void publicFunctionDefinition()
    {
        testParserRule("life_fnc_moveIn = compileFinal \"player moveInCargo (_this select 0);\"", 
                "GlobalVariableDefinition");
    }
    
    @Test
    public void createVehicleLeft()
    {
        testParserRule("createVehicle [\"2S6M_Tunguska\", getMarkerPos \"marker1\", "
                + "[\"marker2\",\"marker3\"], 0, \"NONE\"]", "CommandLeft");
    }
    
    @Test
    public void simpleForTest()
    {
    	testParserRule("for \"_i\" from 0 to 270 do {hint \"ok\";}", "ForVariable");
    }
    
    //@Test
    //public void testTestFile()
    //{
    //    testFile("testFile.sqf");
    //}
}
