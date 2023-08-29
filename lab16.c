#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

int main()
{
	struct flock lock;
	int fd;
	lock.l_start=0;
	lock.l_len=0;
	lock.l_whence=SEEK_SET;
	lock.l_pid=getpid();
	lock.l_type=F_WRLCK;
	fd=open("lseek.txt",O_RDWR);
	printf("\nBefore critical sec:\n");
	int gotlck=fcntl(fd,F_SETLKW,&lock);
	if(gotlck==-1)
	{
		printf("\nError");
	}
	else
	{
		printf("write lock acquired:\n");
	}
	printf("\nPress any key to release lock");
	getchar();
	lock.l_type=F_UNLCK;
	gotlck=fcntl(fd,F_SETLK,&lock);
	printf("\nReleasing write lock\n");
	
	printf("\nBefore critical sec:\n");
	lock.l_type=F_RDLCK;
	 gotlck=fcntl(fd,F_SETLKW,&lock);
	if(gotlck==-1)
	{
		printf("\nError");
	}
	else
	{
		printf("\nRead lock acquired:\n");
	}
	printf("\nPress any key to release lock");
	getchar();
	lock.l_type=F_UNLCK;
	gotlck=fcntl(fd,F_SETLK,&lock);
	printf("\nReleasing readlock\n");
	
	close(fd);
}
