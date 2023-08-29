/* write a prog to copy file1 to file2*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc,char* argv[]){
if(argc!=3)
{
	printf("you are useless\n");
	return -1;
}
int fd_read=open(argv[1], O_RDONLY);
int fd_write=open(argv[2],O_WRONLY|O_CREAT);
if(fd_read==-1 || fd_write==-1)
	printf("Your system is useless\n");

while(1){
char buf;
int read_byte=read(fd_read,&buf,1);
if(read_byte==0)
	break;
int write_bytes=write(fd_write,&buf,1);
}
int fd_read_close=close(fd_read);
int fd_write_close=close(fd_write);
if(fd_write_close==-1 || fd_read_close==-1)
	printf("You cant even close a file\n");
return 0;
}

