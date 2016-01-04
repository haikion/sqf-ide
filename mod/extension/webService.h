#pragma once
#ifndef WEB_SERVICE_H
#include <thread>

namespace webService
{
	extern const unsigned PORT;
	extern const std::string WSDL_TEXT;
	std::thread* start();
	void serverLoop();
	int http_get(struct soap* soap);
}

#endif WEB_SERVICE_H