////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.52
//'now' is Wed Jul 13 18:00:51 2016 : 'file' last modified on Wed Jul 13 18:00:51 2016
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_versioning : config.bin{
class CfgPatches
{
	class cba_versioning
	{
		author = "$STR_CBA_Author";
		name = "$STR_cba_versioning_component";
		url = "$STR_CBA_URL";
		units[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CBA_common","CBA_strings","CBA_hashes","CBA_diagnostic","CBA_events","CBA_network"};
		version = "3.0.0.160713";
		authors[] = {"Sickboy"};
		weapons[] = {};
	};
};
class Extended_PreStart_EventHandlers
{
	class cba_versioning
	{
		init = "call compile preProcessFileLineNumbers '\x\cba\addons\versioning\XEH_preStart.sqf'";
	};
};
class Extended_PreInit_EventHandlers
{
	class cba_versioning
	{
		init = "call compile preProcessFileLineNumbers '\x\cba\addons\versioning\XEH_preInit.sqf'";
	};
};
class Extended_PostInit_EventHandlers
{
	class cba_versioning
	{
		init = "call compile preProcessFileLineNumbers '\x\cba\addons\versioning\XEH_postInit.sqf'";
		serverInit = "call compile preProcessFileLineNumbers '\x\cba\addons\versioning\XEH_postInitServer.sqf'";
		clientInit = "if !(isServer) then { call compile preProcessFileLineNumbers '\x\cba\addons\versioning\XEH_postInitClient.sqf'}";
	};
};
//};
