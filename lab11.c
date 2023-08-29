#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include<string.h>
int main(){


	int f = open("testfile.txt", O_WRONLY | O_APPEND);
	
	if(f< 0)
		printf("Error opening the file\n");
	


	int copy_f= dup(f);
		
	

	write(copy_f,"This will be written by new file descriptor to the file named testfile.txt\n", strlen("This will be written by new file descriptor to the file named testfile.txt\n"));
		
	write(f,"This will be written by old file descriptor to the file named testfile.txt\n",strlen("This will be written by old file descriptor to the file named testfile.txt\n"));

	int file_d = open("dup2.txt",O_WRONLY | O_APPEND);
      

        dup2(file_d, 1) ; 
          
        
        printf("Hello how are you!...\n");

	
	return 0;
}
