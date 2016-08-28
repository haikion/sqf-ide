#include "\x\cba\addons\keybinding\script_component.hpp"

// This button, when clicked, toggles between vanilla and addon control config in RscDisplayConfigure.
disableSerialization;
private ["_KeyboardGroup", "_MouseGroup", "_addonsGroup", "_toggleButton", "_fakeKeyboardButton", "_keyboardButton", "_mouseButton", "_controllerButton", "_title"];
// Get button
params ["_ctrl"];
// Get dialog
_display = uiNamespace getVariable "RscDisplayConfigure";

_KeyboardGroup = _display displayctrl 2300;
_MouseGroup = _display displayctrl 2301;
_addonsGroup = _display displayctrl 4301;
_toggleButton = _display displayCtrl 4302;
_fakeKeyboardButton = _display displayctrl 4303;

_keyboardButton = _display displayctrl 2400;
_mouseButton = _display displayCtrl 2401;
_controllerButton = _display displayCtrl 106;
_title = _display displayCtrl 1000;

// Toggle displayed groups and buttons.
if !(ctrlEnabled _addonsGroup) then {
    // Hide keyboard group
    _KeyboardGroup ctrlenable false;
    _KeyboardGroup ctrlshow false;

    // Hide mouse group
    _MouseGroup ctrlenable false;
    _MouseGroup ctrlshow false;

    // Hide Presets button
    _control = _display displayctrl 114;
    _control ctrlenable false;
    _control ctrlshow false;

    // Hide Default button
    _control = _display displayctrl 101;
    _control ctrlenable false;
    _control ctrlshow false;

    // Hide mouse, keyboard, and controllers buttons
    _mouseButton ctrlenable false;
    _mouseButton ctrlshow false;
    _controllerButton ctrlenable false;
    _controllerButton ctrlshow false;
    _keyboardButton ctrlenable false;
    _keyboardButton ctrlshow false;

    // Show fake keyboard button
    _fakeKeyboardButton ctrlShow true;
    _fakeKeyboardButton ctrlEnable true;

    // Show Addons group
    _addonsGroup ctrlenable true;
    _addonsGroup ctrlshow true;

    // Change button text
    _toggleButton ctrlSetText localize LSTRING(configureBase);
} else {
    // Switch back to vanilla keyboard config.
    // Hide Addons group
    _addonsGroup ctrlenable false;
    _addonsGroup ctrlshow false;
    _toggleButton ctrlSetText localize LSTRING(configureAddons);

    //--- Enable Keyboard
    _KeyboardGroup ctrlenable true;
    _KeyboardGroup ctrlshow true;

    //--- Disable Mouse
    _MouseGroup ctrlenable false;
    _MouseGroup ctrlshow false;

    // Hide fake keyboard button
    _fakeKeyboardButton ctrlShow false;
    _fakeKeyboardButton ctrlEnable false;

    // Terminate any waiting input actions
    GVAR(waitingForInput) = false;
    GVAR(input) = [];

    // Show mouse, keyboard, and controllers buttons
    _mouseButton ctrlenable true;
    _mouseButton ctrlshow true;
    _controllerButton ctrlenable true;
    _controllerButton ctrlshow true;
    _keyboardButton ctrlenable true;
    _keyboardButton ctrlshow true;

    //--- Show Presets button
    _control = _display displayctrl 114;
    _control ctrlenable true;
    _control ctrlshow true;

    //--- Hide Default button
    _control = _display displayctrl 101;
    _control ctrlenable false;
    _control ctrlshow false;
};
