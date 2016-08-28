////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.52
//'now' is Wed Jul 13 18:00:30 2016 : 'file' last modified on Wed Jul 13 18:00:30 2016
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_common : config.bin{
class CfgPatches
{
	class cba_common
	{
		author = "$STR_CBA_Author";
		name = "$STR_cba_common_component";
		url = "$STR_CBA_URL";
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"A3_BaseConfig_F"};
		version = "3.0.0.160713";
		authors[] = {"Spooner","Sickboy","Rocko"};
	};
};
class Extended_PreStart_EventHandlers
{
	class cba_common
	{
		init = "call compile preProcessFileLineNumbers '\x\cba\addons\common\XEH_preStart.sqf'";
	};
};
class Extended_PreInit_EventHandlers
{
	class cba_common
	{
		init = "call compile preProcessFileLineNumbers '\x\cba\addons\common\XEH_preInit.sqf'";
		clientInit = "call compile preProcessFileLineNumbers '\x\cba\addons\common\XEH_preClientInit.sqf'";
	};
};
class Extended_PostInit_EventHandlers
{
	class cba_common
	{
		init = "call compile preProcessFileLineNumbers '\x\cba\addons\common\XEH_postInit.sqf'";
	};
};
class CfgFunctions
{
	class CBA
	{
		class Config
		{
			class getConfigEntry
			{
				file = "\x\cba\addons\common\fnc_getConfigEntry.sqf";
			};
			class getObjectConfig
			{
				file = "\x\cba\addons\common\fnc_getObjectConfig.sqf";
			};
			class getItemConfig
			{
				file = "\x\cba\addons\common\fnc_getItemConfig.sqf";
			};
			class getMuzzles
			{
				file = "\x\cba\addons\common\fnc_getMuzzles.sqf";
			};
			class getWeaponModes
			{
				file = "\x\cba\addons\common\fnc_getWeaponModes.sqf";
			};
			class inheritsFrom
			{
				file = "\x\cba\addons\common\fnc_inheritsFrom.sqf";
			};
			class getTurret
			{
				file = "\x\cba\addons\common\fnc_getTurret.sqf";
			};
		};
		class Entities
		{
			class findEntity
			{
				file = "\x\cba\addons\common\fnc_findEntity.sqf";
			};
			class deleteEntity
			{
				file = "\x\cba\addons\common\fnc_deleteEntity.sqf";
			};
			class isAlive
			{
				file = "\x\cba\addons\common\fnc_isAlive.sqf";
			};
			class getAlive
			{
				file = "\x\cba\addons\common\fnc_getAlive.sqf";
			};
			class getGroup
			{
				file = "\x\cba\addons\common\fnc_getGroup.sqf";
			};
			class getSharedGroup
			{
				file = "\x\cba\addons\common\fnc_getSharedGroup.sqf";
			};
			class nearPlayer
			{
				file = "\x\cba\addons\common\fnc_nearPlayer.sqf";
			};
			class getArg
			{
				file = "\x\cba\addons\common\fnc_getArg.sqf";
			};
			class createMarker
			{
				file = "\x\cba\addons\common\fnc_createMarker.sqf";
			};
			class createTrigger
			{
				file = "\x\cba\addons\common\fnc_createTrigger.sqf";
			};
			class getGroupIndex
			{
				file = "\x\cba\addons\common\fnc_getGroupIndex.sqf";
			};
			class getMagazineIndex
			{
				file = "\x\cba\addons\common\fnc_getMagazineIndex.sqf";
			};
			class currentMagazineIndex
			{
				file = "\x\cba\addons\common\fnc_currentMagazineIndex.sqf";
			};
		};
		class Soldiers
		{
			class isPerson
			{
				file = "\x\cba\addons\common\fnc_isPerson.sqf";
			};
			class canUseWeapon
			{
				file = "\x\cba\addons\common\fnc_canUseWeapon.sqf";
			};
			class selectWeapon
			{
				file = "\x\cba\addons\common\fnc_selectWeapon.sqf";
			};
			class switchPlayer
			{
				file = "\x\cba\addons\common\fnc_switchPlayer.sqf";
			};
			class currentUnit
			{
				file = "\x\cba\addons\common\fnc_currentUnit.sqf";
			};
			class players
			{
				file = "\x\cba\addons\common\fnc_players.sqf";
			};
		};
		class Vehicles
		{
			class getFirer
			{
				file = "\x\cba\addons\common\fnc_getFirer.sqf";
			};
			class isTurnedOut
			{
				file = "\x\cba\addons\common\fnc_isTurnedOut.sqf";
			};
			class getVolume
			{
				file = "\x\cba\addons\common\fnc_getVolume.sqf";
			};
			class vehicleRole
			{
				file = "\x\cba\addons\common\fnc_vehicleRole.sqf";
			};
			class turretPath
			{
				file = "\x\cba\addons\common\fnc_turretPath.sqf";
			};
			class turretPathWeapon
			{
				file = "\x\cba\addons\common\fnc_turretPathWeapon.sqf";
			};
			class viewDir
			{
				file = "\x\cba\addons\common\fnc_viewDir.sqf";
			};
			class turretDir
			{
				file = "\x\cba\addons\common\fnc_turretDir.sqf";
			};
		};
		class Anims
		{
			class getAnimType
			{
				file = "\x\cba\addons\common\fnc_getAnimType.sqf";
			};
			class getUnitAnim
			{
				file = "\x\cba\addons\common\fnc_getUnitAnim.sqf";
			};
			class getUnitDeathAnim
			{
				file = "\x\cba\addons\common\fnc_getUnitDeathAnim.sqf";
			};
			class isUnitGetOutAnim
			{
				file = "\x\cba\addons\common\fnc_isUnitGetOutAnim.sqf";
			};
			class headDir
			{
				file = "\x\cba\addons\common\fnc_headDir.sqf";
			};
			class modelHeadDir
			{
				file = "\x\cba\addons\common\fnc_modelHeadDir.sqf";
			};
		};
		class Inventory
		{
			class addWeapon
			{
				file = "\x\cba\addons\common\fnc_addWeapon.sqf";
			};
			class addMagazine
			{
				file = "\x\cba\addons\common\fnc_addMagazine.sqf";
			};
			class addItem
			{
				file = "\x\cba\addons\common\fnc_addItem.sqf";
			};
			class removeWeapon
			{
				file = "\x\cba\addons\common\fnc_removeWeapon.sqf";
			};
			class removeMagazine
			{
				file = "\x\cba\addons\common\fnc_removeMagazine.sqf";
			};
			class removeItem
			{
				file = "\x\cba\addons\common\fnc_removeItem.sqf";
			};
			class weaponComponents
			{
				file = "\x\cba\addons\common\fnc_weaponComponents.sqf";
			};
			class dropWeapon
			{
				file = "\x\cba\addons\common\fnc_dropWeapon.sqf";
			};
			class dropMagazine
			{
				file = "\x\cba\addons\common\fnc_dropMagazine.sqf";
			};
			class dropItem
			{
				file = "\x\cba\addons\common\fnc_dropItem.sqf";
			};
			class binocularMagazine
			{
				file = "\x\cba\addons\common\fnc_binocularMagazine.sqf";
			};
			class addBinocularMagazine
			{
				file = "\x\cba\addons\common\fnc_addBinocularMagazine.sqf";
			};
			class removeBinocularMagazine
			{
				file = "\x\cba\addons\common\fnc_removeBinocularMagazine.sqf";
			};
		};
		class Cargo
		{
			class addWeaponCargo
			{
				file = "\x\cba\addons\common\fnc_addWeaponCargo.sqf";
			};
			class addMagazineCargo
			{
				file = "\x\cba\addons\common\fnc_addMagazineCargo.sqf";
			};
			class addItemCargo
			{
				file = "\x\cba\addons\common\fnc_addItemCargo.sqf";
			};
			class addBackpackCargo
			{
				file = "\x\cba\addons\common\fnc_addBackpackCargo.sqf";
			};
			class removeWeaponCargo
			{
				file = "\x\cba\addons\common\fnc_removeWeaponCargo.sqf";
			};
			class removeMagazineCargo
			{
				file = "\x\cba\addons\common\fnc_removeMagazineCargo.sqf";
			};
			class removeItemCargo
			{
				file = "\x\cba\addons\common\fnc_removeItemCargo.sqf";
			};
			class removeBackpackCargo
			{
				file = "\x\cba\addons\common\fnc_removeBackpackCargo.sqf";
			};
		};
		class Maps
		{
			class northingReversed
			{
				file = "\x\cba\addons\common\fnc_northingReversed.sqf";
			};
			class mapGridToPos
			{
				file = "\x\cba\addons\common\fnc_mapGridToPos.sqf";
			};
			class mapRelPos
			{
				file = "\x\cba\addons\common\fnc_mapRelPos.sqf";
			};
			class mapDirTo
			{
				file = "\x\cba\addons\common\fnc_mapDirTo.sqf";
			};
			class getTerrainProfile
			{
				file = "\x\cba\addons\common\fnc_getTerrainProfile.sqf";
			};
		};
		class Positions
		{
			class getDistance
			{
				file = "\x\cba\addons\common\fnc_getDistance.sqf";
			};
			class getPos
			{
				file = "\x\cba\addons\common\fnc_getPos.sqf";
			};
			class setPos
			{
				file = "\x\cba\addons\common\fnc_setPos.sqf";
			};
			class realHeight
			{
				file = "\x\cba\addons\common\fnc_realHeight.sqf";
			};
			class setHeight
			{
				file = "\x\cba\addons\common\fnc_setHeight.sqf";
			};
			class randPos
			{
				file = "\x\cba\addons\common\fnc_randPos.sqf";
			};
			class randPosArea
			{
				file = "\x\cba\addons\common\fnc_randPosArea.sqf";
			};
			class inArea
			{
				file = "\x\cba\addons\common\fnc_inArea.sqf";
			};
			class getNearest
			{
				file = "\x\cba\addons\common\fnc_getNearest.sqf";
			};
			class getNearestBuilding
			{
				file = "\x\cba\addons\common\fnc_getNearestBuilding.sqf";
			};
		};
		class Misc
		{
			class addPerFrameHandler
			{
				file = "\x\cba\addons\common\fnc_addPerFrameHandler.sqf";
			};
			class removePerFrameHandler
			{
				file = "\x\cba\addons\common\fnc_removePerFrameHandler.sqf";
			};
			class addPlayerAction
			{
				file = "\x\cba\addons\common\fnc_addPlayerAction.sqf";
			};
			class removePlayerAction
			{
				file = "\x\cba\addons\common\fnc_removePlayerAction.sqf";
			};
			class createNamespace
			{
				file = "\x\cba\addons\common\fnc_createNamespace.sqf";
			};
			class deleteNamespace
			{
				file = "\x\cba\addons\common\fnc_deleteNamespace.sqf";
			};
			class directCall
			{
				file = "\x\cba\addons\common\fnc_directCall.sqf";
			};
			class objectRandom
			{
				file = "\x\cba\addons\common\fnc_objectRandom.sqf";
			};
			class execNextFrame
			{
				file = "\x\cba\addons\common\fnc_execNextFrame.sqf";
			};
			class waitAndExecute
			{
				file = "\x\cba\addons\common\fnc_waitAndExecute.sqf";
			};
			class waitUntilAndExecute
			{
				file = "\x\cba\addons\common\fnc_waitUntilAndExecute.sqf";
			};
		};
		class Ui
		{
			class getFov
			{
				file = "\x\cba\addons\common\fnc_getFov.sqf";
			};
			class getAspectRatio
			{
				file = "\x\cba\addons\common\fnc_getAspectRatio.sqf";
			};
			class getUISize
			{
				file = "\x\cba\addons\common\fnc_getUISize.sqf";
			};
		};
		class Broken
		{
			class actionArgument
			{
				file = "\x\cba\addons\common\fnc_actionArgument.sqf";
			};
		};
	};
};
class CfgVehicles
{
	class Static;
	class CBA_NamespaceDummy: Static
	{
		scope = 1;
		displayName = "";
	};
};
class CfgLocationTypes
{
	class CBA_NamespaceDummy
	{
		name = "";
		drawStyle = "name";
		texture = "";
		color[] = {0,0,0,0};
		size = 0;
		textSize = 0;
		shadow = 0;
		font = "PuristaMedium";
	};
};
//};
