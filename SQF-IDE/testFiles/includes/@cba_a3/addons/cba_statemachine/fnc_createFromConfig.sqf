/* ----------------------------------------------------------------------------
Function: CBA_statemachine_fnc_createFromConfig

Description:
    Creates a state machine from a config class.

Parameters:
    _config         - config path that contains a valid state machine config
                      (check the example.hpp file for the required structure)
                      <CONFIG>

Returns:
    _stateMachine   - a state machine <LOCATION>

Examples:
    (begin example)
        _stateMachine = [configFile >> "MyAddon_Statemachine"] call CBA_statemachine_fnc_createFromConfig;
    (end)

Author:
    BaerMitUmlaut
---------------------------------------------------------------------------- */
#include "script_component.hpp"
SCRIPT(createFromConfig);
params [["_config", [], [configNull]]];

if (isNull _config) exitWith {};

private _list = compile getText (_config >> "list");
private _skipNull = (getNumber (_config >> "skipNull")) > 0;
private _stateMachine = [_list, _skipNull] call FUNC(create);

{
    private _state = configName _x;
    private _onState = compile getText (_x >> "onState");
    private _onStateEntered = compile getText (_x >> "onStateEntered");
    private _onStateLeaving = compile getText (_x >> "onStateLeaving");
    [_stateMachine, _onState, _onStateEntered, _onStateLeaving, _state] call FUNC(addState);

    false
} count (configProperties [_config, "isClass _x", true]);

// We need to add the transitions in a second loop to make sure the states exist already
{
    private _state = configName _x;
    {
        private _transition = configName _x;
        private _targetState = getText (_x >> "targetState");
        private _condition = compile getText (_x >> "condition");
        private _onTransition = compile getText (_x >> "onTransition");

        [_stateMachine, _state, _targetState, _condition, _onTransition, _transition] call FUNC(addTransition);

        false
    } count (configProperties [_x, "isClass _x", true]);

    false
} count (configProperties [_config, "isClass _x", true]);

_stateMachine
