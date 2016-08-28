////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.52
//'now' is Wed Jul 13 18:00:45 2016 : 'file' last modified on Wed Jul 13 18:00:45 2016
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_settings : config.bin{
class CfgPatches
{
	class cba_settings
	{
		author = "$STR_CBA_Author";
		name = "$STR_cba_settings_component";
		url = "$STR_CBA_URL";
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CBA_common","A3_UI_F","3DEN"};
		version = "3.0.0.160713";
		authors[] = {"commy2"};
	};
};
class Extended_PreStart_EventHandlers
{
	class cba_settings
	{
		init = "if (!(productVersion select 2 <= 154)) then {call compile preProcessFileLineNumbers '\x\cba\addons\settings\XEH_preStart.sqf'};";
	};
};
class Extended_PreInit_EventHandlers
{
	class cba_settings
	{
		init = "if (!(productVersion select 2 <= 154)) then {call compile preProcessFileLineNumbers '\x\cba\addons\settings\XEH_preInit.sqf'};";
	};
};
class Extended_PostInit_EventHandlers
{
	class cba_settings
	{
		init = "if (!(productVersion select 2 <= 154)) then {call compile preProcessFileLineNumbers '\x\cba\addons\settings\XEH_postInit.sqf'};";
	};
};
class Extended_DisplayLoad_EventHandlers
{
	class RscDisplayGameOptions
	{
		cba_settings = "if ((productVersion select 2 <= 154)|| {isNil 'cba_settings'}) then {_this call compile preProcessFileLineNumbers '\x\cba\addons\settings\gui_initDisplay_disabled.sqf'} else {_this call compile preProcessFileLineNumbers '\x\cba\addons\settings\gui_initDisplay.sqf'};";
	};
	class Display3DEN
	{
		cba_settings = "if (!(productVersion select 2 <= 154)) then {_this call compile preProcessFileLineNumbers '\x\cba\addons\settings\init3DEN.sqf'};";
	};
};
class CfgFunctions
{
	class CBA
	{
		class Settings{};
	};
};
class Cfg3DEN
{
	class Mission
	{
		class Scenario
		{
			class AttributeCategories
			{
				class Presentation
				{
					class Attributes
					{
						class BriefingName;
						class Author;
						class cba_settings_hash
						{
							property = "cba_settings_hash";
							value = 0;
							control = "Default";
							displayName = "";
							tooltip = "";
							defaultValue = "([] call CBA_fnc_hashCreate)";
							expression = "";
							wikiType = "[[Array]]";
						};
					};
				};
			};
		};
	};
};
class ctrlMenuStrip;
class Display3DEN
{
	class Controls
	{
		class MenuStrip: ctrlMenuStrip
		{
			class Items
			{
				class Options
				{
					items[] += {"cba_settings"};
				};
				class cba_settings
				{
					text = "$STR_cba_settings_shortcut";
					action = "findDisplay 313 call compile preProcessFileLineNumbers '\x\cba\addons\settings\openSettingsMenu.sqf'";
					data = "cba_settings";
					shortcuts[] = {"512+2048+0x1F"};
				};
			};
		};
	};
};
class RscControlsGroup
{
	class VScrollbar;
	class HScrollbar;
};
class RscTitle;
class RscText;
class CBA_Rsc_SettingText: RscText
{
	style = 1;
};
class RscEdit;
class RscCombo;
class RscListBox;
class RscButtonMenu;
class RscXSliderH;
class CBA_Rsc_Slider_R: RscXSliderH
{
	color[] = {1,0,0,0.6};
	colorActive[] = {1,0,0,1};
	colorDisable[] = {1,0,0,0.4};
};
class CBA_Rsc_Slider_G: RscXSliderH
{
	color[] = {0,1,0,0.6};
	colorActive[] = {0,1,0,1};
	colorDisable[] = {0,1,0,0.4};
};
class CBA_Rsc_Slider_B: RscXSliderH
{
	color[] = {0,0,1,0.6};
	colorActive[] = {0,0,1,1};
	colorDisable[] = {0,0,1,0.4};
};
class cba_settings_OptionsGroup: RscControlsGroup
{
	class HScrollbar: HScrollbar
	{
		height = 0;
	};
	x = "((0.5) * (((safezoneW / safezoneH) min 1.2)/ 40))";
	y = "((3.5) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
	w = "((35) * (((safezoneW / safezoneH) min 1.2)/ 40))";
	h = "((13.8) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
	lineHeight = "((1) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
	class controls{};
};
class cba_settings_AddonsList: RscCombo
{
	linespacing = 1;
	text = "";
	wholeHeight = "((12) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
	x = "((4.5) * (((safezoneW / safezoneH) min 1.2)/ 40))";
	y = "((1) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
	w = "((21) * (((safezoneW / safezoneH) min 1.2)/ 40))";
	h = "((1) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
};
class RscDisplayGameOptions
{
	class controls
	{
		class CBA_ButtonConfigureAddons: RscButtonMenu
		{
			idc = 4302;
			text = "$STR_cba_settings_configureAddons";
			x = "((20.15) * (((safezoneW / safezoneH) min 1.2)/ 40)+ ([(safezoneX), (safezoneX + (safezoneW - ((safezoneW / safezoneH) min 1.2))/2)] select (productVersion select 2 >= 162)))";
			y = "((23) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25)+ ([(safezoneY + safezoneH - (((safezoneW / safezoneH) min 1.2)/ 1.2)), (safezoneY + (safezoneH - (((safezoneW / safezoneH) min 1.2)/ 1.2))/2)] select (productVersion select 2 >= 162)))";
			w = "((12.5) * (((safezoneW / safezoneH) min 1.2)/ 40))";
			h = "((1) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
		};
		class CBA_ButtonClient: RscButtonMenu
		{
			idc = 9000;
			text = "$STR_cba_settings_ButtonClient";
			tooltip = "$STR_cba_settings_ButtonClient_tooltip";
			x = "((1) * (((safezoneW / safezoneH) min 1.2)/ 40)+ ([(safezoneX), (safezoneX + (safezoneW - ((safezoneW / safezoneH) min 1.2))/2)] select (productVersion select 2 >= 162)))";
			y = "((2.1) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25)+ ([(safezoneY + safezoneH - (((safezoneW / safezoneH) min 1.2)/ 1.2)), (safezoneY + (safezoneH - (((safezoneW / safezoneH) min 1.2)/ 1.2))/2)] select (productVersion select 2 >= 162)))";
			w = "((8) * (((safezoneW / safezoneH) min 1.2)/ 40))";
			h = "((1) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
		};
		class CBA_ButtonServer: CBA_ButtonClient
		{
			idc = 9001;
			text = "$STR_cba_settings_ButtonServer";
			tooltip = "$STR_cba_settings_ButtonServer_tooltip";
			x = "((9) * (((safezoneW / safezoneH) min 1.2)/ 40)+ ([(safezoneX), (safezoneX + (safezoneW - ((safezoneW / safezoneH) min 1.2))/2)] select (productVersion select 2 >= 162)))";
		};
		class CBA_ButtonMission: CBA_ButtonClient
		{
			idc = 9002;
			text = "$STR_cba_settings_ButtonMission";
			tooltip = "$STR_cba_settings_ButtonMission_tooltip";
			x = "((17) * (((safezoneW / safezoneH) min 1.2)/ 40)+ ([(safezoneX), (safezoneX + (safezoneW - ((safezoneW / safezoneH) min 1.2))/2)] select (productVersion select 2 >= 162)))";
		};
		class CBA_AddonsGroup: RscControlsGroup
		{
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			idc = 4301;
			enableDisplay = 0;
			x = "((1) * (((safezoneW / safezoneH) min 1.2)/ 40)+ ([(safezoneX), (safezoneX + (safezoneW - ((safezoneW / safezoneH) min 1.2))/2)] select (productVersion select 2 >= 162)))";
			y = "((3.1) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25)+ ([(safezoneY + safezoneH - (((safezoneW / safezoneH) min 1.2)/ 1.2)), (safezoneY + (safezoneH - (((safezoneW / safezoneH) min 1.2)/ 1.2))/2)] select (productVersion select 2 >= 162)))";
			w = "((38) * (((safezoneW / safezoneH) min 1.2)/ 40))";
			h = "((17.3) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
			class controls
			{
				class CBA_AddonsEmptyBackground: RscText
				{
					idc = -1;
					type = 0;
					text = "";
					colorBackground[] = {0,0,0,0.4};
					x = "((0.5) * (((safezoneW / safezoneH) min 1.2)/ 40))";
					y = "((3.5) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
					w = "((35) * (((safezoneW / safezoneH) min 1.2)/ 40))";
					h = "((13.8) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
				};
				class CBA_AddonsCA_ControlsPageText: RscText
				{
					style = 1;
					idc = 2002;
					text = "Addon:";
					x = "((0.5) * (((safezoneW / safezoneH) min 1.2)/ 40))";
					y = "((1) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
					w = "((4) * (((safezoneW / safezoneH) min 1.2)/ 40))";
					h = "((1) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
					sizeEx = "((1) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
				};
				class CBA_ForceSettingText: RscText
				{
					style = 1;
					idc = 327;
					text = "";
					tooltip = "$STR_cba_settings_force_tooltip";
					x = "((25) * (((safezoneW / safezoneH) min 1.2)/ 40))";
					y = "((2.5) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
					w = "((10) * (((safezoneW / safezoneH) min 1.2)/ 40))";
					h = "((1) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
				};
			};
		};
	};
};
class CBA_ButtonConfigureSettings_base: RscButtonMenu
{
	onButtonClick = "ctrlParent (_this select 0) call compile preProcessFileLineNumbers '\x\cba\addons\settings\openSettingsMenu.sqf'";
	idc = 7000;
	text = "$STR_cba_settings_configureAddons";
	x = "((11.1) * (((safezoneW / safezoneH) min 1.2)/ 40)+ (safezoneX))";
	y = "((23) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25)+ (safezoneY + safezoneH - (((safezoneW / safezoneH) min 1.2)/ 1.2)))";
	w = "((10) * (((safezoneW / safezoneH) min 1.2)/ 40))";
	h = "((1) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
};
class RscDisplayMainMap;
class RscDisplayGetReady: RscDisplayMainMap
{
	class controls
	{
		class CBA_ButtonConfigureSettings: CBA_ButtonConfigureSettings_base{};
	};
};
class RscDisplayServerGetReady: RscDisplayGetReady
{
	class controls
	{
		class CBA_ButtonConfigureSettings: CBA_ButtonConfigureSettings_base{};
	};
};
class RscDisplayClientGetReady: RscDisplayGetReady
{
	class controls
	{
		class CBA_ButtonConfigureSettings: CBA_ButtonConfigureSettings_base{};
	};
};
class cba_settings_presets
{
	idd = -1;
	movingEnable = 1;
	enableSimulation = 0;
	class controls
	{
		class CBA_Presets: RscControlsGroup
		{
			idc = 8000;
			x = "((10) * (((safezoneW / safezoneH) min 1.2)/ 40)+ (safezoneX + (safezoneW - ((safezoneW / safezoneH) min 1.2))/2))";
			y = "((0.9) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25)+ (safezoneY + (safezoneH - (((safezoneW / safezoneH) min 1.2)/ 1.2))/2))";
			w = "((20) * (((safezoneW / safezoneH) min 1.2)/ 40))";
			h = "((22.2) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
			class controls
			{
				class CBA_Title: RscTitle
				{
					style = 0;
					colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
					idc = 8001;
					text = "";
					x = "((0) * (((safezoneW / safezoneH) min 1.2)/ 40))";
					y = "((0) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
					w = "((20) * (((safezoneW / safezoneH) min 1.2)/ 40))";
					h = "((1) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
				};
				class CBA_Background: RscText
				{
					idc = -1;
					colorBackground[] = {0,0,0,0.8};
					x = "((0) * (((safezoneW / safezoneH) min 1.2)/ 40))";
					y = "((1.1) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
					w = "((20) * (((safezoneW / safezoneH) min 1.2)/ 40))";
					h = "((20) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
				};
				class CBA_TextName: RscText
				{
					style = 1;
					idc = 8002;
					text = "$STR_DISP_INTEL_NAME";
					x = "((0.5) * (((safezoneW / safezoneH) min 1.2)/ 40))";
					y = "((19.6) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
					w = "((5.5) * (((safezoneW / safezoneH) min 1.2)/ 40))";
					h = "((1) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
					sizeEx = "((0.8) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
				};
				class CBA_EditName: RscEdit
				{
					idc = 8003;
					x = "((6) * (((safezoneW / safezoneH) min 1.2)/ 40))";
					y = "((19.6) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
					w = "((13.5) * (((safezoneW / safezoneH) min 1.2)/ 40))";
					h = "((1) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
					sizeEx = "((0.8) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
				};
				class CBA_ValueName: RscListBox
				{
					idc = 8004;
					colorBackground[] = {1,1,1,0.2};
					x = "((0.5) * (((safezoneW / safezoneH) min 1.2)/ 40))";
					y = "((1.6) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
					w = "((19) * (((safezoneW / safezoneH) min 1.2)/ 40))";
					h = "((17.5) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
					sizeEx = "((0.8) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
				};
				class CBA_ButtonOK: RscButtonMenu
				{
					idc = 8005;
					text = "$STR_DISP_OK";
					x = "((15) * (((safezoneW / safezoneH) min 1.2)/ 40))";
					y = "((21.2) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
					w = "((5) * (((safezoneW / safezoneH) min 1.2)/ 40))";
					h = "((1) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
				};
				class CBA_ButtonCancel: RscButtonMenu
				{
					idc = 8006;
					text = "$STR_DISP_CANCEL";
					x = "((0) * (((safezoneW / safezoneH) min 1.2)/ 40))";
					y = "((21.2) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
					w = "((5) * (((safezoneW / safezoneH) min 1.2)/ 40))";
					h = "((1) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
				};
				class CBA_ButtonDelete: RscButtonMenu
				{
					idc = 8007;
					text = "$STR_DISP_DELETE";
					x = "((9.9) * (((safezoneW / safezoneH) min 1.2)/ 40))";
					y = "((21.2) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
					w = "((5) * (((safezoneW / safezoneH) min 1.2)/ 40))";
					h = "((1) * ((((safezoneW / safezoneH) min 1.2)/ 1.2)/ 25))";
				};
			};
		};
	};
};
//};
