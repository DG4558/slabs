#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int filedp=open("testfile.txt",O_RDWR|O_CREAT,0644);
	if(filedp==-1)
	{
		printf("Error opening file");
		return 1;
	}
	
	//writing 10 bytes
	write(filedp,"123456789a",10);
	
	off_t newpos=lseek(filedp,10,SEEK_CUR);
	
	if(newpos==-1)
	{
		printf("\nError movind file pointer");
		close(filedp);
		return 1;
	}
	
	printf("\nNew file pointer position:%ld\n",newpos);
	
	write(filedp,"1234567891",10);
	
	 close(filedp);
	 
	  system("od -c testfile.txt");
	  return 0;
	 
	 }
	
