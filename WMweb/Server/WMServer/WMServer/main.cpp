#include "winsock.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#pragma comment (lib,"wsock32")

void main() {
	WSADATA wsadata;
	WORD wVersion = MAKEWORD(2, 0);
	if (WSAStartup(wVersion, &wsadata) != 0) {
		printf("initalize failed!/n");
		WSACleanup();
		exit(1);
	}

	int sock, csock, length;
	length = sizeof(struct sockaddr);

	struct sockaddr_in server_ipaddr, client_ipaddr;
	memset(&server_ipaddr, 0, length);
	server_ipaddr.sin_family = AF_INET;
	server_ipaddr.sin_port = htons(4497);
	server_ipaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	char buff[4096]; int nbuff;
	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (bind(sock, (struct sockaddr *)&server_ipaddr, length) == SOCKET_ERROR) {
		printf("Bind error/n");
		WSACleanup();
		exit(1);
	}
	if (listen(sock, 5) == SOCKET_ERROR) {
		printf("Listen error/n");
		WSACleanup();
		exit(1);
	}

	char headers[1000];
	char hdrFmt[] =
		"HTTP/1.0 200 OK/r/n"
		"Server: MySocket Server/r/n"
		"Date: %s/r/n"
		"Content-Type: text/html/r/n"
		"Accept-Ranges: bytes/r/n"
		"Content-Length: %d/r/n/r/n";
	char responseStr[] = "false";
	char strGmtNow[] = "08/15/14 22:53:00 GMT";
	sprintf(headers, hdrFmt, (const char*)strGmtNow, strlen(responseStr));

	while (1) {
		csock = accept(sock, (struct sockaddr *)&client_ipaddr, &length);
		if (csock == SOCKET_ERROR) {
			printf("Listen error/n");
			WSACleanup();
			exit(1);
		}
		nbuff = recv(csock, buff, 4095, 0);
		buff[nbuff] = '\0';
		printf("%s", buff);
		strcat(headers, responseStr);
		send(csock, headers, strlen(headers), 0);
		//send(csock, responseStr, strlen(responseStr), 0);
		closesocket(csock);
	}

}