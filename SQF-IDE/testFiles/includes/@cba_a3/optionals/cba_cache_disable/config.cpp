////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.52
//'now' is Wed Jul 13 18:00:29 2016 : 'file' last modified on Wed Jul 13 18:00:29 2016
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_cache_disable : config.bin{
class CfgPatches
{
	class cba_cache_disable
	{
		author = "$STR_CBA_Author";
		name = "$STR_cba_Optional_Component";
		url = "$STR_CBA_URL";
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {"CBA_Extended_EventHandlers","CBA_Main"};
		version = "3.0.0.160713";
		authors[] = {"Sickboy"};
	};
};
class CfgSettings
{
	class CBA
	{
		class Caching
		{
			xeh = 0;
			compile = 0;
			functions = 0;
		};
	};
};
//};
