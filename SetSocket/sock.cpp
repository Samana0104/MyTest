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
	SOCKET sock;
	int sndBuf, rcvBuf, state;
	bool nagle = true;
	int len = sizeof(sndBuf);
	int len2 = sizeof(nagle);
	sock = socket(PF_INET, SOCK_STREAM, 0);
	state = setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, reinterpret_cast<char*>(&nagle), 1);
	state = getsockopt(sock, SOL_SOCKET, SO_SNDBUF, reinterpret_cast<char*>(&sndBuf), &len);
	state = getsockopt(sock, SOL_SOCKET, SO_RCVBUF, reinterpret_cast<char*>(&rcvBuf), &len);
	state = getsockopt(sock, IPPROTO_TCP, TCP_NODELAY, reinterpret_cast<char*>(&nagle), &len2);

	cout << sndBuf << endl;
	cout << rcvBuf << endl;
	cout << nagle << endl;
	DelWinSock();
}
