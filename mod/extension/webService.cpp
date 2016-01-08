#include "src-gen/soapH.h" /* get the gSOAP-generated definitions */
#include "src-gen/arma3.nsmap" /* get the gSOAP-generated namespace bindings */
#include "src-gen/wsdl.h" //WSDL char[] constant
#include "webService.h"
#include "Extension.h"
#include <algorithm>

const std::string webService::WSDL_TEXT(reinterpret_cast<char const*>(src_gen_arma3_wsdl), src_gen_arma3_wsdl_len);
const unsigned webService::PORT(8888);

int ns__runSQFScript(struct soap* soap, std::string code, bool* runSuccesful)
{
	fprintf(stderr, "ns__runSQFScript() code='%s'\n", code.c_str());

	*runSuccesful = Extension::getInstance().runSQFScript(code);
	return SOAP_OK;
}

std::thread* webService::start()
{
	std::thread* runLoop = new std::thread(webService::serverLoop);
	return runLoop;
}

void webService::serverLoop()
{
	int m, s; /* master and slave sockets */
	struct soap *soap = soap_new();
	soap->fget = http_get;
	fprintf(stderr, "http_get added");
	if (false) //FIXME: Beautify
		soap_serve(soap); /* serve as CGI application */
	else
	{
		m = soap_bind(soap, NULL, webService::PORT, 100); /* bind to the port supplied as command-line argument */
		if (m < 0)
		{
			fprintf(stderr, "fault");
			soap_print_fault(soap, stderr);
			exit(-1);
		}
		fprintf(stderr, "Socket connection successful: master socket = %d\n", m);
		for (;;)
		{
			s = soap_accept(soap);
			fprintf(stderr, "Socket connection successful: slave socket = %d\n", s);
			if (s < 0)
			{
				soap_print_fault(soap, stderr);
				exit(1);
			}
			soap_serve(soap);
			soap_end(soap);
		}
	}
	soap_done(soap);
	free(soap);
}

//TODO: Return 404 when wrong path is given.
int webService::http_get(struct soap *soap)
{
	fprintf(stderr, "executing http_get() \n");
	soap->http_content = "text/xml";
	soap_response(soap, SOAP_FILE); // HTTP response header with text/html

	char dle = 16;
	char fs = 28;
	char g = 117;
	fprintf(stderr, "executing http_get() '%c' '%c' \n", dle, fs);
	soap_send(soap, WSDL_TEXT.c_str());
	soap_end_send(soap);
	return SOAP_OK;
}