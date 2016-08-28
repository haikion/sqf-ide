////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.52
//'now' is Wed Jul 13 18:00:43 2016 : 'file' last modified on Wed Jul 13 18:00:43 2016
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_modules : config.bin{
class CfgPatches
{
	class cba_modules
	{
		author = "$STR_CBA_Author";
		name = "$STR_cba_modules_component";
		url = "$STR_CBA_URL";
		units[] = {"CBA_ModuleAttack","CBA_ModuleDefend","CBA_ModulePatrol"};
		requiredVersion = 1.62;
		requiredAddons[] = {"A3_Modules_F","CBA_common"};
		version = "3.0.0.160713";
		authors[] = {"WiredTiger"};
		weapons[] = {};
	};
};
class CfgFactionClasses
{
	class NO_CATEGORY;
	class CBA_Modules: NO_CATEGORY
	{
		displayName = "$STR_cba_modules_Category_DisplayName";
	};
};
class CfgVehicles
{
	class Logic;
	class Module_F: Logic
	{
		class ArgumentsBaseUnits;
		class ModuleDescription;
	};
	class CBA_ModuleAttack: Module_F
	{
		scope = 2;
		displayName = "$STR_cba_modules_Attack";
		author = "WiredTiger";
		vehicleClass = "Modules";
		category = "CBA_Modules";
		function = "CBA_fnc_moduleAttack";
		functionPriority = 1;
		isGlobal = 2;
		isTriggerActivated = 1;
		isDisposable = 0;
		is3DEN = 0;
		curatorInfoType = "RscDisplayAttributeAttack";
		class Arguments: ArgumentsBaseUnits
		{
			class attackLocType
			{
				displayName = "$STR_cba_modules_AttackLocType";
				description = "$STR_cba_modules_AttackLocType_Desc";
				typeName = "STRING";
				class values
				{
					class moduleLoc
					{
						name = "$STR_cba_modules_ModuleLoc";
						value = "";
						default = "";
					};
					class objectLoc
					{
						name = "$STR_cba_modules_ObjectLoc";
						value = "OBJECT";
					};
					class groupLoc
					{
						name = "$STR_cba_modules_GroupLoc";
						value = "GROUP";
					};
					class arrayLoc
					{
						name = "$STR_cba_modules_ArrayLoc";
						value = "ARRAY";
					};
					class markerLoc
					{
						name = "$STR_cba_modules_MarkerLoc";
						value = "MARKER";
					};
					class taskLoc
					{
						name = "$STR_cba_modules_TaskLoc";
						value = "TASK";
					};
				};
			};
			class attackPosition
			{
				displayName = "$STR_cba_modules_AttackPosition";
				description = "$STR_cba_modules_AttackPosition_Desc";
				typeName = "STRING";
			};
			class searchRadius
			{
				displayName = "$STR_cba_modules_SearchRadius";
				description = "$STR_cba_modules_SearchRadius_Desc";
				typeName = "NUMBER";
				defaultValue = 0;
			};
			class allowOverride
			{
				displayName = "$STR_cba_modules_AllowOverride";
				description = "$STR_cba_modules_AllowOverride_Desc";
				typeName = "STRING";
				class values
				{
					class no
					{
						name = "$STR_lib_info_no";
						value = "no";
						default = "";
					};
					class yes
					{
						name = "$STR_lib_info_yes";
						value = "yes";
					};
				};
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description = "$STR_cba_modules_AttackModuleDescription";
			sync[] = {"LocationArea_F"};
			class LocationArea_F
			{
				position = 0;
				optional = 0;
				duplicate = 1;
				synced[] = {"Anything"};
			};
		};
	};
	class CBA_ModuleDefend: Module_F
	{
		scope = 2;
		displayName = "$STR_cba_modules_Defend";
		author = "WiredTiger";
		vehicleClass = "Modules";
		category = "CBA_Modules";
		function = "CBA_fnc_moduleDefend";
		functionPriority = 1;
		isGlobal = 2;
		isTriggerActivated = 1;
		isDisposable = 0;
		is3DEN = 0;
		curatorInfoType = "RscDisplayAttributeDefend";
		class Arguments: ArgumentsBaseUnits
		{
			class defendLocType
			{
				displayName = "$STR_cba_modules_DefendPositionType";
				description = "$STR_cba_modules_DefendPositionType_Desc";
				typeName = "STRING";
				class values
				{
					class setLoc
					{
						name = "$STR_cba_modules_SetLoc";
						value = "";
						default = "";
					};
					class objectLoc
					{
						name = "$STR_cba_modules_ObjectLoc";
						value = "OBJECT";
					};
					class groupLoc
					{
						name = "$STR_cba_modules_GroupLoc";
						value = "GROUP";
					};
					class arrayLoc
					{
						name = "$STR_cba_modules_ArrayLoc";
						value = "ARRAY";
					};
					class markerLoc
					{
						name = "$STR_cba_modules_MarkerLoc";
						value = "MARKER";
					};
					class taskLoc
					{
						name = "$STR_cba_modules_TaskLoc";
						value = "TASK";
					};
				};
			};
			class defendPosition
			{
				displayName = "$STR_cba_modules_DefendPosition";
				description = "$STR_cba_modules_DefendPosition_Desc";
				typeName = "STRING";
			};
			class defendRadius
			{
				displayName = "$STR_cba_modules_DefendRadius";
				description = "$STR_cba_modules_DefendRadius_Desc";
				typeName = "NUMBER";
				defaultValue = 25;
			};
			class threshold
			{
				displayName = "$STR_cba_modules_Threshold";
				description = "$STR_cba_modules_Threshold_Desc";
				typeName = "NUMBER";
				class values
				{
					class two
					{
						name = "2";
						value = 2;
						default = 2;
					};
					class one
					{
						name = "1";
						value = 1;
					};
					class three
					{
						name = "3";
						value = 3;
					};
					class four
					{
						name = "4";
						value = 4;
					};
					class five
					{
						name = "5";
						value = 5;
					};
					class six
					{
						name = "6";
						value = 6;
					};
				};
			};
			class canPatrol
			{
				displayName = "$STR_cba_modules_CanPatrol";
				description = "$STR_cba_modules_CanPatrol_Desc";
				typeName = "BOOL";
				class values
				{
					class yes
					{
						name = "$STR_lib_info_yes";
						value = 1;
						default = 1;
					};
					class no
					{
						name = "$STR_lib_info_no";
						value = 0;
					};
				};
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description = "$STR_cba_modules_DefendModuleDescription";
			sync[] = {"LocationArea_F"};
			class LocationArea_F
			{
				position = 0;
				optional = 0;
				duplicate = 1;
				synced[] = {"Anything"};
			};
		};
	};
	class CBA_ModulePatrol: Module_F
	{
		scope = 2;
		displayName = "$STR_cba_modules_Patrol";
		author = "WiredTiger";
		vehicleClass = "Modules";
		category = "CBA_Modules";
		function = "CBA_fnc_modulePatrol";
		functionPriority = 1;
		isGlobal = 2;
		isTriggerActivated = 1;
		isDisposable = 0;
		is3DEN = 0;
		curatorInfoType = "RscDisplayAttributePatrol";
		class Arguments: ArgumentsBaseUnits
		{
			class patrolLocType
			{
				displayName = "$STR_cba_modules_PatrolCenterType";
				description = "$STR_cba_modules_PatrolCenterType_Desc";
				typeName = "STRING";
				class values
				{
					class setLoc
					{
						name = "$STR_cba_modules_SetLoc";
						value = "";
						default = "";
					};
					class objectLoc
					{
						name = "$STR_cba_modules_ObjectLoc";
						value = "OBJECT";
					};
					class groupLoc
					{
						name = "$STR_cba_modules_GroupLoc";
						value = "GROUP";
					};
					class arrayLoc
					{
						name = "$STR_cba_modules_ArrayLoc";
						value = "ARRAY";
					};
					class markerLoc
					{
						name = "$STR_cba_modules_MarkerLoc";
						value = "MARKER";
					};
					class taskLoc
					{
						name = "$STR_cba_modules_TaskLoc";
						value = "TASK";
					};
				};
			};
			class patrolPosition
			{
				displayName = "$STR_cba_modules_PatrolPosition";
				description = "$STR_cba_modules_PatrolPosition_Desc";
				typeName = "STRING";
			};
			class patrolRadius
			{
				displayName = "$STR_cba_modules_PatrolRadius";
				description = "$STR_cba_modules_PatrolRadius_Desc";
				typeName = "NUMBER";
				defaultValue = 25;
			};
			class waypointCount
			{
				displayName = "$STR_cba_modules_WaypointCount";
				description = "$STR_cba_modules_WaypointCount_Desc";
				typeName = "NUMBER";
				defaultValue = 4;
			};
			class waypointType
			{
				displayName = "$STR_cba_modules_WaypointType";
				description = "$STR_cba_modules_WaypointType_Desc";
				typeName = "STRING";
				class values
				{
					class move
					{
						name = "$STR_cba_modules_Move";
						value = "MOVE";
						default = "";
					};
					class sad
					{
						name = "$STR_cba_modules_SAD";
						value = "SAD";
					};
					class loiter
					{
						name = "$STR_cba_modules_Loiter";
						value = "LOITER";
					};
				};
			};
			class behaviour
			{
				displayName = "$STR_cba_modules_Behaviour";
				description = "$STR_cba_modules_Behaviour_Desc";
				typeName = "STRING";
				class values
				{
					class careless
					{
						name = "$STR_cba_modules_Careless";
						value = "CARELESS";
						default = "";
					};
					class safe
					{
						name = "$STR_cba_modules_Safe";
						value = "SAFE";
					};
					class aware
					{
						name = "$STR_cba_modules_Aware";
						value = "AWARE";
					};
					class combat
					{
						name = "$STR_cba_modules_Combat";
						value = "COMBAT";
					};
					class stealth
					{
						name = "$STR_cba_modules_Stealth";
						value = "STEALTH";
					};
				};
			};
			class combatMode
			{
				displayName = "$STR_cba_modules_CombatMode";
				description = "$STR_cba_modules_CombatMode_Desc";
				typeName = "STRING";
				class values
				{
					class yellow
					{
						name = "$STR_cba_modules_CombatYellow";
						value = "YELLOW";
						default = "";
					};
					class blue
					{
						name = "$STR_cba_modules_CombatBlue";
						value = "BLUE";
					};
					class green
					{
						name = "$STR_cba_modules_CombatGreen";
						value = "GREEN";
					};
					class white
					{
						name = "$STR_cba_modules_CombatWhite";
						value = "WHITE";
					};
					class red
					{
						name = "$STR_cba_modules_CombatRed";
						value = "RED";
					};
				};
			};
			class speedMode
			{
				displayName = "$STR_cba_modules_SpeedMode";
				description = "$STR_cba_modules_SpeedMode_Desc";
				typeName = "STRING";
				class values
				{
					class limited
					{
						name = "$STR_cba_modules_SpeedLimited";
						value = "LIMITED";
						default = "";
					};
					class normal
					{
						name = "$STR_cba_modules_SpeedNormal";
						value = "NORMAL";
					};
					class full
					{
						name = "$STR_cba_modules_SpeedFull";
						value = "FULL";
					};
				};
			};
			class formation
			{
				displayName = "$STR_cba_modules_Formation";
				description = "$STR_cba_modules_Formation_Desc";
				typeName = "STRING";
				class values
				{
					class column
					{
						name = "$STR_cba_modules_Column";
						value = "COLUMN";
						default = "";
					};
					class stagColumn
					{
						name = "$STR_cba_modules_StagColumn";
						value = "STAG COLUMN";
					};
					class wedge
					{
						name = "$STR_cba_modules_Wedge";
						value = "WEDGE";
					};
					class echLeft
					{
						name = "$STR_cba_modules_EchLeft";
						value = "ECH LEFT";
					};
					class echRight
					{
						name = "$STR_cba_modules_EchRight";
						value = "ECH RIGHT";
					};
					class vee
					{
						name = "$STR_cba_modules_Vee";
						value = "VEE";
					};
					class line
					{
						name = "$STR_cba_modules_Line";
						value = "LINE";
					};
					class file
					{
						name = "$STR_cba_modules_File";
						value = "FILE";
					};
					class diamond
					{
						name = "$STR_cba_modules_Diamond";
						value = "DIAMOND";
					};
				};
			};
			class executableCode
			{
				displayName = "$STR_cba_modules_ExecutableCode";
				description = "$STR_cba_modules_ExecutableCode_Desc";
				typeName = "STRING";
			};
			class timeout
			{
				displayName = "$STR_cba_modules_Timeout";
				description = "$STR_cba_modules_Timeout_Desc";
				typeName = "STRING";
				defaultValue = "[1,5,10]";
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description = "$STR_cba_modules_PatrolModuleDescription";
			sync[] = {"LocationArea_F"};
			class LocationArea_F
			{
				position = 0;
				optional = 0;
				duplicate = 1;
				synced[] = {"Anything"};
			};
		};
	};
};
class CfgFunctions
{
	class CBA
	{
		class Modules
		{
			class getPosFromString
			{
				description = "A function to get the position of an item passed as a string.";
				file = "\x\cba\addons\modules\fnc_getPosFromString.sqf";
			};
			class moduleAttack
			{
				description = "A function used to set a group to attack a position through a module.";
				file = "\x\cba\addons\modules\fnc_moduleAttack.sqf";
			};
			class moduleDefend
			{
				description = "A function used to set a group to defend a position through a module.";
				file = "\x\cba\addons\modules\fnc_moduleDefend.sqf";
			};
			class modulePatrol
			{
				description = "A function used to set a group to patrol a position through a module.";
				file = "\x\cba\addons\modules\fnc_modulePatrol.sqf";
			};
		};
	};
};
//};
