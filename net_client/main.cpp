#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
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

int main()
{
	InitWinSock();
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN sa;
	sa.sin_addr.s_addr = inet_addr("192.168.0.12");
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
	recvMsg.reserve(256);

	std::cout << "실행" << endl << endl;

	while (1)
	{
		sendMsg.clear();
		recvMsg.clear();
		std::getline(std::cin, sendMsg);
		output = "[변한빛] : " + sendMsg;
		std::cout << output << endl;
		
		sendByte = send(sock, output.c_str(), output.size(), 0);
		recvByte = recv(sock, &recvMsg[0], recvMsg.size(), 0);

		if (recvByte <= 0)
		{
			int iError = WSAGetLastError();

			if (iError != WSAEWOULDBLOCK)
			{
				std::cout << "서버 종료" << endl;
				break;
			}
		}

		if (sendMsg.compare("종료") == 0)
			break;
		
		if(recvByte > 0)
			std::cout << "받고 : " << recvMsg << endl;
	}

	closesocket(sock);
	DelWinSock();
	std::cout << "종료" << endl;
}