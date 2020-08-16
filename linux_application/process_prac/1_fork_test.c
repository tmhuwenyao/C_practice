#include <unistd.h>
#include <sys/types.h>
int main(void)
{
	pid_t ret ;
	/*调用fork函数*/ 
	ret = fork();
	/*通过ret的值来判断fork()函数的返回情况，首先进行错误处理*/
	if(-1 == ret) 
	{
		perror("fork error");
		return -1;
	}
	else if(0 == ret)  //返回值为0，表示子进程
	{
		printf("in child process  ret is %d ,my pid is %d \n",ret,getpid());
	}
	else  //返回值大于0，表示父进程
	{
		printf("in parent process ,ret is %d ,my pid is %d \n",ret,getpid());
	}
	return 0;
}