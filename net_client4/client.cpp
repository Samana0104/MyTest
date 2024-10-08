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
	SOCKET hSocket;
	sockaddr_in sendAdr;

	hSocket = socket(PF_INET, SOCK_STREAM, 0);
	sendAdr = { };
	{
		sendAdr.sin_family = AF_INET;
		sendAdr.sin_addr.s_addr = inet_addr("127.0.0.1");
		sendAdr.sin_port = htons(10000);
	}
	
	connect(hSocket, reinterpret_cast<sockaddr*>(&sendAdr), sizeof(sendAdr));
	
	send(hSocket, "123", 3, 0);
	send(hSocket, "4", 1, MSG_OOB);
	Sleep(100);
	send(hSocket, "567", 3, 0);
	send(hSocket, "10", 2, MSG_OOB);
	Sleep(100);
	send(hSocket, "34", 2, MSG_OOB);
	Sleep(100);
	send(hSocket, "23", 2, MSG_OOB);

	closesocket(hSocket);
	WSACleanup();
	return 0;
}
