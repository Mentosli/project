#include <stdio.h>
#include <pthread.h>

//用来测试create_task接口
//测试无误提交代码前屏蔽main函数
int main ()
{
	int id1, id2;
	
	//创建任务，测试任务能并发运行
	create_task(mytask1);
	create_task(mytask2);
	
	while(1)
	{
		sleep(1);
	}
	
	return 0;
}

//创建多任务：返回创建好的任务id
//task为任务执行函数
//arg为task函数的参数
int create_task(void*(*task)(void*), void* arg)
{
	int ret = 0;
	int id = 0;
	
	ret = pthread_create(&id, NULL, (void*)task, arg);
    if (ret != 0)
    {
        printf("Create pthread error!\n");
        return -1;
    }
	
	return id;
}
