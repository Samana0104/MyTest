#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
#include <sstream>
#include <string>
#pragma comment(lib, "ws2_32.lib")
using namespace std;
bool InitWinSock()
{
	WSADATA lpWSAData;
	int ret = WSAStartup(MAKEWORD(2, 2), &lpWSAData);
	if (ret != 0)
		return false;
	return true;
}

void DelWinSock()
{
	WSACleanup();
}

bool IsError()
{
	int errorCode = WSAGetLastError();
	if (errorCode != WSAEWOULDBLOCK)
	{
		LPVOID msgErrorBuffer;
		FormatMessageA(
			FORMAT_MESSAGE_ALLOCATE_BUFFER |
			FORMAT_MESSAGE_FROM_SYSTEM,
			NULL,
			errorCode,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			reinterpret_cast<LPSTR>(&msgErrorBuffer),
			0,
			NULL
		);
		std::cerr << "ERROR[" << errorCode << "]" << reinterpret_cast<LPSTR>(msgErrorBuffer) << std::endl;
		LocalFree(msgErrorBuffer);
		return true;
	}
	return false;
}

int main()
{
	InitWinSock();
	SOCKET servSock, clntSock;
	sockaddr_in serv, clnt;
	string msg;
	int adrSize;
	int strLen = 0;

	msg.resize(30);
	
	servSock = socket(PF_INET, SOCK_STREAM, 0);
	
	serv = {};
	{
		serv.sin_family		 = AF_INET;
		serv.sin_addr.s_addr = htonl(INADDR_ANY);
		serv.sin_port		 = htons(10000);
	}
	
	bind(servSock, reinterpret_cast<sockaddr*>(&serv), sizeof(serv));
	IsError();
	listen(servSock, SOMAXCONN);
	
	adrSize = sizeof(clnt);
	clntSock = accept(servSock, reinterpret_cast<sockaddr*>(&clnt), &adrSize);

	cout << "서버 실행" << endl;
	while ((strLen = recv(clntSock, &msg[0], msg.size(), 0)) != 0)
	{
		send(clntSock, &msg[0], strLen, 0);
		//send(1, &msg[0], strLen, 0);
	}
	closesocket(clntSock);
	closesocket(servSock);
	DelWinSock();
}
