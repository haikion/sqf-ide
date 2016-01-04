#include <string>
#include <algorithm>
#include "WebService.h"
#include "Extension.h"

Extension& Extension::getInstance()
{
	static Extension instance; // Guaranteed to be destroyed.
								  // Instantiated on first use.
	return instance;
}

std::string Extension::rvExtension(int outputSize,const char* function)
{
	std::string outputString = "NO_OUTPUT";
	std::string input = function;

	if (input == "getState")
	{
		outputString = state_;
	}
	
	if (state_ == "initializing")
	{
		webService::start();
		state_ = "listening";
	}
	else if (state_ == "listening")
	{
		fprintf(stderr, "listening state code_='%s'\n", 
			code_.c_str());

		if (code_.length() != 0)
		{
			//FIXME: State transition never happens.....
			state_ = "code";
		}
	}
	else if (state_ == "code")
	{
		codeState(input, outputSize, outputString);
	}

	return outputString;
	//strcpy(output, outputString.c_str());
}

bool Extension::runSQFScript(std::string script)
{
	if (state_ != "listening")
	{
		return false;
	}
	code_ = script; //Set code to be executed
	return true;
}

void Extension::codeState(std::string input, int outputSize, std::string& output)
{

	if (input == "getCode")
	{
		output = readCode(outputSize);
	}

	if (code_.length() == 0)
	{
		state_ = "listening";
	}
}


std::string Extension::readCode(int outputSize)
{
	int toRead = std::min(outputSize, int(code_.length()));
	std::string rVal = code_.substr(0, toRead);
	code_.erase(0, toRead);

	return rVal;
}