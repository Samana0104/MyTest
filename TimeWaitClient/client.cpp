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

#define BUF_SIZE 1024
void ErrorHandling(const char *message);

int main()
{
	WSADATA wsaData;
	SOCKET hSocket;
	char message[BUF_SIZE];
	int strLen;
	SOCKADDR_IN servAdr;

	if(WSAStartup(MAKEWORD(2, 2), &wsaData)!=0)
		ErrorHandling("WSAStartup() error!"); 

	hSocket=socket(PF_INET, SOCK_STREAM, 0);   
	if(hSocket==INVALID_SOCKET)
		ErrorHandling("socket() error");
	
	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family=AF_INET;
	servAdr.sin_addr.s_addr=inet_addr("127.0.0.1");
	servAdr.sin_port=htons(10000);
	
	if(connect(hSocket, (SOCKADDR*)&servAdr, sizeof(servAdr))==SOCKET_ERROR)
		ErrorHandling("connect() error!");
	else
		puts("Connected...........");
	
	while(1) 
	{
		fputs("Input message(Q to quit): ", stdout);
		fgets(message, BUF_SIZE, stdin);
		
		if(!strcmp(message,"q\n") || !strcmp(message,"Q\n"))
			break;

		send(hSocket, message, strlen(message), 0);
		strLen=recv(hSocket, message, BUF_SIZE-1, 0);
		message[strLen]=0;
		printf("Message from server: %s", message);
	}
	
	closesocket(hSocket);
	WSACleanup();
	return 0;
}

void ErrorHandling(const char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
