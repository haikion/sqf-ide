////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.52
//'now' is Wed Jul 13 18:00:39 2016 : 'file' last modified on Wed Jul 13 18:00:39 2016
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_jr_prep : config.bin{
class CfgPatches
{
	class cba_jr_prep
	{
		author = "$STR_CBA_Author";
		name = "$STR_cba_jr_component";
		url = "$STR_CBA_URL";
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"A3_Weapons_F","A3_Weapons_F_Mark","A3_Weapons_F_Exp"};
		version = "3.0.0.160713";
	};
};
class CfgWeapons
{
	class Rifle;
	class Rifle_Base_F: Rifle
	{
		class WeaponSlotsInfo;
	};
	class Rifle_Long_Base_F: Rifle_Base_F
	{
		class WeaponSlotsInfo;
	};
	class EBR_base_F: Rifle_Long_Base_F
	{
		class WeaponSlotsInfo;
	};
	class srifle_EBR_F: EBR_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			delete UnderBarrelSlot;
		};
	};
	class GM6_base_F: Rifle_Long_Base_F{};
	class srifle_GM6_F: GM6_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			delete CowsSlot;
		};
	};
	class LRR_base_F: Rifle_Long_Base_F{};
	class srifle_LRR_F: LRR_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			delete CowsSlot;
		};
	};
	class DMR_01_base_F: Rifle_Long_Base_F
	{
		class WeaponSlotsInfo;
	};
	class srifle_DMR_01_F: DMR_01_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			delete UnderBarrelSlot;
		};
	};
	class LMG_Mk200_F: Rifle_Long_Base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			delete MuzzleSlot;
			delete CowsSlot;
			delete PointerSlot;
			delete UnderBarrelSlot;
		};
	};
	class LMG_Zafir_F: Rifle_Long_Base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			delete MuzzleSlot;
			delete CowsSlot;
			delete PointerSlot;
		};
	};
	class arifle_MX_Base_F: Rifle_Base_F
	{
		class WeaponSlotsInfo;
	};
	class arifle_MXC_F: arifle_MX_Base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			delete MuzzleSlot;
			delete CowsSlot;
			delete PointerSlot;
		};
	};
	class arifle_MXM_F: arifle_MX_Base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			delete MuzzleSlot;
		};
	};
	class arifle_MX_SW_F: arifle_MX_Base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			delete MuzzleSlot;
		};
	};
	class arifle_Katiba_Base_F: Rifle_Base_F
	{
		class WeaponSlotsInfo;
	};
	class arifle_Katiba_C_F: arifle_Katiba_Base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			delete MuzzleSlot;
		};
	};
	class Tavor_base_F: Rifle_Base_F
	{
		class WeaponSlotsInfo;
	};
	class arifle_TRG20_F: Tavor_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			delete MuzzleSlot;
		};
	};
	class LMG_03_base_F: Rifle_Long_Base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			delete MuzzleSlot;
			delete CowsSlot;
			delete PointerSlot;
			delete UnderBarrelSlot;
		};
	};
	class DMR_07_base_F: Rifle_Long_Base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			delete MuzzleSlot;
			delete CowsSlot;
			delete PointerSlot;
		};
	};
	class SMG_05_base_F: Rifle_Base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			delete MuzzleSlot;
			delete CowsSlot;
			delete PointerSlot;
			delete UnderBarrelSlot;
		};
	};
	class arifle_AK12_base_F: Rifle_Base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			delete MuzzleSlot;
			delete CowsSlot;
			delete PointerSlot;
		};
	};
	class arifle_SPAR_01_base_F: Rifle_Base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			delete MuzzleSlot;
			delete CowsSlot;
			delete PointerSlot;
		};
	};
	class arifle_SPAR_02_base_F: Rifle_Base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			delete MuzzleSlot;
			delete CowsSlot;
			delete PointerSlot;
			delete UnderBarrelSlot;
		};
	};
	class arifle_SPAR_03_base_F: Rifle_Base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			delete MuzzleSlot;
			delete CowsSlot;
			delete PointerSlot;
			delete UnderBarrelSlot;
		};
	};
	class arifle_CTAR_base_F: Rifle_Base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			delete MuzzleSlot;
			delete CowsSlot;
			delete PointerSlot;
		};
	};
	class arifle_CTARS_base_F: Rifle_Base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			delete MuzzleSlot;
			delete CowsSlot;
			delete PointerSlot;
		};
	};
	class arifle_ARX_base_F: Rifle_Base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			delete MuzzleSlot;
			delete CowsSlot;
			delete PointerSlot;
			delete UnderBarrelSlot;
		};
	};
};
//};
