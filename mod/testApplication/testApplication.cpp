/*
Program to test Extension class.
Requires the plugin to be build first.
Compiles on both Linux and Windows.
*/

#include "stdafx.h"

#include <math.h>
#include <string>
#include <iostream>
#include "../extension/Extension.h"

int main(int argc, char* argv[])
{
	char* output = "";
	int outputSize = 10000;
	std::string rVal = "";
	rVal = Extension::getInstance().rvExtension(outputSize, "getState");
	fprintf(stderr, "main() rVal='%s'\n", rVal.c_str());
	std::cin.get(); //wait for enter

	rVal = Extension::getInstance().rvExtension(outputSize, "getState");
	fprintf(stderr, "main() rVal='%s'\n", rVal.c_str());
	std::cin.get(); //wait for enter

	rVal = Extension::getInstance().rvExtension(outputSize, "getState");
	fprintf(stderr, "main() rVal='%s'\n", rVal.c_str());
	std::cin.get(); //wait for enter
}