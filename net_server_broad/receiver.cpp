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
	sockaddr_in sendAdr = { };
	sockaddr_in cintAdr = { };
	int size = sizeof(sockaddr_in);

	hSocket = socket(PF_INET, SOCK_DGRAM, 0);
	{
		sendAdr.sin_family = AF_INET;
		sendAdr.sin_addr.s_addr = htonl(INADDR_ANY);
		sendAdr.sin_port = htons(9000);
	}

	int ret = bind(hSocket, reinterpret_cast<sockaddr*>(&sendAdr), sizeof(sendAdr));
	
	while (true)
	{
		string msg;
		int len;
		msg.resize(100);
		
		len = recvfrom(hSocket, &msg[0], msg.size(), 0, reinterpret_cast<sockaddr*>(&cintAdr), &size);
		len = sendto(hSocket, &msg[0], msg.size(), 0, reinterpret_cast<sockaddr*>(&cintAdr), sizeof(cintAdr));
		msg[len] = '\\n';
		cout << "메세지 받는 중 : " << msg  << " 크기 : "<<len << endl;
		Sleep(1000);
	}
	closesocket(hSocket);
	WSACleanup();
	return 0;
}
