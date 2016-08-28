////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.52
//'now' is Wed Jul 13 18:00:43 2016 : 'file' last modified on Wed Jul 13 18:00:43 2016
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_main_a3 : config.bin{
class CfgPatches
{
	class cba_main_a3
	{
		author = "$STR_CBA_Author";
		name = "$STR_cba_main_component";
		url = "$STR_CBA_URL";
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CBA_Main"};
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
		class Versioning
		{
			class cba
			{
				class Dependencies
				{
					CBA[] = {"cba_main",{1,0,0},"(true)"};
				};
			};
		};
	};
};
class CfgMods
{
	class cba
	{
		dir = "@CBA_A3";
		name = "Community Base Addons (Arma III)";
		picture = "x\cba\addons\main\logo_cba_ca.paa";
		hidePicture = "true";
		hideName = "true";
		actionName = "Website";
		action = "http://dev-heaven.net/projects/cca";
	};
};
//};
