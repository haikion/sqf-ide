////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.52
//'now' is Wed Jul 13 18:00:36 2016 : 'file' last modified on Wed Jul 13 18:00:36 2016
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_help : config.bin{
class CfgPatches
{
	class cba_help
	{
		author = "$STR_CBA_Author";
		name = "$STR_cba_help_component";
		url = "$STR_CBA_URL";
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"cba_common","cba_hashes","cba_keybinding","A3_UI_F"};
		version = "3.0.0.160713";
		authors[] = {"alef","Rocko","Sickboy"};
	};
};
class Extended_PreInit_EventHandlers
{
	class cba_help
	{
		clientInit = "call compile preProcessFileLineNumbers '\x\cba\addons\help\XEH_preClientInit.sqf'";
	};
};
class Extended_PostInit_EventHandlers
{
	class cba_help
	{
		clientInit = "call compile preProcessFileLineNumbers '\x\cba\addons\help\XEH_postClientInit.sqf'";
	};
};
class Extended_DisplayLoad_EventHandlers
{
	class RscDisplayMain
	{
		CBA_helpVersion = "_this call compile preProcessFileLineNumbers '\x\cba\addons\help\fnc_setVersionLine.sqf'";
		CBA_helpCredits = "_this call compile preProcessFileLineNumbers '\x\cba\addons\help\fnc_setCreditsLine.sqf'";
	};
	class RscDisplayInterrupt
	{
		CBA_helpVersion = "_this call compile preProcessFileLineNumbers '\x\cba\addons\help\fnc_setVersionLine.sqf'";
		CBA_helpCredits = "_this call compile preProcessFileLineNumbers '\x\cba\addons\help\fnc_setCreditsLine.sqf'";
	};
	class RscDisplayMPInterrupt
	{
		CBA_helpVersion = "_this call compile preProcessFileLineNumbers '\x\cba\addons\help\fnc_setVersionLine.sqf'";
		CBA_helpCredits = "_this call compile preProcessFileLineNumbers '\x\cba\addons\help\fnc_setCreditsLine.sqf'";
	};
};
class RscButton;
class RscText;
class CBA_Credits_Ver_Btn: RscButton
{
	idc = -1;
	colorText[] = {1,1,1,0};
	colorDisabled[] = {1,1,1,0};
	colorBackground[] = {1,1,1,0};
	colorBackgroundDisabled[] = {1,1,1,0};
	colorBackgroundActive[] = {1,1,1,0};
	colorShadow[] = {1,1,1,0};
	colorFocused[] = {1,1,1,0};
	soundClick[] = {"",0.1,1};
	x = -1;
	y = -1;
	w = 0;
	h = 0;
	text = "";
};
class RscStructuredText;
class CBA_Credits_Cont: RscStructuredText
{
	idc = -1;
	colorBackground[] = {0,0,0,0};
	x = "8 * (((safezoneW / safezoneH) min 1.2)/ 40)+ (safezoneX + (safezoneW - ((safezoneW / safezoneH) min 1.2))/2)";
	y = "23 * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25)+ (safezoneY + safezoneH - (((safezoneW / safezoneH) min 1.2)/ 1.2))";
	w = "26 * (((safezoneW / safezoneH) min 1.2)/ 40)";
	h = "1 * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25)";
	class Attributes
	{
		font = "RobotoCondensed";
		align = "center";
		valign = "middle";
		color = "#bdcc9c";
		size = 0.8;
	};
};
class RscStandardDisplay;
class RscDisplayMain: RscStandardDisplay
{
	class controls
	{
		class CBA_Credits_Ver: RscText
		{
			idc = 2222712;
			y = -1;
			style = 0;
			shadow = 0;
			sizeEx = "0.8 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CBA_Credits_Ver_Btn: CBA_Credits_Ver_Btn
		{
			idc = 2222713;
			onMouseButtonClick = "_this call compile preProcessFileLineNumbers '\x\cba\addons\help\fnc_setVersionLine.sqf'";
		};
		class CBA_Credits_Cont_C: CBA_Credits_Cont
		{
			idc = 2222710;
		};
	};
};
class RscDisplayInterrupt: RscStandardDisplay
{
	class controls
	{
		class CBA_Credits_Cont_C: CBA_Credits_Cont
		{
			idc = 2222710;
		};
	};
};
class RscDisplayMPInterrupt: RscStandardDisplay
{
	class controls
	{
		class CBA_Credits_Cont_C: CBA_Credits_Cont
		{
			idc = 2222710;
		};
	};
};
//};
