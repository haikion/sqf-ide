////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.52
//'now' is Wed Jul 13 18:00:33 2016 : 'file' last modified on Wed Jul 13 18:00:33 2016
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_diagnostic_enable_perf_loop : config.bin{
class CfgPatches
{
	class cba_diagnostic_enable_perf_loop
	{
		author = "$STR_CBA_Author";
		name = "$STR_cba_Optional_Component";
		url = "$STR_CBA_URL";
		units[] = {};
		requiredVersion = 1.02;
		requiredAddons[] = {"CBA_common","CBA_diagnostic"};
		version = "0.4.1.101";
		authors[] = {"Spooner","Sickboy"};
		weapons[] = {};
	};
};
class Extended_PostInit_EventHandlers
{
	class cba_diagnostic_enable_perf_loop
	{
		init = "[] spawn cba_diagnostic_fnc_perf_loop";
	};
};
//};
