class CfgFunctions
{
	class SI
	{
		class functions
		{
			class eventLoop 
			{
				//preStart causes SQF to behave in an unexpected way. 
				//preStart = 1; // 1 to call the function upon game start, before title screen, but after all addons are loaded.
				postInit = 1; // 1 to call the function upon game start, before title screen, but after all addons are loaded.
				file = "si\fnc_eventLoop.sqf";
			};
		};
	};
};

class CfgPatches
{
	//class KYL_addFirstMag
	class SI
	{
		units[] = {};
		//weapons[] = {};
		//requiredVersion = 1.0;
		//requiredAddons[] = {"Extended_EventHandlers"};

	};
};

//class Extended_PreInit_EventHandlers {
//  KYL_AFM_Init = "KYL_AFM_Init_Var = [] execVM ""\KYL_addFirstMag\init.sqf""";
//};