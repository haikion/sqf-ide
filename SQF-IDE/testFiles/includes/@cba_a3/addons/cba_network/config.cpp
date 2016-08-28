////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.52
//'now' is Wed Jul 13 18:00:44 2016 : 'file' last modified on Wed Jul 13 18:00:44 2016
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_network : config.bin{
class CfgPatches
{
	class cba_network
	{
		author = "$STR_CBA_Author";
		name = "$STR_cba_network_component";
		url = "$STR_CBA_URL";
		units[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CBA_common","CBA_events"};
		version = "3.0.0.160713";
		authors[] = {"Sickboy"};
		weapons[] = {};
	};
};
class CfgSettings
{
	class CBA
	{
		class network
		{
			disableGlobalExecute = 0;
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class cba_network
	{
		init = "call compile preProcessFileLineNumbers '\x\cba\addons\network\XEH_preStart.sqf'";
	};
};
class Extended_PreInit_EventHandlers
{
	class cba_network
	{
		init = "call compile preProcessFileLineNumbers '\x\cba\addons\network\XEH_preInit.sqf'";
	};
};
class Extended_PostInit_EventHandlers
{
	class cba_network
	{
		serverInit = "call compile preProcessFileLineNumbers '\x\cba\addons\network\XEH_postServerInit.sqf'";
	};
};
class CfgFunctions
{
	class CBA
	{
		class Network
		{
			class getMarkerPersistent
			{
				description = "Checks if a global marker is persistent for JIP players.";
				file = "\x\cba\addons\network\fnc_getMarkerPersistent.sqf";
			};
			class globalExecute
			{
				description = "Executes code on given destinations";
				file = "\x\cba\addons\network\fnc_globalExecute.sqf";
			};
			class globalSay
			{
				description = "Says sound on all client computer";
				file = "\x\cba\addons\network\fnc_globalSay.sqf";
			};
			class globalSay3d
			{
				description = "Says sound on all client computer in 3d";
				file = "\x\cba\addons\network\fnc_globalSay3d.sqf";
			};
			class publicVariable
			{
				description = "CBA_fnc_publicVariable does only broadcast the new value if it doesn't exist in missionNamespace or the new value is different to the one in missionNamespace. Checks also for different types. Nil as value gets always broadcasted.";
				file = "\x\cba\addons\network\fnc_publicVariable.sqf";
			};
			class setMarkerPersistent
			{
				description = "Sets or unsets JIP persistency on a global marker.";
				file = "\x\cba\addons\network\fnc_setMarkerPersistent.sqf";
			};
			class setVarNet
			{
				description = "Same as setVariable [""name"",var, true] but only broadcasts when the value of var is different to the one which is already saved in the variable space. Checks also for different types. Nil as value gets always broadcasted.";
				file = "\x\cba\addons\network\fnc_setVarNet.sqf";
			};
		};
	};
};
//};
