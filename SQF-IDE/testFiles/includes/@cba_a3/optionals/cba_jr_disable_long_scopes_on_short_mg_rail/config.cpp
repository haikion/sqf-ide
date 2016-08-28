////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.52
//'now' is Wed Jul 13 18:00:38 2016 : 'file' last modified on Wed Jul 13 18:00:38 2016
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_jr_disable_long_scopes_on_short_mg_rail : config.bin{
class CfgPatches
{
	class cba_jr_disable_long_scopes_on_short_mg_rail
	{
		author = "$STR_CBA_Author";
		name = "$STR_cba_Optional_Component";
		url = "$STR_CBA_URL";
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"cba_jr"};
		version = "3.0.0.160713";
		authors[] = {"Robalo"};
	};
};
class asdg_OpticRail1913;
class asdg_OpticRail1913_short: asdg_OpticRail1913
{
	class compatibleItems;
};
class asdg_OpticRail1913_short_MG: asdg_OpticRail1913_short
{
	class compatibleItems: compatibleItems
	{
		optic_SOS = 0;
		optic_SOS_khk_F = 0;
		optic_DMS = 0;
		optic_DMS_ghex_F = 0;
		optic_LRPS = 0;
		optic_LRPS_ghex_F = 0;
		optic_LRPS_tna_F = 0;
		optic_AMS = 0;
		optic_AMS_khk = 0;
		optic_AMS_snd = 0;
		optic_KHS_blk = 0;
		optic_KHS_hex = 0;
		optic_KHS_old = 0;
		optic_KHS_tan = 0;
	};
};
//};
