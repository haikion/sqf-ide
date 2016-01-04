#pragma once
/*
Acts as a middlewear between ArmA and SQF-IDE.
This is platform independed standard C++ part of the extension.
*/
#include <string>

class Extension
{
public:
	//Singleton
	Extension(const Extension&) = delete;
	void operator=(const Extension&) = delete;
	static Extension& getInstance();

	std::string rvExtension(int outputSize, const char* function);
	bool runSQFScript(std::string script);
private:
	std::string state_ = "initializing";
	std::string code_ = "";

	std::string readCode(int outputSize);
	void Extension::codeState(std::string input, int outputSize, std::string& output);
	Extension() = default;
};