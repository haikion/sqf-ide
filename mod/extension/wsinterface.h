#pragma once

#include <string>

//gsoap ns service name: arma3
//gsoap ns service namespace: http://www.mysite.com/arma3.wsdl
//gsoap ns service location: http://www.mysite.com/arma3.cgi
//gsoap ns schema namespace: urn:calc
int ns__runSQFScript(std::string code, bool* runSuccesful);