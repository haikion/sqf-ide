////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.52
//'now' is Wed Jul 13 18:00:35 2016 : 'file' last modified on Wed Jul 13 18:00:35 2016
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_hashes : config.bin{
class CfgPatches
{
	class cba_hashes
	{
		author = "$STR_CBA_Author";
		name = "$STR_cba_hashes_component";
		url = "$STR_CBA_URL";
		units[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CBA_common"};
		version = "3.0.0.160713";
		authors[] = {"Spooner"};
		weapons[] = {};
	};
};
class CfgFunctions
{
	class CBA
	{
		class Hashes
		{
			class hashCreate
			{
				description = "Check if a Hash has a value defined for a key.";
				file = "\x\cba\addons\hashes\fnc_hashCreate.sqf";
			};
			class hashEachPair
			{
				description = "Iterate through all keys and values in a Hash.";
				file = "\x\cba\addons\hashes\fnc_hashEachPair.sqf";
			};
			class hashGet
			{
				description = "Gets a value for a given key from a Hash.";
				file = "\x\cba\addons\hashes\fnc_hashGet.sqf";
			};
			class hashHasKey
			{
				description = "Check if a Hash has a value defined for a key.";
				file = "\x\cba\addons\hashes\fnc_hashHasKey.sqf";
			};
			class hashRem
			{
				description = "Removes given key from given Hash.";
				file = "\x\cba\addons\hashes\fnc_hashRem.sqf";
			};
			class hashSet
			{
				description = "Sets a value for a given key in a Hash.";
				file = "\x\cba\addons\hashes\fnc_hashSet.sqf";
			};
			class isHash
			{
				description = "Check if a value is a Hash data structure.";
				file = "\x\cba\addons\hashes\fnc_isHash.sqf";
			};
			class testHash
			{
				description = "Internal Self Check. Check the RPT file for results.";
				file = "\x\cba\addons\hashes\test.sqf";
			};
			class parseYAML
			{
				description = "Parses a YAML file into a nested array/Hash structure.";
				file = "\x\cba\addons\hashes\fnc_parseYAML.sqf";
			};
		};
	};
};
//};
