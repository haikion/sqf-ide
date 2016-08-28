////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.52
//'now' is Wed Jul 13 18:00:32 2016 : 'file' last modified on Wed Jul 13 18:00:32 2016
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_diagnostic_enable_logging : config.bin{
class CfgPatches
{
	class cba_diagnostic_logging
	{
		author = "$STR_CBA_Author";
		name = "$STR_cba_Optional_Component";
		url = "$STR_CBA_URL";
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CBA_Diagnostic"};
		version = "3.0.0.160713";
		authors[] = {"Sickboy"};
	};
};
class Extended_Init_EventHandlers
{
	class All
	{
		class cba_diagnostic_logging
		{
			init = "diag_log [diag_frameNo, diag_fps, diag_tickTime, time, _this, typeOf (_this select 0), getPosASL (_this select 0)]";
		};
	};
};
//};
