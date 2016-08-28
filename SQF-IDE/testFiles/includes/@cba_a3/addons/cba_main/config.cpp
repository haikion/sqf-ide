////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.52
//'now' is Wed Jul 13 18:00:42 2016 : 'file' last modified on Wed Jul 13 18:00:42 2016
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_main : config.bin{
class CfgPatches
{
	class cba_main
	{
		author = "$STR_CBA_Author";
		name = "$STR_cba_main_component";
		url = "$STR_CBA_URL";
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"cba_common","cba_arrays","cba_hashes","cba_strings","cba_events","cba_diagnostic","cba_network","cba_ai","cba_vectors","cba_ui","cba_ui_helper","cba_help"};
		versionDesc = "C.B.A.";
		version = "3.0.0.160713";
		versionStr = "3.0.0.160713";
		versionAr[] = {3,0,0,160713};
		authors[] = {};
	};
};
class CfgSettings
{
	class CBA
	{
		class Caching
		{
			functions = 1;
		};
		class Versioning
		{
			class cba
			{
				class dependencies
				{
					CBA_A3[] = {"cba_main_a3",{1,0,0},"isClass(configFile >> 'CfgPatches' >> 'A3_Map_Stratis')"};
					XEH[] = {"cba_xeh",{1,0,0},"(true)"};
				};
			};
		};
		class Registry
		{
			class cba
			{
				removed[] = {};
			};
		};
	};
};
class CfgVehicles
{
	class Logic;
	class CBA_main_require: Logic
	{
		displayName = "Require CBA";
		vehicleClass = "Modules";
	};
};
//};
