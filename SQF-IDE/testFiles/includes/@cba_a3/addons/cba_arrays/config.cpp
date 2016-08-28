////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.52
//'now' is Wed Jul 13 18:00:29 2016 : 'file' last modified on Wed Jul 13 18:00:29 2016
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_arrays : config.bin{
class CfgPatches
{
	class cba_arrays
	{
		author = "$STR_CBA_Author";
		name = "$STR_cba_arrays_component";
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
		class Arrays
		{
			class filter
			{
				description = "Filter each element of an array via a function.";
				file = "\x\cba\addons\arrays\fnc_filter.sqf";
			};
			class findMax
			{
				description = "Find largest numeric value with index in an array.";
				file = "\x\cba\addons\arrays\fnc_findMax.sqf";
			};
			class findMin
			{
				description = "Find smallest numeric value with index in an array.";
				file = "\x\cba\addons\arrays\fnc_findMin.sqf";
			};
			class findNil
			{
				description = "A function that returns the index of the first empty (nil) entry in an array.";
				file = "\x\cba\addons\arrays\fnc_findNil.sqf";
			};
			class findTypeName
			{
				description = "A function that returns the index of the first entry of a certain type in an array.";
				file = "\x\cba\addons\arrays\fnc_findTypeName.sqf";
			};
			class findTypeOf
			{
				description = "A function that returns the index of the first entry of a certain type in an array.";
				file = "\x\cba\addons\arrays\fnc_findTypeOf.sqf";
			};
			class findNull
			{
				description = "A function that returns the index of the first null entry in an array.";
				file = "\x\cba\addons\arrays\fnc_findNull.sqf";
			};
			class getArrayDiff
			{
				description = "A function used to return the differences between two arrays. Parameters: Two Arrays of strings (must not contain scalars) Example: _distance = [[0,0,1], [0,0,0]] call CBA_fnc_getArrayDiff Returns: Array Differences (for above example, return is [[1],[0]]) Author: Rommel";
				file = "\x\cba\addons\arrays\fnc_getArrayDiff.sqf";
			};
			class getArrayElements
			{
				description = "A function used to return the element counts in an array. Parameters: Array Example: _types = [0,0,1,1,1,1] call CBA_fnc_getArrayElements Returns: Array element counts (for above example, return would be [0,2,1,4]) Author: Rommel && sbsmac";
				file = "\x\cba\addons\arrays\fnc_getArrayElements.sqf";
			};
			class inject
			{
				description = "Accumulates a value by passing elements of an array ""through"" a function.";
				file = "\x\cba\addons\arrays\fnc_inject.sqf";
			};
			class join
			{
				description = "Joins an array of values into a single string, joining each fragment around a separator string. Inverse of <CBA_fnc_split>.";
				file = "\x\cba\addons\arrays\fnc_join.sqf";
			};
			class reject
			{
				description = "Reject array elements for which the block returns true";
				file = "\x\cba\addons\arrays\fnc_reject.sqf";
			};
			class select
			{
				description = "Select array elements for which the block returns true";
				file = "\x\cba\addons\arrays\fnc_select.sqf";
			};
			class shuffle
			{
				description = "Shuffles an array's contents into random order, returning a new array.";
				file = "\x\cba\addons\arrays\fnc_shuffle.sqf";
			};
			class sortNestedArray
			{
				description = "Used to sort a nested array from lowest to highest using quick sort based on the specified column, which must have numerical data. Parameters: _array: array - Nested array to be sorted _index: integer - sub array item index to be sorted on Example: _array = [_array,1] call CBA_fnc_sortNestedArray Returns: Passed in array Author: Standard algorithm";
				file = "\x\cba\addons\arrays\fnc_sortNestedArray.sqf";
			};
			class testArrays
			{
				description = "Internal Self Check. Check the RPT file for results.";
				file = "\x\cba\addons\arrays\test.sqf";
			};
		};
	};
};
//};
