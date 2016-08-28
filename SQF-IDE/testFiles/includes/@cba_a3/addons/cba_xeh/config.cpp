////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.52
//'now' is Wed Jul 13 18:00:51 2016 : 'file' last modified on Wed Jul 13 18:00:51 2016
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_xeh : config.bin{
class CfgPatches
{
	class cba_xeh
	{
		author = "$STR_CBA_Author";
		name = "$STR_cba_xeh_component";
		url = "$STR_CBA_URL";
		units[] = {};
		weapons[] = {};
		requiredAddons[] = {"A3_Data_F","A3_Characters_F","A3_Air_F","A3_Armor_F","A3_Boat_F","A3_Soft_F","A3_Air_F_Heli_Heli_Transport_04","A3_Characters_F_exp"};
		requiredVersion = 0.1;
		version = "4.0.0";
		versionStr = "4.0.0";
		versionAr[] = {4,0,0};
		authors[] = {"Solus","Killswitch","commy2"};
		addonRootClass = "A3_Characters_F";
	};
	class cba_xeh_a3: cba_xeh
	{
		author = "";
	};
	class Extended_EventHandlers: cba_xeh
	{
		author = "";
	};
	class CBA_Extended_EventHandlers: cba_xeh
	{
		author = "";
	};
	class cba_ee: cba_xeh
	{
		author = "";
	};
};
class CBA_Extended_EventHandlers_base
{
	init = "(_this select 0) call CBA_fnc_initEvents; (_this select 0) call CBA_fnc_init";
	fired = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_fired"")";
	animChanged = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_animChanged"")";
	animDone = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_animDone"")";
	animStateChanged = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_animStateChanged"")";
	containerClosed = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_containerClosed"")";
	containerOpened = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_containerOpened"")";
	controlsShifted = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_controlsShifted"")";
	dammaged = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_dammaged"")";
	engine = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_engine"")";
	epeContact = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_epeContact"")";
	epeContactEnd = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_epeContactEnd"")";
	epeContactStart = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_epeContactStart"")";
	explosion = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_explosion"")";
	firedNear = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_firedNear"")";
	fuel = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_cba_xeh_fuel"")";
	gear = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_gear"")";
	getIn = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_getIn"")";
	getInMan = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_getInMan"")";
	getOut = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_getOut"")";
	getOutMan = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_getOutMan"")";
	handleHeal = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_handleHeal"")";
	hit = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_hit"")";
	hitPart = "{_this call _x} forEach ((_this select 0 select 0) getVariable ""cba_xeh_hitPart"")";
	incomingMissile = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_incomingMissile"")";
	inventoryClosed = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_inventoryClosed"")";
	inventoryOpened = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_inventoryOpened"")";
	killed = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_killed"")";
	landedTouchDown = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_landedTouchDown"")";
	landedStopped = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_landedStopped"")";
	local = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_local"")";
	respawn = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_respawn"")";
	put = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_put"")";
	take = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_take"")";
	seatSwitched = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_seatSwitched"")";
	seatSwitchedMan = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_seatSwitchedMan"")";
	soundPlayed = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_soundPlayed"")";
	weaponAssembled = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_weaponAssembled"")";
	weaponDisassembled = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_weaponDisassembled"")";
	weaponDeployed = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_weaponDeployed"")";
	weaponRested = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_weaponRested"")";
	reloaded = "{_this call _x} forEach ((_this select 0) getVariable ""cba_xeh_reloaded"")";
};
class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base{};
class DefaultEventhandlers
{
	class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base{};
};
class Extended_PreStart_EventHandlers{};
class Extended_PreInit_EventHandlers{};
class Extended_PostInit_EventHandlers{};
class Extended_InitPost_EventHandlers{};
class Extended_AnimChanged_EventHandlers{};
class Extended_AnimDone_EventHandlers{};
class Extended_AnimStateChanged_EventHandlers{};
class Extended_ContainerClosed_EventHandlers{};
class Extended_ContainerOpened_EventHandlers{};
class Extended_ControlsShifted_EventHandlers{};
class Extended_Dammaged_EventHandlers{};
class Extended_Engine_EventHandlers{};
class Extended_EpeContact_EventHandlers{};
class Extended_EpeContactEnd_EventHandlers{};
class Extended_EpeContactStart_EventHandlers{};
class Extended_Explosion_EventHandlers{};
class Extended_Fired_EventHandlers{};
class Extended_FiredBIS_EventHandlers{};
class Extended_FiredNear_EventHandlers{};
class Extended_Fuel_EventHandlers{};
class Extended_Gear_EventHandlers{};
class Extended_GetIn_EventHandlers{};
class Extended_GetInMan_EventHandlers{};
class Extended_GetOut_EventHandlers{};
class Extended_GetOutMan_EventHandlers{};
class Extended_Hit_EventHandlers{};
class Extended_HitPart_EventHandlers{};
class Extended_IncomingMissile_EventHandlers{};
class Extended_Init_EventHandlers{};
class Extended_InventoryClosed_EventHandlers{};
class Extended_InventoryOpened_EventHandlers{};
class Extended_Killed_EventHandlers{};
class Extended_LandedStopped_EventHandlers{};
class Extended_LandedTouchDown_EventHandlers{};
class Extended_Local_EventHandlers{};
class Extended_Put_EventHandlers{};
class Extended_Respawn_EventHandlers{};
class Extended_SeatSwitched_EventHandlers{};
class Extended_SeatSwitchedMan_EventHandlers{};
class Extended_SoundPlayed_EventHandlers{};
class Extended_Take_EventHandlers{};
class Extended_WeaponAssembled_EventHandlers{};
class Extended_WeaponDisassembled_EventHandlers{};
class Extended_Reloaded_EventHandlers{};
class Extended_DisplayLoad_EventHandlers
{
	class Display3DEN
	{
		cba_xeh = "call compile preProcessFileLineNumbers '\x\cba\addons\xeh\XEH_3DENDisplayLoad.sqf'";
	};
};
class Extended_DisplayUnload_EventHandlers{};
class CfgFunctions
{
	class CBA
	{
		class XEH
		{
			class isScheduled
			{
				description = "Check if the current scope is running in scheduled or unscheduled environment.";
				file = "\x\cba\addons\xeh\fnc_isScheduled.sqf";
			};
			class isRecompileEnabled
			{
				description = "Check if recompiling is enabled.";
				file = "\x\cba\addons\xeh\fnc_isRecompileEnabled.sqf";
			};
			class addClassEventHandler
			{
				description = "Add an eventhandler to a class and all children.";
				file = "\x\cba\addons\xeh\fnc_addClassEventHandler.sqf";
			};
			class init
			{
				headerType = -1;
				description = "Runs Init and InitPost event handlers on this object.";
				file = "\x\cba\addons\xeh\fnc_init.sqf";
			};
			class initEvents
			{
				headerType = -1;
				description = "Adds all event handlers to this object.";
				file = "\x\cba\addons\xeh\fnc_initEvents.sqf";
			};
			class supportMonitor
			{
				description = "Iterate through all vehicle classes and find those who don't support extended event handlers.";
				file = "\x\cba\addons\xeh\fnc_supportMonitor.sqf";
			};
			class compileEventHandlers
			{
				description = "Compiles all Extended EventHandlers in given config.";
				file = "\x\cba\addons\xeh\fnc_compileEventHandlers.sqf";
			};
			class compileFunction
			{
				description = "Compiles a function into mission namespace and into ui namespace for caching purposes.";
				file = "\x\cba\addons\xeh\fnc_compileFunction.sqf";
			};
			class preStart
			{
				preStart = 1;
				description = "Occurs once during game start.";
				file = "\x\cba\addons\xeh\fnc_preStart.sqf";
			};
			class preInit
			{
				preInit = 1;
				description = "Occurs once per mission before objects are initialized.";
				file = "\x\cba\addons\xeh\fnc_preInit.sqf";
			};
			class postInit
			{
				postInit = 1;
				description = "Occurs once per mission after objects and functions are initialized.";
				file = "\x\cba\addons\xeh\fnc_postInit.sqf";
			};
			class postInit_unscheduled
			{
				description = "Occurs once per mission after objects and functions are initialized.";
				file = "\x\cba\addons\xeh\fnc_postInit_unscheduled.sqf";
			};
			class startFallbackLoop
			{
				description = "Starts a loop to iterate through all objects to initialize event handlers on XEH incompatible objects.";
				file = "\x\cba\addons\xeh\fnc_startFallbackLoop.sqf";
			};
		};
	};
	class A3
	{
		class GUI
		{
			class initDisplay
			{
				file = "\x\cba\addons\xeh\fnc_initDisplay.sqf";
			};
		};
	};
};
class CfgVehicles
{
	class All
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class Logic: All
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 1;
	};
	class LaserTarget: All
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 1;
	};
	class NVTarget: All
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 1;
	};
	class ArtilleryTarget: All
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 1;
	};
	class FireSectorTarget: All
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 1;
	};
	class Static: All
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 1;
	};
	class Thing: All
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 1;
	};
	class Helicopter;
	class ParachuteBase: Helicopter
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class StaticWeapon;
	class StaticCannon: StaticWeapon
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class StaticMortar;
	class Mortar_01_base_F: StaticMortar
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class Land_Campfire_F;
	class Campfire_burning_F: Land_Campfire_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class Land_FirePlace_F;
	class FirePlace_burning_F: Land_FirePlace_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class House_F;
	class PowerLines_base_F: House_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class Land_Communication_anchor_F: House_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class Land_Communication_F: House_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class House_Small_F;
	class PowerLines_Small_base_F: House_Small_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class Land_MetalBarrel_empty_F;
	class MetalBarrel_burning_F: Land_MetalBarrel_empty_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class FlagCarrierCore;
	class FlagChecked_F: FlagCarrierCore
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class ThingX;
	class ReammoBox_F: ThingX
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class C_man_w_worker_F;
	class C_scientist_F: C_man_w_worker_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class C_man_1;
	class C_journalist_F: C_man_1
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class C_Driver_1_F: C_man_1
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class Civilian_F;
	class VirtualMan_F: Civilian_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class VirtualSpectator_F: VirtualMan_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class PlaneWreck;
	class Plane_Fighter_03_wreck_F: PlaneWreck
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class Wreck_base_F;
	class Land_Wreck_Heli_Attack_01_F: Wreck_base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class Land_TentA_F;
	class Respawn_TentA_F: Land_TentA_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class Land_TentDome_F;
	class Respawn_TentDome_F: Land_TentDome_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class Land_Sleeping_bag_F;
	class Respawn_Sleeping_bag_F: Land_Sleeping_bag_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class Land_Sleeping_bag_blue_F;
	class Respawn_Sleeping_bag_blue_F: Land_Sleeping_bag_blue_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class Land_Sleeping_bag_brown_F;
	class Respawn_Sleeping_bag_brown_F: Land_Sleeping_bag_brown_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class SLX_XEH_Logic: Logic
	{
		scope = 1;
		displayName = "XEH Initialization Logic";
	};
	class Pod_Heli_Transport_04_crewed_base_F: StaticWeapon
	{
		class EventHandlers;
	};
	class Slingload_base_F;
	class Pod_Heli_Transport_04_base_F: Slingload_base_F
	{
		class EventHandlers;
	};
	class Land_Pod_Heli_Transport_04_ammo_F: Pod_Heli_Transport_04_base_F
	{
		class EventHandlers: EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base{};
		};
	};
	class Land_Pod_Heli_Transport_04_bench_F: Pod_Heli_Transport_04_crewed_base_F
	{
		class EventHandlers: EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base{};
		};
	};
	class Land_Pod_Heli_Transport_04_box_F: Pod_Heli_Transport_04_base_F
	{
		class EventHandlers: EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base{};
		};
	};
	class Land_Pod_Heli_Transport_04_covered_F: Pod_Heli_Transport_04_crewed_base_F
	{
		class EventHandlers: EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base{};
		};
	};
	class Land_Pod_Heli_Transport_04_fuel_F: Pod_Heli_Transport_04_base_F
	{
		class EventHandlers: EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base{};
		};
	};
	class Land_Pod_Heli_Transport_04_medevac_F: Pod_Heli_Transport_04_crewed_base_F
	{
		class EventHandlers: EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base{};
		};
	};
	class Land_Pod_Heli_Transport_04_repair_F: Pod_Heli_Transport_04_base_F
	{
		class EventHandlers: EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base{};
		};
	};
	class Land_Pod_Heli_Transport_04_ammo_black_F: Land_Pod_Heli_Transport_04_ammo_F
	{
		class EventHandlers: EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base{};
		};
	};
	class Land_Pod_Heli_Transport_04_bench_black_F: Land_Pod_Heli_Transport_04_bench_F
	{
		class EventHandlers: EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base{};
		};
	};
	class Land_Pod_Heli_Transport_04_box_black_F: Land_Pod_Heli_Transport_04_box_F
	{
		class EventHandlers: EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base{};
		};
	};
	class Land_Pod_Heli_Transport_04_covered_black_F: Land_Pod_Heli_Transport_04_covered_F
	{
		class EventHandlers: EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base{};
		};
	};
	class Land_Pod_Heli_Transport_04_fuel_black_F: Land_Pod_Heli_Transport_04_fuel_F
	{
		class EventHandlers: EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base{};
		};
	};
	class Land_Pod_Heli_Transport_04_medevac_black_F: Land_Pod_Heli_Transport_04_medevac_F
	{
		class EventHandlers: EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base{};
		};
	};
	class Land_Pod_Heli_Transport_04_repair_black_F: Land_Pod_Heli_Transport_04_repair_F
	{
		class EventHandlers: EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base{};
		};
	};
	class Helicopter_Base_F;
	class Helicopter_Base_H: Helicopter_Base_F
	{
		class EventHandlers;
	};
	class Heli_Transport_04_base_F: Helicopter_Base_H
	{
		class EventHandlers: EventHandlers
		{
			init = "if (local (_this select 0)) then {[(_this select 0), """", false, false] call bis_fnc_initVehicle;};";
		};
	};
	class Plane_Base_F;
	class Plane_Civil_01_base_F: Plane_Base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class B_CTRG_Soldier_3_F;
	class B_CTRG_Miller_F: B_CTRG_Soldier_3_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class Land_PowerLine_01_pole_junction_F: PowerLines_Small_base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class Land_PowerLine_01_pole_lamp_F: PowerLines_Small_base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class Land_PowerLine_01_pole_lamp_off_F: PowerLines_Small_base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class Land_PowerLine_01_pole_small_F: PowerLines_Small_base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class Land_PowerLine_01_pole_tall_F: PowerLines_Small_base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
	class Land_PowerLine_01_pole_transformer_F: PowerLines_Small_base_F
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers{};
		};
		SLX_XEH_DISABLED = 0;
	};
};
//};
