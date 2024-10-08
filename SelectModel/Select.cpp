#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
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
	SOCKET sock, clntSock;

	clntSock = -1;
	sock = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN sa, ca;
	FD_SET readSet, writeSet, errorSet;
	FD_SET cpyRSet, cpyWSet, cpyESet;
	string msg;
	timeval  time;

	sa = { };
	ca = { };
	int caAdr = 0;
	int readByte = 0;
	int sendByte = 0;

	sa.sin_addr.s_addr = inet_addr("127.0.0.1");
	sa.sin_port = htons(10000);
	sa.sin_family = AF_INET;

	int ret;

	ret = bind(sock, reinterpret_cast<SOCKADDR*>(&sa), sizeof(sa));
	ret = listen(sock, SOMAXCONN);

	if (!IsError())
		return 0;

	msg.resize(256);

	FD_ZERO(&readSet);
	FD_ZERO(&writeSet);
	FD_ZERO(&errorSet);
	FD_SET(sock, &readSet);
	FD_SET(sock, &writeSet);
	FD_SET(sock, &errorSet);

	cout << "----------------------------------------------------------------" << endl;
	while (true)
	{
		cpyRSet = readSet;
		cpyESet = errorSet;
		cpyWSet = writeSet;
		time.tv_sec = 5;
		time.tv_usec = 0;
		int iRet = select(0, &cpyRSet, &cpyWSet, &cpyESet, &time);

		if (iRet == SOCKET_ERROR)
		{
			break;
		}
		else if (iRet == 0)
		{
			cout << "타임아웃" << endl;
			continue;
		}

		if (FD_ISSET(sock, &cpyRSet))
		{
			caAdr = sizeof(ca);
			clntSock = accept(sock, reinterpret_cast<sockaddr*>(&ca), &caAdr);
			FD_SET(clntSock, &readSet);
			cout << "클라이언트 접속" << msg<< endl;
		}

		if (FD_ISSET(clntSock, &cpyRSet))
		{
			int test = recv(clntSock, &msg[0], msg.size(), 0);
			cout << "수신받은 메세지 : " << msg << test<< endl;
		}
	}

	closesocket(sock);
	WSACleanup();
	return 0;
}