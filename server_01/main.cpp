#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
#include <string>
#include <fstream>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

int main()
{
	WSAData data = { };
	SOCKADDR_IN servAddr = { };
	SOCKET servSock;
	int hr = 0;

	hr = WSAStartup(MAKEWORD(2, 2), &data);

	if (hr != 0)
		cerr << "error" << endl;

	servSock = socket(PF_INET, SOCK_STREAM, 0);

	if(servSock == INVALID_SOCKET)
		cerr << "error" << endl;

	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = INADDR_ANY;
	servAddr.sin_port = htons(10000);

	hr = bind(servSock, reinterpret_cast<sockaddr*>(&servAddr), sizeof(servAddr));

	if (hr != 0)
		cerr << "error" << endl;
	
	hr = listen(servSock, SOMAXCONN);

	if (hr != 0)
		cerr << "error" << endl;

	SOCKET clientSock;
	sockaddr_in clientAddr = { };

	string str;
	int sz = sizeof(clientAddr);
	clientSock = accept(servSock, reinterpret_cast<sockaddr*>(&clientAddr), &sz);

	while (1)
	{
		cin >> str;
		hr = send(clientSock, str.c_str(), str.size(), 0);
	}

	closesocket(servSock);
	closesocket(clientSock);
	WSACleanup();
	return 0;
}