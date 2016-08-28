////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.52
//'now' is Wed Jul 13 18:00:31 2016 : 'file' last modified on Wed Jul 13 18:00:31 2016
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_diagnostic : config.bin{
class CfgPatches
{
	class cba_diagnostic
	{
		author = "$STR_CBA_Author";
		name = "$STR_cba_diagnostic_component";
		url = "$STR_CBA_URL";
		units[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CBA_common","CBA_events","3DEN"};
		version = "3.0.0.160713";
		authors[] = {"Spooner","Sickboy"};
		weapons[] = {};
	};
};
class CfgFunctions
{
	class CBA
	{
		class Diagnostic
		{
			class benchmarkFunction
			{
				description = "Benchmarks a function to see how long it will take to execute.";
				file = "\x\cba\addons\diagnostic\fnc_benchmarkFunction.sqf";
			};
			class debug
			{
				description = "General Purpose Debug Message Writer";
				file = "\x\cba\addons\diagnostic\fnc_debug.sqf";
			};
			class error
			{
				description = "Logs an error message to the RPT log.";
				file = "\x\cba\addons\diagnostic\fnc_error.sqf";
			};
			class log
			{
				description = "Logs a message to the RPT log.";
				file = "\x\cba\addons\diagnostic\fnc_log.sqf";
			};
			class peek
			{
				description = "Peek at variable on the server To receive the variable content back, you will have to [""cba_diagnostics_receive_peak"", {_this call myFunction}] call CBA_fnc_addEventHandler;";
				file = "\x\cba\addons\diagnostic\fnc_peek.sqf";
			};
			class test
			{
				description = "Runs unit tests for an addon or component.";
				file = "\x\cba\addons\diagnostic\fnc_test.sqf";
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class cba_diagnostic
	{
		init = "call compile preProcessFileLineNumbers '\x\cba\addons\diagnostic\XEH_preStart.sqf'";
	};
};
class Extended_PreInit_EventHandlers
{
	class cba_diagnostic
	{
		init = "call compile preProcessFileLineNumbers '\x\cba\addons\diagnostic\XEH_preInit.sqf'";
	};
};
class Extended_DisplayLoad_EventHandlers
{
	class RscDisplayDebugPublic
	{
		CBA_extendedDebug = "_this call compile preProcessFileLineNumbers '\x\cba\addons\diagnostic\fnc_initExtendedDebug.sqf'";
		CBA_removeCancelBtn = "((_this select 0) displayCtrl 2) ctrlEnable false; ((_this select 0) displayCtrl 2) ctrlShow false;";
	};
	class RscDisplayInterrupt
	{
		CBA_extendedDebug = "_this call compile preProcessFileLineNumbers '\x\cba\addons\diagnostic\fnc_initExtendedDebug.sqf'";
	};
	class RscDisplayMPInterrupt
	{
		CBA_extendedDebug = "_this call compile preProcessFileLineNumbers '\x\cba\addons\diagnostic\fnc_initExtendedDebug.sqf'";
	};
};
class ctrlMenuStrip;
class Display3DEN
{
	class Controls
	{
		class MenuStrip: ctrlMenuStrip
		{
			class Items
			{
				class DebugConsole
				{
					shortcuts[] = {"512+0x20"};
				};
				class FunctionsViewer
				{
					shortcuts[] = {"2048+0x21"};
				};
				class ConfigViewer
				{
					shortcuts[] = {"512+0x22"};
				};
			};
		};
	};
};
//};
