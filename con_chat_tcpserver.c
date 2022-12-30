#include <stdio.h>

//聊天任务声明
void *chatfunc(void* arg);

int main ()
{	
	//1. 创建TCP socket
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	//2. 绑定IP地址与端口号
	bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr))
	//3. 创建监听客户端连接队列
	listen(sockfd, 10);

	while(1)
	{		
		//4. 等待并建立客户端的连接
		connfd = accept(sockfd, (struct sockaddr*)&clientaddr,socklen_t addrlen);
	
		//5. 为已连接客户端创建聊天任务
		create_task(chattask, (void*)&connfd);
	}
	
	close(sockfd);
	
	return 0;
}

//聊天任务实现
void *chatfunc(void* arg)
{
	int connfd = *(int*)arg; //连接套接字
	
	while(1)
	{
		//接收对方聊天信息
		recv(connfd, buf, sizeof(buf), 0);
		printf("from server: %s\n", buf);
		
		//发送本方聊天信息
		printf("please chat:");
		scanf("%s", msg);
		send(connfd, msg, strlen(msg), 0);	
	}
	
	close(connfd);
}
