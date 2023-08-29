#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include<string.h>
int main(){
	
	const char *fn = "lab12.c"; 

       
        int fd= open(fn,O_RDWR);
        if (fd == -1) {
        perror("Error opening file");
        return 1;
         }

        
        int flags = fcntl(fd, F_GETFL) & O_ACCMODE;

	
        if (flags == -1) {
        perror("Error getting file flags");
        close(fd);
        } 
        
        if (flags==0) 
	{
        printf("File is opened in read-only mode.\n");
        }
	else if (flags==1) 
	{
        printf("File is opened in write-only mode.\n");
        } 
	else if (flags==2) 
	{
        printf("File is opened in read-write mode.\n");
        }
	else 
	{
        printf("Unknown file access mode.\n");
        }

        
        close(fd);

    return 0;
}
