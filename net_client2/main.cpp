#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
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

int Sender(SOCKET sock)
{
	return 0;
}

int main()
{
	InitWinSock();
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN sa;
	sa.sin_addr.s_addr = inet_addr("127.0.0.1");
	sa.sin_port = htons(10000);
	sa.sin_family = AF_INET;

	int namelen = sizeof(sa);
	int ret;

	ret = connect(sock, reinterpret_cast<sockaddr*>(&sa), namelen);

	u_long iNonSocket = TRUE;
	int iMode = ioctlsocket(sock, FIONBIO, &iNonSocket);

	int sendByte;
	int recvByte;
	string sendMsg;
	string recvMsg;
	string output;

	sendMsg.reserve(256);
	recvMsg.resize(256);
	std::cout << "실행" << endl << endl;

	while (1)
	{
		sendMsg.clear();
		recvMsg.replace(0, 256, "");
		std::getline(std::cin, sendMsg);
		output = "[변한빛] : " + sendMsg;
		std::cout << output << endl;
		
		sendByte = send(sock, output.c_str(), output.size(), 0);
		recvByte = recv(sock, &recvMsg[0], recvMsg.size(), 0);

		if (recvByte < 0)
		{
			int iError = WSAGetLastError();

			if (iError != WSAEWOULDBLOCK)
			{
				std::cout << "비정상 종료" << endl;
				break;
			}
		}
		else if (recvByte > 0)
		{
			cout << recvMsg << endl;
		}

		if (sendMsg.compare("종료") == 0)
			break;
	}

	closesocket(sock);
	DelWinSock();
	std::cout << "종료" << endl;
}