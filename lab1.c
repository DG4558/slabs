#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
	int a=symlink("testfile.txt","bba");
	printf("%d",a);
	if(a<0)
	{perror("Failed");
	return 1;
	}

	int f=link("testfile.txt","aab");
	  if(f<0)
	  {perror("Failed");
	  }

	int b= mknod("ababa",S_IFIFO,0);

	if(b<0)
		perror("Failed");
		
	return 0;
}	
