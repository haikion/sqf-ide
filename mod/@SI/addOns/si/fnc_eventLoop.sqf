private ["_codeState", "_extension", "_running"];
_extension = "SI";
_running = true;

diag_log "Running event loop 30";
hint "Running event loop 30";

_codeState = {
	private[ "_codeString", "_code", "_state"];
	_codeString = "";
	_code = {};
	_state = _extension callExtension "getState";
	
	//Join code
	while { _state == "code" } do
	{
		private["_codeBlock"];
	
		_codeBlock = _extension callExtension "getCode";
		diag_log format["_codeBlock = %1", _codeBlock];
		_codeString = [_codeString, _codeBlock] joinString "";
		_state = _extension callExtension "getState";
	};
	diag_log format["_state = %1", _state];
	//Run code
	_code = compile _codeString;
	[] spawn _code;
	_codeString = "";
};

while {_running} do
{
	_state = _extension callExtension "getState";
	switch (_state) do 
	{
		case "listening": {};
		case "initializing": {};
		case "code": { [] call _codeState; };
		case default {
			hint format["Incorrect state: %1", _state]; 
			_running = false
		}; //exit loop
	};
	sleep 1;
}