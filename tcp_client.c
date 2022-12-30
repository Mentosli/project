#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
 
void test_connect()
{
	unsigned short port = 8000;        		
	char *server_ip = "192.168.43.237";    	
	
	int sockfd;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		perror("socket");
		exit(-1);
	}
	
	struct sockaddr_in server_addr;
	bzero(&server_addr,sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	inet_pton(AF_INET, server_ip, &server_addr.sin_addr);
	
	int err_log = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));     
	if(err_log != 0)
	{
		perror("connect");
		close(sockfd);
		exit(-1);
	}
	
	printf("err_log ========= %d\n", err_log);
	
	char send_buf[100]="Hello";
	send(sockfd, send_buf, strlen(send_buf), 0);  

}
 
int main(int argc, char *argv[])
{
	pid_t pid;
	pid = fork();
	
	if(0 == pid){
 
		test_connect();	
		
		pid_t pid = fork();
		if(0 == pid){
			test_connect();	
		
		}else if(pid > 0){
			test_connect();
		}
		
	}else if(pid > 0){
		
		test_connect();	
		
		pid_t pid = fork();
		if(0 == pid){
			test_connect();
		
		}else if(pid > 0){
			test_connect();	
		}
	
	}
 
	while(1);
	
	return 0;
}