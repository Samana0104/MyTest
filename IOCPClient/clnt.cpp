#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
#include <cstring>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

#define BUF_SIZE 1024
void ErrorHandling(const char *message);

int main()
{
	WSADATA wsaData;
	SOCKET hSocket;
	SOCKADDR_IN servAdr;
	char message[BUF_SIZE];
	int strLen, readLen;

	if(WSAStartup(MAKEWORD(2, 2), &wsaData)!=0)
		ErrorHandling("WSAStartup() error!"); 

	hSocket=socket(PF_INET, SOCK_STREAM, 0);   
	if(hSocket==INVALID_SOCKET)
		ErrorHandling("socket() error");
	
	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family=AF_INET;
	servAdr.sin_addr.s_addr = inet_addr("127.0.0.1");
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

		strLen= std::strlen(message);
		send(hSocket, message, strLen, 0);

		readLen=0;
		while(1)
		{
			readLen+=recv(hSocket, &message[readLen], BUF_SIZE-1, 0);
			if(readLen>=strLen)
				break;
		}
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
