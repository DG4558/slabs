#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
int main()
{

       int c;
       mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
       char *fn= "testfile.txt";
       c = creat(fn, mode);
       int fd = open(fn, O_RDONLY);

       printf("fd = %d\n" , fd);
       if(c<0){
	       perror("Error");
       }
       return 0;

}
