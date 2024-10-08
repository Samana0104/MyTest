#define _WINSOCK_DEPRECATED_NO_WARNINGS 
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
	servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servAddr.sin_port = htons(10000);

	hr = connect(servSock, reinterpret_cast<sockaddr*>(&servAddr), sizeof(servAddr));

	if (hr != 0)
		cerr << "error" << endl;
	

	if (hr != 0)
		cerr << "error" << endl;

	string str;
	int a = 10;
	int readByte = 0;
	string buffer;
	str.resize(256);

	Sleep(10000);
		readByte = recv(servSock, const_cast<char*>(str.data()), str.size(), 0);
		buffer += str;
		
	cout << buffer<<endl;


	closesocket(servSock);
	WSACleanup();
	return 0;
}
