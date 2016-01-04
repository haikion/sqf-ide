// si.cpp : Defines the exported functions for the DLL application.
// 32 bit Windows specific library.
//

#include "stdafx.h"

#include "Extension.h"

extern "C" 
{
	__declspec (dllexport) void __stdcall RVExtension(char *output, int outputSize, const char *function); 
}

void __stdcall RVExtension(char* output, int outputSize, const char* function) 
{
	std::string rVal = Extension::getInstance().rvExtension(outputSize, function);
	strncpy_s(output, outputSize, rVal.c_str(), _TRUNCATE); 
}