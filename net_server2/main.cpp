#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
#include <vector>
#include <list>
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

struct Session
{
	SOCKET		sock;
	SOCKADDR_IN addr;
	std::string buf;

	Session(SOCKET sock)
	{
		this->sock = sock;
		addr = { };
		buf.resize(256);
	}
};

void DelWinSock()
{
	WSACleanup();
}

int main()
{
	InitWinSock();
	int ret;

	SOCKET g_hListenSock = socket(AF_INET, SOCK_STREAM, 0);
	list<SOCKET> g_sockList;
	sockaddr name;
	SOCKADDR_IN sa = { };
	//ret = inet_pton(AF_INET, "192.168.0.12", &sa.sin_addr.s_addr);

	sa.sin_addr.s_addr = INADDR_ANY;
	sa.sin_port = htons(10000);
	sa.sin_family = AF_INET;

	int namelen = sizeof(sa);

	ret = bind(g_hListenSock, reinterpret_cast<sockaddr*>(&sa), namelen);
	ret = listen(g_hListenSock, SOMAXCONN);

	u_long iNonSocket = TRUE;
	int iMode = ioctlsocket(g_hListenSock, FIONBIO, &iNonSocket);
	SOCKET clientSock = INVALID_SOCKET;
	SOCKADDR_IN addr = { };
	int addrlen = sizeof(addr);


	while (1)
	{
		clientSock = accept(g_hListenSock, reinterpret_cast<sockaddr*>(&addr), &addrlen);

		if (clientSock == INVALID_SOCKET)
		{
			int iError = WSAGetLastError();

			if (iError != WSAEWOULDBLOCK)
				break;
		}
		else
		{
			std::cout << "접속 ip =" << inet_ntoa(addr.sin_addr) << " port : " << ntohs(addr.sin_port) << std::endl;
			g_sockList.emplace_back(clientSock);
		}

		for (auto iter = g_sockList.begin(); iter!=g_sockList.end(); ++iter)
		{
			char buf[256] = { 0, };
	
			int recvByte;
			int sendByte;
			recvByte = recv(*iter, buf, strlen(buf), 0);
			sendByte = send(*iter, buf, strlen(buf), 0);

			if (recvByte <= 0)
			{
				int iError = WSAGetLastError();

				if (iError == WSAEWOULDBLOCK)
				{
					continue;
				}
				else
				{
					closesocket(*iter);
					g_sockList.erase(iter);
					std::cout << "종료 ip =" << inet_ntoa(addr.sin_addr) << " port : " << ntohs(addr.sin_port) << std::endl;
					continue;
				}
			}
		}
	}

	closesocket(clientSock);
	closesocket(g_hListenSock);
	DelWinSock();
}