////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.52
//'now' is Wed Jul 13 18:00:34 2016 : 'file' last modified on Wed Jul 13 18:00:34 2016
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_events : config.bin{
class CfgPatches
{
	class cba_events
	{
		author = "$STR_CBA_Author";
		name = "$STR_cba_events_component";
		url = "$STR_CBA_URL";
		units[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CBA_common"};
		version = "3.0.0.160713";
		authors[] = {"Spooner","Sickboy","Xeno","commy2"};
		weapons[] = {};
	};
};
class Extended_PreStart_EventHandlers
{
	class cba_events
	{
		init = "call compile preProcessFileLineNumbers '\x\cba\addons\events\XEH_preStart.sqf'";
	};
};
class Extended_PreInit_EventHandlers
{
	class cba_events
	{
		init = "call compile preProcessFileLineNumbers '\x\cba\addons\events\XEH_preInit.sqf'";
	};
};
class Extended_PostInit_EventHandlers
{
	class cba_events
	{
		init = "call compile preProcessFileLineNumbers '\x\cba\addons\events\XEH_postInit.sqf'";
	};
};
class Extended_DisplayLoad_EventHandlers
{
	class RscDisplayMission
	{
		cba_events = "_this call compile preProcessFileLineNumbers '\x\cba\addons\events\XEH_missionDisplayLoad.sqf'";
	};
	class RscDisplayCurator
	{
		cba_events = "_this call compile preProcessFileLineNumbers '\x\cba\addons\events\XEH_curatorDisplayLoad.sqf'";
	};
};
class CfgFunctions
{
	class CBA
	{
		class Events
		{
			class addBISEventHandler
			{
				description = "Adds an event handler with arguments.";
				file = "\x\cba\addons\events\fnc_addBISEventHandler.sqf";
			};
			class addPlayerEventHandler
			{
				description = "Adds a player event handler.";
				file = "\x\cba\addons\events\fnc_addPlayerEventHandler.sqf";
			};
			class removePlayerEventHandler
			{
				description = "Removes a player event handler.";
				file = "\x\cba\addons\events\fnc_removePlayerEventHandler.sqf";
			};
			class addDisplayHandler
			{
				description = "Adds an action to the main display.";
				file = "\x\cba\addons\events\fnc_addDisplayHandler.sqf";
			};
			class removeDisplayHandler
			{
				description = "Removes an action from the main display.";
				file = "\x\cba\addons\events\fnc_removeDisplayHandler.sqf";
			};
			class addKeyHandler
			{
				description = "Adds an action to a keybind.";
				file = "\x\cba\addons\events\fnc_addKeyHandler.sqf";
			};
			class addKeyHandlerFromConfig
			{
				description = "Adds an action to a keybind from config.";
				file = "\x\cba\addons\events\fnc_addKeyHandlerFromConfig.sqf";
			};
			class readKeyFromConfig
			{
				description = "Reads key setting from config.";
				file = "\x\cba\addons\events\fnc_readKeyFromConfig.sqf";
			};
			class changeKeyHandler
			{
				description = "Changes the key of a key handler.";
				file = "\x\cba\addons\events\fnc_changeKeyHandler.sqf";
			};
			class removeKeyHandler
			{
				description = "Removes an action from a keybind.";
				file = "\x\cba\addons\events\fnc_removeKeyHandler.sqf";
			};
			class addEventHandler
			{
				description = "Registers an event handler for a specific CBA event.";
				file = "\x\cba\addons\events\fnc_addEventHandler.sqf";
			};
			class addEventHandlerArgs
			{
				description = "Registers an event handler for a specific CBA event with arguments.";
				file = "\x\cba\addons\events\fnc_addEventHandlerArgs.sqf";
			};
			class removeEventHandler
			{
				description = "Removes an event handler previously registered with CBA_fnc_addEventHandler.";
				file = "\x\cba\addons\events\fnc_removeEventHandler.sqf";
			};
			class localEvent
			{
				description = "Raises a CBA event on the local machine.";
				file = "\x\cba\addons\events\fnc_localEvent.sqf";
			};
			class globalEvent
			{
				description = "Raises a CBA event on all machines, including the local one.";
				file = "\x\cba\addons\events\fnc_globalEvent.sqf";
			};
			class globalEventJIP
			{
				description = "Raises a CBA event on all machines. Event is put on a stack that is executed on every future JIP machine. Stack can be overwritten by using the same JIP-Stack-ID.";
				file = "\x\cba\addons\events\fnc_globalEventJIP.sqf";
			};
			class serverEvent
			{
				description = "Raises a CBA event on the server machine.";
				file = "\x\cba\addons\events\fnc_serverEvent.sqf";
			};
			class remoteEvent
			{
				description = "Raises a CBA event on all machines, except the local one.";
				file = "\x\cba\addons\events\fnc_remoteEvent.sqf";
			};
			class targetEvent
			{
				description = "Raises a CBA event on all machines where this object or at least one of these objects are local.";
				file = "\x\cba\addons\events\fnc_targetEvent.sqf";
			};
			class ownerEvent
			{
				description = "Raises a CBA event on the target client ID's machine.";
				file = "\x\cba\addons\events\fnc_ownerEvent.sqf";
			};
		};
	};
};
//};
