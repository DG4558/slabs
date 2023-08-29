#include<sys/types.h>
#include<sys/stat.h>
#include<sys/select.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
    int returnval;
    fd_set rd;
    struct timeval t;
    
    FD_ZERO(&rd);
    FD_SET(0,&rd);
   

    t.tv_sec =10;
    printf("please wait for 10 seconds\n");
    returnval = select(2, &rd, NULL, NULL, &t);
 
   
    if (returnval == -1)
         perror("select()");
    else if (returnval)
         printf("Data is available now.\n");
         
    else
         printf("your time is over thanks!....\n");

   return 0;

}
