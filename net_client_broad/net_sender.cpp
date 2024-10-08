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
	sockaddr_in sendAdr = {};
	sockaddr_in broadAdr = {};
	bool so_brd = true;
	hSocket = socket(PF_INET, SOCK_DGRAM, 0);

	sendAdr.sin_family = AF_INET;
	sendAdr.sin_addr.s_addr = inet_addr("235.7.8.9");
	sendAdr.sin_port = htons(9000);
	int ret = bind(hSocket, reinterpret_cast<sockaddr*>(&sendAdr), sizeof(sendAdr));

	string msg;
	msg = "[9000 Port][Send to 235.7.8.9]The port are sending a packet";
	while (true)
	{
		cout << "메세지 전송 중 ..." << endl;
			int ret = setsockopt(hSocket, SOL_SOCKET, SO_BROADCAST, (char*)&so_brd, sizeof(so_brd));
			sendto(hSocket, &msg[0], msg.size(), 0, reinterpret_cast<sockaddr*>(&sendAdr), sizeof(sendAdr));
		IsError();
		Sleep(5000);
	}

	closesocket(hSocket);
	WSACleanup();
	return 0;
}
