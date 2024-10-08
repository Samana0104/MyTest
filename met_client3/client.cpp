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
	SOCKET sock = socket(AF_INET, SOCK_DGRAM, 0);
	SOCKADDR_IN sa, ca;
	string msg;
	sa = { };
	ca = { };
	int caAdr = 0;
	int readByte = 0;
	int sendByte = 0;

	sa.sin_addr.s_addr = inet_addr("127.0.0.1");
	sa.sin_port = htons(10000);
	sa.sin_family = AF_INET;

	int ret;

	//ret = bind(sock, reinterpret_cast<SOCKADDR*>(&sa), sizeof(sa));

	if (!IsError())
		return 0;

	cout << "----------------------------------------------------------------" << endl;
	while (true)
	{
		cout << "input msg : ";
		cin >> msg;

		if (msg.compare("q") == 0)
			break;

		caAdr = sizeof(sa);
		sendByte = sendto(sock, &msg[0], msg.size(), 0, reinterpret_cast<sockaddr*>(&sa), caAdr);
		Sleep(30);
		readByte = recvfrom(sock, &msg[0], sendByte, 0, reinterpret_cast<sockaddr*>(&ca), &caAdr);

		if (readByte >= 0)
		{
			msg[readByte] = '\0';
			cout << msg << endl;;
		}
	}

	closesocket(sock);
	WSACleanup();
	return 0;
}
