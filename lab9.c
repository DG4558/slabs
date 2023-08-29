#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include <sys/sysmacros.h>
#include <time.h>
int main(){


   struct stat sfile;
   stat("qus1.c", &sfile);


 
  printf("\ninode number:%ld",sfile.st_ino);
  printf("\nsize of the file:%ld",sfile.st_size);
  printf("\ntotal number of hard link:%lu", sfile.st_nlink);
  printf("\nuserid:%d", sfile.st_uid);
  printf("\nblock size:%ld", sfile.st_blksize);
  printf("\ngroup id:%d", sfile.st_gid);
  printf("\ntotal number of blocks:%ld", sfile.st_blocks);
  printf("\ntime of last access:%ld", sfile.st_atime);
  printf("\ntime of recent modification:%ld", sfile.st_mtime);
  printf("\ntime of last change:%ld\n",sfile.st_ctime);
}
