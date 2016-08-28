////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.52
//'now' is Wed Jul 13 18:00:49 2016 : 'file' last modified on Wed Jul 13 18:00:49 2016
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_ui_helper : config.bin{
class CfgPatches
{
	class cba_ui_helper
	{
		author = "$STR_CBA_Author";
		name = "$STR_cba_ui_component";
		url = "$STR_CBA_URL";
		units[] = {};
		weapons[] = {};
		worlds[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CBA_common","A3_UI_F"};
	};
};
class RscListBox;
class RscButtonMenuOK;
class RscStandardDisplay;
class RscDisplayMultiplayer: RscStandardDisplay
{
	class Controls
	{
		class CA_Join: RscButtonMenuOK
		{
			onMouseButtonDown = "uiNamespace setVariable ['CBA_isCached', nil]";
			onKeyDown = "uiNamespace setVariable ['CBA_isCached', nil]";
		};
		class CA_ValueSessions: RscListBox
		{
			onMouseButtonDown = "uiNamespace setVariable ['CBA_isCached', nil]";
		};
	};
};
//};
