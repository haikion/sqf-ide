////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.52
//'now' is Wed Jul 13 18:00:46 2016 : 'file' last modified on Wed Jul 13 18:00:46 2016
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_strings : config.bin{
class CfgPatches
{
	class cba_strings
	{
		author = "$STR_CBA_Author";
		name = "$STR_cba_strings_component";
		url = "$STR_CBA_URL";
		units[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CBA_common"};
		version = "3.0.0.160713";
		authors[] = {"Spooner","Kronzky"};
		weapons[] = {};
	};
};
class CfgFunctions
{
	class CBA
	{
		class Strings
		{
			class capitalize
			{
				description = "Upper case the first letter of the string, lower case the rest.";
				file = "\x\cba\addons\strings\fnc_capitalize.sqf";
			};
			class substring
			{
				description = "Extracts the index-based substring from a string.";
				file = "\x\cba\addons\strings\fnc_substring.sqf";
			};
			class substr
			{
				description = "Retrieves a substring of this instance. The substring starts at a specified character position and has a specified length.";
				file = "\x\cba\addons\strings\fnc_substr.sqf";
			};
			class find
			{
				description = "Finds a string within another string.";
				file = "\x\cba\addons\strings\fnc_find.sqf";
			};
			class floatToString
			{
				description = "Higher precision string representation of a float. Fast.";
				file = "\x\cba\addons\strings\fnc_floatToString.sqf";
			};
			class formatElapsedTime
			{
				description = "Formats time in seconds according to a format. Intended to show time elapsed, rather than time-of-day.";
				file = "\x\cba\addons\strings\fnc_formatElapsedTime.sqf";
			};
			class formatNumber
			{
				description = "Formats a number to a minimum integer width and to a specific number of decimal places (including padding with 0s and correct rounding). Numbers are always displayed fully, never being condensed using an exponent (e.g. the number 1.234e9 would be given as ""1234000000"").";
				file = "\x\cba\addons\strings\fnc_formatNumber.sqf";
			};
			class leftTrim
			{
				description = "Trims white-space (space, tab, newline) from the left end of a string.";
				file = "\x\cba\addons\strings\fnc_leftTrim.sqf";
			};
			class replace
			{
				description = "Replaces substrings within a string. Case-dependent.";
				file = "\x\cba\addons\strings\fnc_replace.sqf";
			};
			class rightTrim
			{
				description = "Trims white-space (space, tab, newline) from the right end of a string.";
				file = "\x\cba\addons\strings\fnc_rightTrim.sqf";
			};
			class split
			{
				description = "Splits a string into substrings using a separator. Inverse of <CBA_fnc_join>.";
				file = "\x\cba\addons\strings\fnc_split.sqf";
			};
			class strLen
			{
				description = "Counts the number of characters in a string.";
				file = "\x\cba\addons\strings\fnc_strLen.sqf";
			};
			class trim
			{
				description = "Trims white-space (space, tab, newline) from the both ends of a string.";
				file = "\x\cba\addons\strings\fnc_trim.sqf";
			};
			class testStrings
			{
				description = "Internal Self Check. Check the RPT file for results.";
				file = "\x\cba\addons\strings\test.sqf";
			};
		};
	};
};
//};
