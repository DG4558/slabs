/*Write a prog to take i/p from stdin and display on stdout using read/write system calls*/


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main()
{
    char buf[512];
    
    
    //Taking input from stdin
    
    
    
    read(0, buf, 32);
    
    //Writing output to stdout
    
    printf("\nThe output is:\n");
    write(1, buf, 32);
    return 0;
}
