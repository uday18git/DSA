#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

void print_file_flags(int fd);

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		fprintf(stderr,"Usage: %s <file_descrptor>\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	int fd = atoi(argv[1]);

	int flags =fcntl(fd,F_GETFL);
	if(flags==-1)
	{
		perror("fcntl");
		exit(EXIT_FAILURE);
	}
	printf("File descriptor: %d\n",fd);
	printf("File flags:\n");

	switch(flags & O_ACCMODE){
		case O_RDONLY:
			printf("Read only\n");
			break;
		case O_WRONLY:
			printf("Write only\n");
			break;
		case O_RDWR:
			printf(" Read/Write\n");
			break;
		default:
			printf(" Unknown access mode\n");
			break;
	}
	return 0;
}
