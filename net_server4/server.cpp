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
	SOCKET hAcptSock, hRecvSock;
	sockaddr_in recvAdr, sendAdr;
	int sendAdrSize, strLen;
	string msg;

	fd_set read, except, readCopy, exceptCopy;
	timeval timeout;

	hAcptSock = socket(PF_INET, SOCK_STREAM, 0);
	recvAdr = {};
	{
		recvAdr.sin_family = AF_INET;
		recvAdr.sin_addr.s_addr = htonl(INADDR_ANY);
		recvAdr.sin_port = htons(10000);
	}

	int ret = bind(hAcptSock, reinterpret_cast<sockaddr*>(&recvAdr), sizeof(recvAdr));
	ret = listen(hAcptSock, SOMAXCONN);

	sendAdrSize = sizeof(sendAdr);
	hRecvSock = accept(hAcptSock, reinterpret_cast<sockaddr*>(&sendAdr), &sendAdrSize);
	
	FD_ZERO(&read);
	FD_ZERO(&except);
	FD_SET(hRecvSock, &read);
	FD_SET(hRecvSock, &except);
	
	while (true)
	{
		string msg;
		msg.resize(100);
		readCopy = read;
		exceptCopy = except;
		timeout.tv_sec = 5;
		timeout.tv_usec = 0;
		
		cout << "Å¸ÀÓ¾Æ¿ô Àü" << endl;
		int result = select(0, &read, nullptr, &except, &timeout);
		cout << "Å¸ÀÓ¾Æ¿ô ÈÄ" << endl;

		if (result > 0)
		{
			if (FD_ISSET(hRecvSock, &exceptCopy))
			{
				strLen = recv(hRecvSock, &msg[0], msg.size(), MSG_OOB);

				cout << "Urgent : " << msg<<endl;
			}

			if (FD_ISSET(hRecvSock, &readCopy))
			{
				strLen = recv(hRecvSock, &msg[0], msg.size(), 0);
				if (strLen == 0)
					break;
				else
					cout << "msg : "<< msg << endl;
			}
		}
	}
	closesocket(hRecvSock);
	closesocket(hAcptSock);
	WSACleanup();
	return 0;
}
