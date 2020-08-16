#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd = -1;
	fd = open("test.txt",O_RDWR|O_CREAT|O_TRUNC,0666);
	if(fd < 0)
	{
		perror("fail to open");
		return -1;
	}
	close(fd);
	return fd;
}