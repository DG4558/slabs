#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int f= open("testfile.txt", O_RDWR | O_CREAT | O_EXCL);
	if(f==0)
	{
		printf("already has file");
	}
        printf("f= %d\n", f);
	if(f<0)
	{
		perror("Error");
	}
	return 0;
}	
