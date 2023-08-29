/* Write a prog to open a file in read only mode and read line by line and display each line as read.close file when EOF reached*/


#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

 

 int main() {
    
    char buf[512];
     
    int f = open("testfile.txt", O_RDONLY);
    if(f== -1)
        printf("Error in opening file");


    while(read(f, &buf, sizeof(buf))){
        printf("%s",buf);
    }

     
    close(f);
    return 0;
}
