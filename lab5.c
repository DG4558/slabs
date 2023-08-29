#include<stdio.h> 
#include<unistd.h>
#include<fcntl.h>
int main(void){
	int fd1, fd2, fd3 ,fd4 ,fd5;
	fd1=open("f1", O_RDWR | O_CREAT);
	fd2=open("f2", O_RDWR | O_CREAT);
	fd3=open("f3", O_RDWR | O_CREAT);
        fd4=open("f4", O_RDWR | O_CREAT);
        fd5=open("f5", O_RDWR | O_CREAT);
	for(;;);
}


