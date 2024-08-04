#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
int main(int argc,char* argv[])
{
	int fd;
	char buffer[51];
	struct flock fvar;
	if(argc!=2)
	{
		printf("Usage: %s filename\n",argv[0]);
		return -1;
	}
	if((fd=open(argv[1],O_RDWR))==-1)
	{
		perror("open");
		exit(1);
	}
	fvar.l_type =F_WRLCK;
	fvar.l_whence=SEEK_END;
	fvar.l_start = -100;
	fvar.l_len=100;
	printf("Press enter to set lock\n");
	getchar();
	printf("Trying to get lock...\n");
	if(fcntl(fd,F_SETLK,&fvar)==-1)
	{
		fcntl(fd,F_GETLK,&fvar);
		printf("\n file already locked by process (pid): %d\n",fvar.l_pid);
		close(fd);
		return -1;
	}
	printf("Locked");
	if(lseek(fd,-50,SEEK_END)==-1)
	{
		perror("lseek");
		close(fd);
		exit(1);
	}
	ssize_t bytes_read = read(fd,buffer,50);
	if(bytes_read ==-1)
	{
		perror("read");
		close(fd);
		exit(1);
	}
	buffer[bytes_read] = '\0';
	printf("Data read from file:\n");
	puts(buffer);
	printf("press enter to release lock"\n);
	getchar();
	fvar.l_type = F_UNLCK;
	
