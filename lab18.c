#include<sys/types.h>
#include<sys/stat.h>
#include<sys/select.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>



int main()
{
	int i,fd;
	struct {
		int train_num;
		int train_ticket;
		int ticket_count;
	}db[3];
for(i=0;i<3;i++)
{
	db[i].train_num=i+1;
	db[i].ticket_count=0;
}

fd=open("record.txt",O_RDWR);
write(fd,db,sizeof(db));

int input;
 fd=open("record.txt",O_RDWR);
 printf("\nSelect train no:");
 scanf("%d",&input);
 
 struct flock lock;
 lock.l_type=F_WRLCK;
 lock.l_whence=SEEK_SET;
 lock.l_start=(input-1)*sizeof(db);
 
 lock.l_len=sizeof(db);
 lock.l_pid=getpid();
 
 lseek(fd,(input-1)*sizeof(db),SEEK_SET);
 
 read(fd,&db,sizeof(db));
 
 printf("\nBefore critical sec");
 db->ticket_count++;
 
 lseek(fd,-1*sizeof(db),SEEK_CUR);
 write(fd,&db,sizeof(db));
 
 printf("\nTo book ticket press enter");
 getchar();
 
 getchar();
 
 lock.l_type=F_UNLCK;
 
 fcntl(fd,F_SETLK,&lock);
 
 printf("\nTicket booked %d",db->ticket_count);
 
 return 0;
 }
