////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.52
//'now' is Wed Jul 13 18:00:46 2016 : 'file' last modified on Wed Jul 13 18:00:46 2016
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_statemachine : config.bin{
class CfgPatches
{
	class cba_statemachine
	{
		author = "$STR_CBA_Author";
		name = "$STR_cba_statemachine_component";
		url = "$STR_CBA_URL";
		units[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CBA_common"};
		version = "3.0.0.160713";
		authors[] = {"BaerMitUmlaut"};
		weapons[] = {};
	};
};
class Extended_PreStart_EventHandlers
{
	class cba_statemachine
	{
		init = "if (!(productVersion select 2 <= 154)) then {call compile preProcessFileLineNumbers '\x\cba\addons\statemachine\XEH_preStart.sqf'}";
	};
};
class Extended_PreInit_EventHandlers
{
	class cba_statemachine
	{
		init = "if (!(productVersion select 2 <= 154)) then {call compile preProcessFileLineNumbers '\x\cba\addons\statemachine\XEH_preInit.sqf'}";
	};
};
//};
