#include<stdio.h>
#include"queue.h"
#include<string.h>
int main()
{
	Queue *que = NULL;
	char op = 0;
	T msg;
	
	que = CreateQueue();
	printf("请选择你需要的队列操作：\n");
	printf("1:进队\n");
	printf("2:出队\n");
	printf("3:显示\n");
	
	scanf("%c",&op);
	
	switch(op)
	{
		case 1:
			memset(msg, 0, sizeof(msg));
			printf("请输入进队的消息：\n");
			scanf("%s", msg);
			Push(que, msg);
			break;
			case 2:
				memset(msg, 0, sizeof(msg));
				Pop(que, msg);
				break;
				case 3:
					Print(que);
					break;
					default:
						printf("你输入的选项无效！\n");
						break;
	}
	return 0;
}