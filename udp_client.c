#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define SERVER_PORT 5000
int main()
{
	
	int sock = 0;
	struct sockaddr_in addr;
	int addrlen = sizeof(addr);
	char msg[64] = {0};
	char buf[64] = {0};
	
	sock = socket (AF_INET, SOCK_DGRAM,0);
	
	while(1)
	{
	printf("输入向服务器发送的消息：\n");
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(SERVER_PORT);
	addr.sin_addr.s_addr = inet_addr ("192.168.43.237");
	
	sendto(sock, msg, strlen(msg), 0,(struct sockaddr *)&addr,addrlen);
	recvfrom(sock,buf, sizeof(buf), 0,(struct sockaddr *)&addr, &addrlen);
	printf("服务器应答： %s\n",buf);
   }
	return 0;
	
}
