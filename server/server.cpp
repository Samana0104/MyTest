#define _WINSOCK_DEPRECATED_NO_WARNINGS 
#include <iostream>
#include <string>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main()
{
	sockaddr_in addr1, addr2;
	string str_ptr;
	string str_arr;
	char* a, *b;

	addr1.sin_addr.s_addr = htonl(0x1020304);
	addr2.sin_addr.s_addr = htonl(0x1010101);

	a = inet_ntoa(addr1.sin_addr);
	b = inet_ntoa(addr2.sin_addr);
	return 0;
}