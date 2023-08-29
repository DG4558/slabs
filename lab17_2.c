#include<sys/types.h>
#include<sys/stat.h>
#include<sys/select.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>





int main() {

struct flock lock; 
int fd; 


struct
{ int ticket_no;
} db;


db.ticket_no = 10; 
fd = open("db",O_CREAT|O_RDWR, 0744); 
write(fd, &db,sizeof(db)); 
close(fd);
 fd = open("db",O_RDONLY); 
 read(fd, &db, sizeof(db));
printf("\nTicket no: %d\n",db.ticket_no);
 close(fd);

fd = open("db", O_RDWR);

printf("\nBefore entering into critical");
fcntl(fd, F_SETLKW, &lock);
printf("\nInside the critical section\n");

read(fd, &db, sizeof(db)); 
printf("\nCurrent ticket number: %d\n", db.ticket_no); 
db.ticket_no++;

lseek(fd, 0, SEEK_SET); 
write(fd, &db, sizeof(db));

printf("\nPress enter to unlock\n"); 
getchar();

lock.l_type = F_UNLCK;
fcntl(fd, F_SETLK, &lock);
printf("\nExited critical section\n");

return 0;

}

