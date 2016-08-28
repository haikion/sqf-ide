////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.52
//'now' is Wed Jul 13 18:01:17 2016 : 'file' last modified on Wed Jul 13 18:01:17 2016
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_ui : config.bin{
class CfgPatches
{
	class cba_ui
	{
		author = "$STR_CBA_Author";
		name = "$STR_cba_ui_component";
		url = "$STR_CBA_URL";
		units[] = {};
		requiredVersion = 1;
		requiredAddons[] = {"CBA_common","CBA_arrays","A3_Ui_F"};
		version = "3.0.0.160713";
		authors[] = {"Dr Eyeball"};
		weapons[] = {};
	};
};
class CfgFunctions
{
	class CBA
	{
		class UI
		{
			class flexiMenu_Add
			{
				description = "Add a type-based menu source. Result: TBA (WIP)";
				file = "\x\cba\addons\ui\flexiMenu\fnc_add.sqf";
			};
			class flexiMenu_Remove
			{
				description = "Remove a type-based menu source. Result: TBA (WIP)";
				file = "\x\cba\addons\ui\flexiMenu\fnc_remove.sqf";
			};
			class flexiMenu_setObjectMenuSource
			{
				description = "Set an object's menu source (variable). Result: TBA (WIP)";
				file = "\x\cba\addons\ui\flexiMenu\fnc_setObjectMenuSource.sqf";
			};
			class flexiMenu_openMenuByDef
			{
				description = "Open a previously defined menu by passing the exact parameters used with cba_fnc_fleximenu_add. Result: TBA (WIP)";
				file = "\x\cba\addons\ui\flexiMenu\fnc_openMenuByDef.sqf";
			};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class cba_ui
	{
		clientInit = "call compile preProcessFileLineNumbers '\x\cba\addons\ui\XEH_preClientInit.sqf'";
	};
};
class RscText;
class RscShortcutButton;
class _flexiMenu_RscShortcutButton: RscShortcutButton
{
	class HitZone
	{
		left = 0.002;
		top = 0.003;
		right = 0.002;
		bottom = 0.003;
	};
	class ShortcutPos
	{
		left = -0.006;
		top = -0.007;
		w = 0.0392157;
		h = "2*(safeZoneH/36)";
	};
	class TextPos
	{
		left = 0.01;
		top = 0.002;
		right = 0.01;
		bottom = 0.002;
	};
};
class CBA_flexiMenu_rscRose
{
	idd = -1;
	movingEnable = 0;
	onLoad = "with uiNamespace do {cba_ui_display= _this select 0};";
	onUnload = "with uiNamespace do {cba_ui_display= displayNull};";
	class controlsBackground{};
	class objects{};
	flexiMenu_primaryMenuControlWidth = "0.21*safeZoneW";
	flexiMenu_subMenuControlWidth = "0.21*safeZoneW";
	flexiMenu_subMenuCaptionWidth = 0.4;
	flexiMenu_hotKeyColor = "#f07EB27E";
	class listButton: _flexiMenu_RscShortcutButton
	{
		x = 0.5;
		y = 0.5;
		w = 0;
		h = "0.0375*safeZoneH";
		sizeEx = "0.033*safeZoneH";
		size = "0.033*safeZoneH*0.75";
		color[] = {"138/256","146/256","105/256",1};
		color2[] = {1,1,1,0.8};
		colorBackground[] = {1,1,1,1};
		colorbackground2[] = {1,1,1,1};
		colorDisabled[] = {1,1,1,0.25};
		class TextPos
		{
			left = 0.02;
			top = 0.005;
			right = 0.02;
			bottom = 0.005;
		};
		class Attributes
		{
			font = "PuristaMedium";
			color = "#E5E5E5";
			align = "left";
			shadow = "true";
		};
		animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\buttonList\normal.paa";
		animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\buttonList\disabled.paa";
		animTextureOver = "\x\cba\addons\ui\flexiMenu\data\buttonList\over.paa";
		animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\buttonList\focused.paa";
		animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\buttonList\down.paa";
		animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\buttonList\default.paa";
		animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\buttonList\normal.paa";
	};
	class button: _flexiMenu_RscShortcutButton
	{
		w = 0;
		h = "(0.15*safeZoneH/5.5)";
		sizeEx = "(0.15*safeZoneH/5.5)";
		size = "(0.15*safeZoneH/5.5)*0.85";
		color[] = {"138/256","146/256","105/256",1};
		color2[] = {1,1,1,0.8};
		colorBackground[] = {1,1,1,1};
		colorbackground2[] = {1,1,1,1};
		colorDisabled[] = {1,1,1,0.25};
		class Attributes
		{
			font = "PuristaMedium";
			color = "#E5E5E5";
			align = "center";
			shadow = "true";
		};
	};
	class controls
	{
		class caption: rscText
		{
			idc = 230;
			x = "((safeZoneX+safeZoneW/2)-(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(-0.025*safeZoneW))-0.21*safeZoneW-(-0.00*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)-(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))-(0.15*safeZoneH/5.5)-((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)-(0.15*safeZoneH/5.5)*0.85";
			w = "0.50*safeZoneW";
			h = "(0.15*safeZoneH/5.5)*0.85";
			sizeEx = "(0.15*safeZoneH/5.5)*0.85";
			colorText[] = {"138/256","146/256","105/256",1};
			text = "";
		};
		class button01: button
		{
			idc = "240+0";
			x = "(safeZoneX+safeZoneW/2)-0.15*safeZoneW*3/4/2+0.011*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)-0.15*safeZoneH/2";
			w = "0.15*safeZoneW*3/4";
			h = "0.15*safeZoneH";
			sizeEx = "0.15*safeZoneH";
			class TextPos
			{
				left = "-0.011*safeZoneW*2";
				top = "0.15*safeZoneH/2-(0.15*safeZoneH/5.5)/2";
				right = 0;
				bottom = 0.0;
			};
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_circle.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_circle.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_circle.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\focused_circle.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_circle.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_circle.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_circle.paa";
		};
		class button02: button
		{
			idc = "240+(02-1)";
			x = "(safeZoneX+safeZoneW/2)-0.21*safeZoneW/2";
			y = "(safeZoneY+safeZoneH/2)-(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))-(0.15*safeZoneH/5.5)";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_top.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_top.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_top.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\focused_top.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_top.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_top.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_top.paa";
		};
		class button03: button
		{
			idc = "240+(03-1)";
			x = "(safeZoneX+safeZoneW/2)-0.21*safeZoneW/2";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_bottom.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_bottom.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_bottom.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\focused_bottom.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_bottom.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_bottom.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_bottom.paa";
		};
		class button04: button
		{
			idc = "240+(04-1)";
			x = "((safeZoneX+safeZoneW/2)-(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(-0.025*safeZoneW))-0.21*safeZoneW-(-0.00*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)-((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2-(0.15*safeZoneH/5.5)-((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)-(0.15*safeZoneH/5.5)";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L01.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_L01.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_L01.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\focused_L01.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_L01.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L01.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L01.paa";
		};
		class button05: button
		{
			idc = "240+(05-1)";
			x = "((safeZoneX+safeZoneW/2)-(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(-0.015*safeZoneW))-0.21*safeZoneW-(-0.00*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)-((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2-(0.15*safeZoneH/5.5)";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L02.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_L02.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_L02.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\focused_L02.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_L02.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L02.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L02.paa";
		};
		class button06: button
		{
			idc = "240+(06-1)";
			x = "((safeZoneX+safeZoneW/2)-(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(-0.015*safeZoneW))-0.21*safeZoneW-(-0.00*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L03.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_L03.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_L03.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\focused_L03.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_L03.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L03.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L03.paa";
		};
		class button07: button
		{
			idc = "240+(07-1)";
			x = "((safeZoneX+safeZoneW/2)-(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(-0.025*safeZoneW))-0.21*safeZoneW-(-0.00*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L04.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_L04.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_L04.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\focused_L04.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_L04.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L04.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L04.paa";
		};
		class button08: button
		{
			idc = "240+(08-1)";
			x = "((safeZoneX+safeZoneW/2)+(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(-0.025*safeZoneW))+(-0.00*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)-((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2-(0.15*safeZoneH/5.5)-((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)-(0.15*safeZoneH/5.5)";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R01.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_R01.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_R01.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\focused_R01.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_R01.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R01.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R01.paa";
		};
		class button09: button
		{
			idc = "240+(09-1)";
			x = "((safeZoneX+safeZoneW/2)+(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(-0.015*safeZoneW))+(-0.00*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)-((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2-(0.15*safeZoneH/5.5)";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R02.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_R02.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_R02.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\focused_R02.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_R02.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R02.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R02.paa";
		};
		class button10: button
		{
			idc = "240+(10-1)";
			x = "((safeZoneX+safeZoneW/2)+(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(-0.015*safeZoneW))+(-0.00*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R03.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_R03.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_R03.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\focused_R03.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_R03.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R03.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R03.paa";
		};
		class button11: button
		{
			idc = "240+(11-1)";
			x = "((safeZoneX+safeZoneW/2)+(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(-0.025*safeZoneW))+(-0.00*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R04.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_R04.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_R04.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\focused_R04.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_R04.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R04.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R04.paa";
		};
		class caption2: caption
		{
			idc = 231;
			x = "(safeZoneX+safeZoneW/2)-(0.21*safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+0*0.033*safeZoneH";
			w = 0;
		};
		class listButton00: listButton
		{
			idc = "340+00";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((00 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(00 mod 10))*0.033*safeZoneH";
		};
		class listButton01: listButton
		{
			idc = "340+01";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((01 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(01 mod 10))*0.033*safeZoneH";
		};
		class listButton02: listButton
		{
			idc = "340+02";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((02 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(02 mod 10))*0.033*safeZoneH";
		};
		class listButton03: listButton
		{
			idc = "340+03";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((03 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(03 mod 10))*0.033*safeZoneH";
		};
		class listButton04: listButton
		{
			idc = "340+04";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((04 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(04 mod 10))*0.033*safeZoneH";
		};
		class listButton05: listButton
		{
			idc = "340+05";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((05 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(05 mod 10))*0.033*safeZoneH";
		};
		class listButton06: listButton
		{
			idc = "340+06";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((06 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(06 mod 10))*0.033*safeZoneH";
		};
		class listButton07: listButton
		{
			idc = "340+07";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((07 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(07 mod 10))*0.033*safeZoneH";
		};
		class listButton08: listButton
		{
			idc = "340+08";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((08 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(08 mod 10))*0.033*safeZoneH";
		};
		class listButton09: listButton
		{
			idc = "340+09";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((09 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(09 mod 10))*0.033*safeZoneH";
		};
		class listButton10: listButton
		{
			idc = "340+10";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((10 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(10 mod 10))*0.033*safeZoneH";
		};
		class listButton11: listButton
		{
			idc = "340+11";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((11 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(11 mod 10))*0.033*safeZoneH";
		};
		class listButton12: listButton
		{
			idc = "340+12";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((12 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(12 mod 10))*0.033*safeZoneH";
		};
		class listButton13: listButton
		{
			idc = "340+13";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((13 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(13 mod 10))*0.033*safeZoneH";
		};
		class listButton14: listButton
		{
			idc = "340+14";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((14 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(14 mod 10))*0.033*safeZoneH";
		};
		class listButton15: listButton
		{
			idc = "340+15";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((15 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(15 mod 10))*0.033*safeZoneH";
		};
		class listButton16: listButton
		{
			idc = "340+16";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((16 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(16 mod 10))*0.033*safeZoneH";
		};
		class listButton17: listButton
		{
			idc = "340+17";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((17 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(17 mod 10))*0.033*safeZoneH";
		};
		class listButton18: listButton
		{
			idc = "340+18";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((18 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(18 mod 10))*0.033*safeZoneH";
		};
		class listButton19: listButton
		{
			idc = "340+19";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((19 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(19 mod 10))*0.033*safeZoneH";
		};
		class listButton20: listButton
		{
			idc = "340+20";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((20 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(20 mod 10))*0.033*safeZoneH";
		};
		class listButton21: listButton
		{
			idc = "340+21";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((21 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(21 mod 10))*0.033*safeZoneH";
		};
		class listButton22: listButton
		{
			idc = "340+22";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((22 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(22 mod 10))*0.033*safeZoneH";
		};
		class listButton23: listButton
		{
			idc = "340+23";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((23 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(23 mod 10))*0.033*safeZoneH";
		};
		class listButton24: listButton
		{
			idc = "340+24";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((24 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(24 mod 10))*0.033*safeZoneH";
		};
		class listButton25: listButton
		{
			idc = "340+25";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((25 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(25 mod 10))*0.033*safeZoneH";
		};
		class listButton26: listButton
		{
			idc = "340+26";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((26 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(26 mod 10))*0.033*safeZoneH";
		};
		class listButton27: listButton
		{
			idc = "340+27";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((27 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(27 mod 10))*0.033*safeZoneH";
		};
		class listButton28: listButton
		{
			idc = "340+28";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((28 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(28 mod 10))*0.033*safeZoneH";
		};
		class listButton29: listButton
		{
			idc = "340+29";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((29 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(29 mod 10))*0.033*safeZoneH";
		};
	};
};
class CBA_flexiMenu_rscArma2
{
	idd = -1;
	movingEnable = 0;
	onLoad = "with uiNamespace do {cba_ui_display= _this select 0};";
	onUnload = "with uiNamespace do {cba_ui_display= displayNull};";
	class controlsBackground{};
	class objects{};
	flexiMenu_primaryMenuControlWidth = "0.21*safeZoneW";
	flexiMenu_subMenuControlWidth = "0.21*safeZoneW";
	flexiMenu_subMenuCaptionWidth = 0.4;
	class listButton: _flexiMenu_RscShortcutButton
	{
		x = 0.5;
		y = 0.5;
		w = 0;
		h = "0.0375*safeZoneH";
		sizeEx = "0.033*safeZoneH";
		size = "0.033*safeZoneH*0.75";
		color[] = {"138/256","146/256","105/256",1};
		color2[] = {1,1,1,0.8};
		colorBackground[] = {1,1,1,1};
		colorbackground2[] = {1,1,1,1};
		colorDisabled[] = {1,1,1,0.25};
		class TextPos
		{
			left = 0.02;
			top = 0.005;
			right = 0.02;
			bottom = 0.005;
		};
		class Attributes
		{
			font = "PuristaMedium";
			color = "#E5E5E5";
			align = "left";
			shadow = "true";
		};
		animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\buttonList\normal.paa";
		animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\buttonList\disabled.paa";
		animTextureOver = "\x\cba\addons\ui\flexiMenu\data\buttonList\over.paa";
		animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\buttonList\focused.paa";
		animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\buttonList\down.paa";
		animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\buttonList\default.paa";
		animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\buttonList\normal.paa";
	};
	class button: _flexiMenu_RscShortcutButton
	{
		w = 0;
		h = "(0.15*safeZoneH/5.5)*1.52";
		sizeEx = "(0.15*safeZoneH/5.5)";
		size = "(0.15*safeZoneH/5.5)*0.85";
		color[] = {"138/256","146/256","105/256",1};
		color2[] = {1,1,1,0.8};
		colorBackground[] = {1,1,1,1};
		colorbackground2[] = {1,1,1,1};
		colorDisabled[] = {1,1,1,0.25};
		class ShortcutPos
		{
			left = 0;
			top = 0;
			w = 0.1;
			h = 0.1;
		};
		class Attributes
		{
			font = "PuristaMedium";
			color = "#E5E5E5";
			align = "center";
			shadow = "true";
		};
	};
	class controls
	{
		class caption: rscText
		{
			idc = 230;
			x = "((safeZoneX+safeZoneW/2)-(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(0.01*safeZoneW))-0.21*safeZoneW-(-0.015*safeZoneW-0.01*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)-(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))-(0.15*safeZoneH/5.5)-((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)-(0.15*safeZoneH/5.5)*0.85";
			w = "0.50*safeZoneW";
			h = "(0.15*safeZoneH/5.5)*0.85";
			sizeEx = "(0.15*safeZoneH/5.5)*0.85";
			colorText[] = {"138/256","146/256","105/256",1};
			text = "";
		};
		class button01: button
		{
			idc = "240+0";
			x = "(safeZoneX+safeZoneW/2)-0.15*safeZoneW*3/4/2+0.011*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)-0.15*safeZoneH/2";
			w = "0.15*safeZoneW*3/4";
			h = "0.15*safeZoneH";
			sizeEx = "0.15*safeZoneH";
			class TextPos
			{
				left = "-0.011*safeZoneW*2";
				top = "0.15*safeZoneH/2-(0.15*safeZoneH/5.5)/2";
				right = 0;
				bottom = 0.0;
			};
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\arma2\mid_button_normal.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\arma2\mid_button_disabled.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\arma2\mid_button_over.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\arma2\mid_button_focus.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\arma2\mid_button_down.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\arma2\mid_button_normal.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\arma2\mid_button_normal.paa";
		};
		class button02: button
		{
			idc = "240+1";
			x = "(safeZoneX+safeZoneW/2)-0.21*safeZoneW/2";
			y = "(safeZoneY+safeZoneH/2)-(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))-(0.15*safeZoneH/5.5)";
			animTextureNormal = "\a3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\normal_ca.paa";
			animTextureDisabled = "\a3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\disabled_ca.paa";
			animTextureOver = "\a3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\over_ca.paa";
			animTextureFocused = "\a3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\focus_ca.paa";
			animTexturePressed = "\a3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\down_ca.paa";
			animTextureDefault = "\a3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\normal_ca.paa";
			animTextureNoShortcut = "\a3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\normal_ca.paa";
		};
		class button03: button02
		{
			idc = "240+2";
			x = "(safeZoneX+safeZoneW/2)-0.21*safeZoneW/2";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))";
		};
		class button04: button02
		{
			idc = "240+3";
			x = "((safeZoneX+safeZoneW/2)-(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(0.01*safeZoneW))-0.21*safeZoneW-(-0.015*safeZoneW-0.01*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)-((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2-(0.15*safeZoneH/5.5)-((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)-(0.15*safeZoneH/5.5)";
		};
		class button05: button02
		{
			idc = "240+4";
			x = "((safeZoneX+safeZoneW/2)-(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(0.01*safeZoneW))-0.21*safeZoneW-(-0.015*safeZoneW-0.01*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)-((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2-(0.15*safeZoneH/5.5)";
		};
		class button06: button02
		{
			idc = "240+5";
			x = "((safeZoneX+safeZoneW/2)-(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(0.01*safeZoneW))-0.21*safeZoneW-(-0.015*safeZoneW-0.01*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2";
		};
		class button07: button02
		{
			idc = "240+6";
			x = "((safeZoneX+safeZoneW/2)-(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(0.01*safeZoneW))-0.21*safeZoneW-(-0.015*safeZoneW-0.01*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)";
		};
		class button08: button02
		{
			idc = "240+7";
			x = "((safeZoneX+safeZoneW/2)+(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(0.01*safeZoneW))+(-0.015*safeZoneW-0.01*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)-((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2-(0.15*safeZoneH/5.5)-((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)-(0.15*safeZoneH/5.5)";
		};
		class button09: button02
		{
			idc = "240+8";
			x = "((safeZoneX+safeZoneW/2)+(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(0.01*safeZoneW))+(-0.015*safeZoneW-0.01*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)-((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2-(0.15*safeZoneH/5.5)";
		};
		class button10: button02
		{
			idc = "240+9";
			x = "((safeZoneX+safeZoneW/2)+(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(0.01*safeZoneW))+(-0.015*safeZoneW-0.01*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2";
		};
		class button11: button02
		{
			idc = "240+10";
			x = "((safeZoneX+safeZoneW/2)+(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(0.01*safeZoneW))+(-0.015*safeZoneW-0.01*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)";
		};
		class caption2: caption
		{
			idc = 231;
			x = "(safeZoneX+safeZoneW/2)-(0.21*safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+0*0.033*safeZoneH";
			w = 0;
		};
		class listButton00: listButton
		{
			idc = "340+00";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((00 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(00 mod 10))*0.033*safeZoneH";
		};
		class listButton01: listButton
		{
			idc = "340+01";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((01 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(01 mod 10))*0.033*safeZoneH";
		};
		class listButton02: listButton
		{
			idc = "340+02";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((02 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(02 mod 10))*0.033*safeZoneH";
		};
		class listButton03: listButton
		{
			idc = "340+03";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((03 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(03 mod 10))*0.033*safeZoneH";
		};
		class listButton04: listButton
		{
			idc = "340+04";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((04 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(04 mod 10))*0.033*safeZoneH";
		};
		class listButton05: listButton
		{
			idc = "340+05";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((05 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(05 mod 10))*0.033*safeZoneH";
		};
		class listButton06: listButton
		{
			idc = "340+06";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((06 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(06 mod 10))*0.033*safeZoneH";
		};
		class listButton07: listButton
		{
			idc = "340+07";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((07 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(07 mod 10))*0.033*safeZoneH";
		};
		class listButton08: listButton
		{
			idc = "340+08";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((08 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(08 mod 10))*0.033*safeZoneH";
		};
		class listButton09: listButton
		{
			idc = "340+09";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((09 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(09 mod 10))*0.033*safeZoneH";
		};
		class listButton10: listButton
		{
			idc = "340+10";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((10 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(10 mod 10))*0.033*safeZoneH";
		};
		class listButton11: listButton
		{
			idc = "340+11";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((11 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(11 mod 10))*0.033*safeZoneH";
		};
		class listButton12: listButton
		{
			idc = "340+12";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((12 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(12 mod 10))*0.033*safeZoneH";
		};
		class listButton13: listButton
		{
			idc = "340+13";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((13 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(13 mod 10))*0.033*safeZoneH";
		};
		class listButton14: listButton
		{
			idc = "340+14";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((14 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(14 mod 10))*0.033*safeZoneH";
		};
		class listButton15: listButton
		{
			idc = "340+15";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((15 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(15 mod 10))*0.033*safeZoneH";
		};
		class listButton16: listButton
		{
			idc = "340+16";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((16 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(16 mod 10))*0.033*safeZoneH";
		};
		class listButton17: listButton
		{
			idc = "340+17";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((17 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(17 mod 10))*0.033*safeZoneH";
		};
		class listButton18: listButton
		{
			idc = "340+18";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((18 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(18 mod 10))*0.033*safeZoneH";
		};
		class listButton19: listButton
		{
			idc = "340+19";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((19 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(19 mod 10))*0.033*safeZoneH";
		};
		class listButton20: listButton
		{
			idc = "340+20";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((20 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(20 mod 10))*0.033*safeZoneH";
		};
		class listButton21: listButton
		{
			idc = "340+21";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((21 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(21 mod 10))*0.033*safeZoneH";
		};
		class listButton22: listButton
		{
			idc = "340+22";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((22 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(22 mod 10))*0.033*safeZoneH";
		};
		class listButton23: listButton
		{
			idc = "340+23";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((23 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(23 mod 10))*0.033*safeZoneH";
		};
		class listButton24: listButton
		{
			idc = "340+24";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((24 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(24 mod 10))*0.033*safeZoneH";
		};
		class listButton25: listButton
		{
			idc = "340+25";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((25 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(25 mod 10))*0.033*safeZoneH";
		};
		class listButton26: listButton
		{
			idc = "340+26";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((26 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(26 mod 10))*0.033*safeZoneH";
		};
		class listButton27: listButton
		{
			idc = "340+27";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((27 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(27 mod 10))*0.033*safeZoneH";
		};
		class listButton28: listButton
		{
			idc = "340+28";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((28 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(28 mod 10))*0.033*safeZoneH";
		};
		class listButton29: listButton
		{
			idc = "340+29";
			x = "(safeZoneX+safeZoneW/2)- ((0.21*safeZoneW+0.01*safeZoneW) * 1.5) + floor(((29 + 10) / 10) mod 3)*(0.21*safeZoneW+0.01*safeZoneW)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+(29 mod 10))*0.033*safeZoneH";
		};
	};
};
class CBA_flexiMenu_rscButtonList
{
	idd = -1;
	movingEnable = 0;
	onLoad = "with uiNamespace do {cba_ui_display= _this select 0};";
	onUnload = "with uiNamespace do {cba_ui_display= displayNull};";
	class controlsBackground{};
	class objects{};
	flexiMenu_primaryMenuControlWidth = "0.21*safeZoneW";
	flexiMenu_subMenuControlWidth = "0.21*safeZoneW";
	flexiMenu_subMenuCaptionWidth = 0.4;
	class listButton: _flexiMenu_RscShortcutButton
	{
		x = 0.5;
		y = 0.5;
		w = 0;
		h = "0.033*safeZoneH";
		sizeEx = "0.033*safeZoneH";
		size = "0.033*safeZoneH*0.75";
		color[] = {"138/256","146/256","105/256",1};
		color2[] = {1,1,1,0.8};
		colorBackground[] = {1,1,1,1};
		colorbackground2[] = {1,1,1,1};
		colorDisabled[] = {1,1,1,0.25};
		class TextPos
		{
			left = 0.02;
			top = 0.005;
			right = 0.02;
			bottom = 0.005;
		};
		class Attributes
		{
			font = "PuristaMedium";
			color = "#E5E5E5";
			align = "left";
			shadow = "true";
		};
		animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\buttonList\normal.paa";
		animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\buttonList\disabled.paa";
		animTextureOver = "\x\cba\addons\ui\flexiMenu\data\buttonList\over.paa";
		animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\buttonList\focused.paa";
		animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\buttonList\down.paa";
		animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\buttonList\default.paa";
		animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\buttonList\normal.paa";
	};
	class button: _flexiMenu_RscShortcutButton
	{
		x = "(safeZoneX+safeZoneW/2)-0.21*safeZoneW";
		y = "(safeZoneY+safeZoneH/2)";
		w = 0;
		h = "0.033*safeZoneH";
		sizeEx = "0.033*safeZoneH";
		size = "0.033*safeZoneH*0.75";
		color[] = {"138/256","146/256","105/256",1};
		color2[] = {1,1,1,0.8};
		colorBackground[] = {1,1,1,1};
		colorbackground2[] = {1,1,1,1};
		colorDisabled[] = {1,1,1,0.25};
		class TextPos
		{
			left = 0.02;
			top = 0.0;
			right = 0.02;
			bottom = 0.0;
		};
		class Attributes
		{
			font = "PuristaMedium";
			color = "#E5E5E5";
			align = "left";
			shadow = "true";
		};
		animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\buttonList\normal.paa";
		animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\buttonList\disabled.paa";
		animTextureOver = "\x\cba\addons\ui\flexiMenu\data\buttonList\over.paa";
		animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\buttonList\focused.paa";
		animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\buttonList\down.paa";
		animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\buttonList\default.paa";
		animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\buttonList\normal.paa";
	};
	class controls
	{
		class caption: rscText
		{
			idc = 230;
			x = "(safeZoneX+safeZoneW/2)-0.21*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH-0.01*safeZoneH-0.033*safeZoneH*0.75";
			w = "0.50*safeZoneW";
			h = "0.033*safeZoneH*0.75";
			sizeEx = "0.033*safeZoneH*0.75";
			colorText[] = {"138/256","146/256","105/256",1};
			text = "";
		};
		class button00: button
		{
			idc = "240+00";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+00*0.033*safeZoneH";
		};
		class button01: button
		{
			idc = "240+01";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+01*0.033*safeZoneH";
		};
		class button02: button
		{
			idc = "240+02";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+02*0.033*safeZoneH";
		};
		class button03: button
		{
			idc = "240+03";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+03*0.033*safeZoneH";
		};
		class button04: button
		{
			idc = "240+04";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+04*0.033*safeZoneH";
		};
		class button05: button
		{
			idc = "240+05";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+05*0.033*safeZoneH";
		};
		class button06: button
		{
			idc = "240+06";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+06*0.033*safeZoneH";
		};
		class button07: button
		{
			idc = "240+07";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+07*0.033*safeZoneH";
		};
		class button08: button
		{
			idc = "240+08";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+08*0.033*safeZoneH";
		};
		class button09: button
		{
			idc = "240+09";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+09*0.033*safeZoneH";
		};
		class button10: button
		{
			idc = "240+10";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+10*0.033*safeZoneH";
		};
		class button11: button
		{
			idc = "240+11";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+11*0.033*safeZoneH";
		};
		class button12: button
		{
			idc = "240+12";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+12*0.033*safeZoneH";
		};
		class button13: button
		{
			idc = "240+13";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+13*0.033*safeZoneH";
		};
		class button14: button
		{
			idc = "240+14";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+14*0.033*safeZoneH";
		};
		class button15: button
		{
			idc = "240+15";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+15*0.033*safeZoneH";
		};
		class button16: button
		{
			idc = "240+16";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+16*0.033*safeZoneH";
		};
		class button17: button
		{
			idc = "240+17";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+17*0.033*safeZoneH";
		};
		class caption2: caption
		{
			idc = 231;
			x = "(safeZoneX+safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+(-1*0.033*safeZoneH)";
			w = 0;
		};
		class listButton00: listButton
		{
			idc = "340+00";
			x = "(safeZoneX+safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+00*0.033*safeZoneH";
		};
		class listButton01: listButton
		{
			idc = "340+01";
			x = "(safeZoneX+safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+01*0.033*safeZoneH";
		};
		class listButton02: listButton
		{
			idc = "340+02";
			x = "(safeZoneX+safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+02*0.033*safeZoneH";
		};
		class listButton03: listButton
		{
			idc = "340+03";
			x = "(safeZoneX+safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+03*0.033*safeZoneH";
		};
		class listButton04: listButton
		{
			idc = "340+04";
			x = "(safeZoneX+safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+04*0.033*safeZoneH";
		};
		class listButton05: listButton
		{
			idc = "340+05";
			x = "(safeZoneX+safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+05*0.033*safeZoneH";
		};
		class listButton06: listButton
		{
			idc = "340+06";
			x = "(safeZoneX+safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+06*0.033*safeZoneH";
		};
		class listButton07: listButton
		{
			idc = "340+07";
			x = "(safeZoneX+safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+07*0.033*safeZoneH";
		};
		class listButton08: listButton
		{
			idc = "340+08";
			x = "(safeZoneX+safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+08*0.033*safeZoneH";
		};
		class listButton09: listButton
		{
			idc = "340+09";
			x = "(safeZoneX+safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+09*0.033*safeZoneH";
		};
		class listButton10: listButton
		{
			idc = "340+10";
			x = "(safeZoneX+safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)-7*0.033*safeZoneH+10*0.033*safeZoneH";
		};
	};
};
class CBA_flexiMenu_rscIconRow
{
	idd = -1;
	movingEnable = 0;
	onLoad = "with uiNamespace do {cba_ui_display= _this select 0};";
	onUnload = "with uiNamespace do {cba_ui_display= displayNull};";
	class controlsBackground{};
	class objects{};
	flexiMenu_primaryMenuControlWidth = "0.04*safeZoneW";
	flexiMenu_subMenuControlWidth = "0.15*safeZoneW";
	flexiMenu_subMenuCaptionWidth = 0.4;
	class listButton: _flexiMenu_RscShortcutButton
	{
		x = 0.5;
		y = 0.5;
		w = 0;
		h = "0.033*safeZoneH";
		sizeEx = "0.033*safeZoneH";
		size = "0.033*safeZoneH*0.75";
		color[] = {"138/256","146/256","105/256",1};
		color2[] = {1,1,1,0.8};
		colorBackground[] = {1,1,1,1};
		colorbackground2[] = {1,1,1,1};
		colorDisabled[] = {1,1,1,0.25};
		class TextPos
		{
			left = 0.02;
			top = 0.005;
			right = 0.02;
			bottom = 0.005;
		};
		class Attributes
		{
			font = "PuristaMedium";
			color = "#E5E5E5";
			align = "left";
			shadow = "true";
		};
		animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\buttonList\normal.paa";
		animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\buttonList\disabled.paa";
		animTextureOver = "\x\cba\addons\ui\flexiMenu\data\buttonList\over.paa";
		animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\buttonList\focused.paa";
		animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\buttonList\down.paa";
		animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\buttonList\default.paa";
		animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\buttonList\normal.paa";
	};
	class button: _flexiMenu_RscShortcutButton
	{
		x = "(safeZoneX+safeZoneW/2)-0.04*safeZoneW";
		y = "(safeZoneY+safeZoneH/2)";
		w = 0;
		h = "0.04*safeZoneH*1.52";
		sizeEx = "0.04*safeZoneH";
		size = "0.04*safeZoneH";
		color[] = {"138/256","146/256","105/256",1};
		color2[] = {1,1,1,0.8};
		colorBackground[] = {1,1,1,1};
		colorbackground2[] = {1,1,1,1};
		colorDisabled[] = {1,1,1,0.25};
		class TextPos
		{
			left = 0.0055;
			top = 0.009;
			right = 0.0;
			bottom = 0.0;
		};
		class Attributes
		{
			font = "PuristaMedium";
			color = "#E5E5E5";
			align = "center";
			shadow = "true";
		};
		animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\arma2\mid_button_normal.paa";
		animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\arma2\mid_button_disabled.paa";
		animTextureOver = "\x\cba\addons\ui\flexiMenu\data\arma2\mid_button_over.paa";
		animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\arma2\mid_button_focus.paa";
		animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\arma2\mid_button_down.paa";
		animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\arma2\mid_button_normal.paa";
		animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\arma2\mid_button_normal.paa";
	};
	class controls
	{
		class caption: rscText
		{
			idc = 230;
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)-0.01*safeZoneH-0.033*safeZoneH*0.75";
			w = "0.50*safeZoneW";
			h = "0.033*safeZoneH*0.75";
			sizeEx = "0.033*safeZoneH*0.75";
			colorText[] = {"138/256","146/256","105/256",1};
			text = "";
		};
		class button00: button
		{
			idc = "240+00";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(00 mod 5)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+floor(00 / 5)*(0.01*safeZoneH+0.04*safeZoneH*1.52)";
		};
		class button01: button
		{
			idc = "240+01";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(01 mod 5)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+floor(01 / 5)*(0.01*safeZoneH+0.04*safeZoneH*1.52)";
		};
		class button02: button
		{
			idc = "240+02";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(02 mod 5)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+floor(02 / 5)*(0.01*safeZoneH+0.04*safeZoneH*1.52)";
		};
		class button03: button
		{
			idc = "240+03";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(03 mod 5)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+floor(03 / 5)*(0.01*safeZoneH+0.04*safeZoneH*1.52)";
		};
		class button04: button
		{
			idc = "240+04";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(04 mod 5)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+floor(04 / 5)*(0.01*safeZoneH+0.04*safeZoneH*1.52)";
		};
		class button05: button
		{
			idc = "240+05";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(05 mod 5)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+floor(05 / 5)*(0.01*safeZoneH+0.04*safeZoneH*1.52)";
		};
		class button06: button
		{
			idc = "240+06";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(06 mod 5)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+floor(06 / 5)*(0.01*safeZoneH+0.04*safeZoneH*1.52)";
		};
		class button07: button
		{
			idc = "240+07";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(07 mod 5)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+floor(07 / 5)*(0.01*safeZoneH+0.04*safeZoneH*1.52)";
		};
		class button08: button
		{
			idc = "240+08";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(08 mod 5)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+floor(08 / 5)*(0.01*safeZoneH+0.04*safeZoneH*1.52)";
		};
		class button09: button
		{
			idc = "240+09";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(09 mod 5)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+floor(09 / 5)*(0.01*safeZoneH+0.04*safeZoneH*1.52)";
		};
		class button10: button
		{
			idc = "240+10";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(10 mod 5)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+floor(10 / 5)*(0.01*safeZoneH+0.04*safeZoneH*1.52)";
		};
		class button11: button
		{
			idc = "240+11";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(11 mod 5)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+floor(11 / 5)*(0.01*safeZoneH+0.04*safeZoneH*1.52)";
		};
		class button12: button
		{
			idc = "240+12";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(12 mod 5)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+floor(12 / 5)*(0.01*safeZoneH+0.04*safeZoneH*1.52)";
		};
		class button13: button
		{
			idc = "240+13";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(13 mod 5)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+floor(13 / 5)*(0.01*safeZoneH+0.04*safeZoneH*1.52)";
		};
		class button14: button
		{
			idc = "240+14";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(14 mod 5)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+floor(14 / 5)*(0.01*safeZoneH+0.04*safeZoneH*1.52)";
		};
		class button15: button
		{
			idc = "240+15";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(15 mod 5)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+floor(15 / 5)*(0.01*safeZoneH+0.04*safeZoneH*1.52)";
		};
		class button16: button
		{
			idc = "240+16";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(16 mod 5)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+floor(16 / 5)*(0.01*safeZoneH+0.04*safeZoneH*1.52)";
		};
		class button17: button
		{
			idc = "240+17";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(17 mod 5)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+floor(17 / 5)*(0.01*safeZoneH+0.04*safeZoneH*1.52)";
		};
		class button18: button
		{
			idc = "240+18";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(18 mod 5)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+floor(18 / 5)*(0.01*safeZoneH+0.04*safeZoneH*1.52)";
		};
		class button19: button
		{
			idc = "240+19";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(19 mod 5)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+floor(19 / 5)*(0.01*safeZoneH+0.04*safeZoneH*1.52)";
		};
		class caption2: caption
		{
			idc = 231;
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(5+1)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)";
			w = 0;
		};
		class listButton00: listButton
		{
			idc = "340+00";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(5+1)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+00*0.033*safeZoneH";
		};
		class listButton01: listButton
		{
			idc = "340+01";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(5+1)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+01*0.033*safeZoneH";
		};
		class listButton02: listButton
		{
			idc = "340+02";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(5+1)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+02*0.033*safeZoneH";
		};
		class listButton03: listButton
		{
			idc = "340+03";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(5+1)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+03*0.033*safeZoneH";
		};
		class listButton04: listButton
		{
			idc = "340+04";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(5+1)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+04*0.033*safeZoneH";
		};
		class listButton05: listButton
		{
			idc = "340+05";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(5+1)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+05*0.033*safeZoneH";
		};
		class listButton06: listButton
		{
			idc = "340+06";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(5+1)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+06*0.033*safeZoneH";
		};
		class listButton07: listButton
		{
			idc = "340+07";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(5+1)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+07*0.033*safeZoneH";
		};
		class listButton08: listButton
		{
			idc = "340+08";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(5+1)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+08*0.033*safeZoneH";
		};
		class listButton09: listButton
		{
			idc = "340+09";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(5+1)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+09*0.033*safeZoneH";
		};
		class listButton10: listButton
		{
			idc = "340+10";
			x = "(safeZoneX+safeZoneW/2)-6*0.04*safeZoneW+(5+1)*0.04*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)+10*0.033*safeZoneH";
		};
	};
};
class CBA_flexiMenu_rscPopup
{
	idd = -1;
	movingEnable = 0;
	onLoad = "with uiNamespace do {cba_ui_display= _this select 0};";
	onUnload = "with uiNamespace do {cba_ui_display= displayNull};";
	class controlsBackground{};
	class objects{};
	flexiMenu_primaryMenuControlWidth = "0.21*safeZoneW";
	flexiMenu_subMenuControlWidth = "0.21*safeZoneW";
	flexiMenu_subMenuCaptionWidth = "0.21*safeZoneW";
	class listButton: _flexiMenu_RscShortcutButton
	{
		x = "(safeZoneX+safeZoneW/2)-0.21*safeZoneW";
		y = "safeZoneY+0.30*safeZoneH";
		w = 0;
		h = "0.0375*safeZoneH";
		sizeEx = "0.033*safeZoneH";
		size = "0.033*safeZoneH*0.75";
		color[] = {"138/256","146/256","105/256",1};
		color2[] = {1,1,1,0.8};
		colorBackground[] = {1,1,1,1};
		colorbackground2[] = {1,1,1,1};
		colorDisabled[] = {1,1,1,0.25};
		class TextPos
		{
			left = 0.02;
			top = 0.005;
			right = 0.02;
			bottom = 0.005;
		};
		class Attributes
		{
			font = "PuristaMedium";
			color = "#E5E5E5";
			align = "left";
			shadow = "true";
		};
		animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\popup\normal.paa";
		animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\popup\disabled.paa";
		animTextureOver = "\x\cba\addons\ui\flexiMenu\data\popup\over.paa";
		animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\popup\focused.paa";
		animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\popup\down.paa";
		animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\popup\default.paa";
		animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\popup\normal.paa";
	};
	class controls
	{
		class caption: rscText
		{
			idc = 230;
			x = "(safeZoneX+safeZoneW/2)-0.21*safeZoneW";
			y = "safeZoneY+0.30*safeZoneH-0.033*safeZoneH*1";
			w = "0.21*safeZoneW";
			h = "0.033*safeZoneH*1";
			sizeEx = "0.033*safeZoneH*1";
			colorText[] = {"138/256","146/256","105/256",1};
			colorBackground[] = {"58/256","80/256","55/256",1};
			text = "";
		};
		class button00: listButton
		{
			idc = "240+00";
			y = "safeZoneY+0.30*safeZoneH+00*0.033*safeZoneH";
		};
		class button01: listButton
		{
			idc = "240+01";
			y = "safeZoneY+0.30*safeZoneH+01*0.033*safeZoneH";
		};
		class button02: listButton
		{
			idc = "240+02";
			y = "safeZoneY+0.30*safeZoneH+02*0.033*safeZoneH";
		};
		class button03: listButton
		{
			idc = "240+03";
			y = "safeZoneY+0.30*safeZoneH+03*0.033*safeZoneH";
		};
		class button04: listButton
		{
			idc = "240+04";
			y = "safeZoneY+0.30*safeZoneH+04*0.033*safeZoneH";
		};
		class button05: listButton
		{
			idc = "240+05";
			y = "safeZoneY+0.30*safeZoneH+05*0.033*safeZoneH";
		};
		class button06: listButton
		{
			idc = "240+06";
			y = "safeZoneY+0.30*safeZoneH+06*0.033*safeZoneH";
		};
		class button07: listButton
		{
			idc = "240+07";
			y = "safeZoneY+0.30*safeZoneH+07*0.033*safeZoneH";
		};
		class button08: listButton
		{
			idc = "240+08";
			y = "safeZoneY+0.30*safeZoneH+08*0.033*safeZoneH";
		};
		class button09: listButton
		{
			idc = "240+09";
			y = "safeZoneY+0.30*safeZoneH+09*0.033*safeZoneH";
		};
		class button10: listButton
		{
			idc = "240+10";
			y = "safeZoneY+0.30*safeZoneH+10*0.033*safeZoneH";
		};
		class button11: listButton
		{
			idc = "240+11";
			y = "safeZoneY+0.30*safeZoneH+11*0.033*safeZoneH";
		};
		class button12: listButton
		{
			idc = "240+12";
			y = "safeZoneY+0.30*safeZoneH+12*0.033*safeZoneH";
		};
		class button13: listButton
		{
			idc = "240+13";
			y = "safeZoneY+0.30*safeZoneH+13*0.033*safeZoneH";
		};
		class button14: listButton
		{
			idc = "240+14";
			y = "safeZoneY+0.30*safeZoneH+14*0.033*safeZoneH";
		};
		class button15: listButton
		{
			idc = "240+15";
			y = "safeZoneY+0.30*safeZoneH+15*0.033*safeZoneH";
		};
		class button16: listButton
		{
			idc = "240+16";
			y = "safeZoneY+0.30*safeZoneH+16*0.033*safeZoneH";
		};
		class button17: listButton
		{
			idc = "240+17";
			y = "safeZoneY+0.30*safeZoneH+17*0.033*safeZoneH";
		};
		class button18: listButton
		{
			idc = "240+18";
			y = "safeZoneY+0.30*safeZoneH+18*0.033*safeZoneH";
		};
		class button19: listButton
		{
			idc = "240+19";
			y = "safeZoneY+0.30*safeZoneH+19*0.033*safeZoneH";
		};
		class caption2: caption
		{
			idc = 231;
			x = "(safeZoneX+safeZoneW/2)";
			y = "safeZoneY+0.30*safeZoneH+0.033*safeZoneH-0.033*safeZoneH*1";
			w = 0;
		};
		class listButton00: listButton
		{
			idc = "340+00";
			x = "(safeZoneX+safeZoneW/2)";
			y = "safeZoneY+0.30*safeZoneH+0.033*safeZoneH+00*0.033*safeZoneH";
		};
		class listButton01: listButton
		{
			idc = "340+01";
			x = "(safeZoneX+safeZoneW/2)";
			y = "safeZoneY+0.30*safeZoneH+0.033*safeZoneH+01*0.033*safeZoneH";
		};
		class listButton02: listButton
		{
			idc = "340+02";
			x = "(safeZoneX+safeZoneW/2)";
			y = "safeZoneY+0.30*safeZoneH+0.033*safeZoneH+02*0.033*safeZoneH";
		};
		class listButton03: listButton
		{
			idc = "340+03";
			x = "(safeZoneX+safeZoneW/2)";
			y = "safeZoneY+0.30*safeZoneH+0.033*safeZoneH+03*0.033*safeZoneH";
		};
		class listButton04: listButton
		{
			idc = "340+04";
			x = "(safeZoneX+safeZoneW/2)";
			y = "safeZoneY+0.30*safeZoneH+0.033*safeZoneH+04*0.033*safeZoneH";
		};
		class listButton05: listButton
		{
			idc = "340+05";
			x = "(safeZoneX+safeZoneW/2)";
			y = "safeZoneY+0.30*safeZoneH+0.033*safeZoneH+05*0.033*safeZoneH";
		};
		class listButton06: listButton
		{
			idc = "340+06";
			x = "(safeZoneX+safeZoneW/2)";
			y = "safeZoneY+0.30*safeZoneH+0.033*safeZoneH+06*0.033*safeZoneH";
		};
		class listButton07: listButton
		{
			idc = "340+07";
			x = "(safeZoneX+safeZoneW/2)";
			y = "safeZoneY+0.30*safeZoneH+0.033*safeZoneH+07*0.033*safeZoneH";
		};
		class listButton08: listButton
		{
			idc = "340+08";
			x = "(safeZoneX+safeZoneW/2)";
			y = "safeZoneY+0.30*safeZoneH+0.033*safeZoneH+08*0.033*safeZoneH";
		};
		class listButton09: listButton
		{
			idc = "340+09";
			x = "(safeZoneX+safeZoneW/2)";
			y = "safeZoneY+0.30*safeZoneH+0.033*safeZoneH+09*0.033*safeZoneH";
		};
		class listButton10: listButton
		{
			idc = "340+10";
			x = "(safeZoneX+safeZoneW/2)";
			y = "safeZoneY+0.30*safeZoneH+0.033*safeZoneH+10*0.033*safeZoneH";
		};
		class listButton11: listButton
		{
			idc = "340+11";
			x = "(safeZoneX+safeZoneW/2)";
			y = "safeZoneY+0.30*safeZoneH+0.033*safeZoneH+11*0.033*safeZoneH";
		};
		class listButton12: listButton
		{
			idc = "340+12";
			x = "(safeZoneX+safeZoneW/2)";
			y = "safeZoneY+0.30*safeZoneH+0.033*safeZoneH+12*0.033*safeZoneH";
		};
		class listButton13: listButton
		{
			idc = "340+13";
			x = "(safeZoneX+safeZoneW/2)";
			y = "safeZoneY+0.30*safeZoneH+0.033*safeZoneH+13*0.033*safeZoneH";
		};
		class listButton14: listButton
		{
			idc = "340+14";
			x = "(safeZoneX+safeZoneW/2)";
			y = "safeZoneY+0.30*safeZoneH+0.033*safeZoneH+14*0.033*safeZoneH";
		};
		class listButton15: listButton
		{
			idc = "340+15";
			x = "(safeZoneX+safeZoneW/2)";
			y = "safeZoneY+0.30*safeZoneH+0.033*safeZoneH+15*0.033*safeZoneH";
		};
		class listButton16: listButton
		{
			idc = "340+16";
			x = "(safeZoneX+safeZoneW/2)";
			y = "safeZoneY+0.30*safeZoneH+0.033*safeZoneH+16*0.033*safeZoneH";
		};
		class listButton17: listButton
		{
			idc = "340+17";
			x = "(safeZoneX+safeZoneW/2)";
			y = "safeZoneY+0.30*safeZoneH+0.033*safeZoneH+17*0.033*safeZoneH";
		};
		class listButton18: listButton
		{
			idc = "340+18";
			x = "(safeZoneX+safeZoneW/2)";
			y = "safeZoneY+0.30*safeZoneH+0.033*safeZoneH+18*0.033*safeZoneH";
		};
		class listButton19: listButton
		{
			idc = "340+19";
			x = "(safeZoneX+safeZoneW/2)";
			y = "safeZoneY+0.30*safeZoneH+0.033*safeZoneH+19*0.033*safeZoneH";
		};
	};
};
//};
