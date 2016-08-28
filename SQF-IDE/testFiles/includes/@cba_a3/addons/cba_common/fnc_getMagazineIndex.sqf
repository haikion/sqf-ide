/* ----------------------------------------------------------------------------
Function: CBA_fnc_getMagazineIndex

Description:
    Finds out the magazine ID of all magazines of given type in the inventory of given unit.

Parameters:
    _unit     - Unit to check <OBJECT>
    _magazine - Magazines to check <OBJECT>

Returns:
    Magazine IDs <ARRAY of STRINGS>

Author:
    commy2
---------------------------------------------------------------------------- */
#include "script_component.hpp"
SCRIPT(getMagazineIndex);

params [["_unit", objNull, [objNull]], ["_magazine", "", [""]]];

private _displayName = getText (configFile >> "CfgMagazines" >> _magazine >> "displayName");

if (_displayName isEqualTo "") exitWith {[]};

#ifndef LINUX_BUILD
    magazinesDetail _unit select {_x find _displayName == 0} apply {_x = _x splitString "[:]"; _x select (count _x - 1)};
#else
    [magazinesDetail _unit, {
        if (_x find _displayName == 0) then {
            _x = _x splitString "[:]";
            _x = _x select (count _x - 1);
            true
        } else {false};
    }] call BIS_fnc_conditionalSelect;
#endif
