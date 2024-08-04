// copy from one file to another file 
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#define BUFFER_SIZE 4096
void report_error(const char * message,const char *filename)
{
}
int main(int argc,char* argv[])
{
	const char* src = argv[1];
	const char* dest = argv[2];
	int src_fd,dest_fd;
	ssize_t bytes_read,bytes_written;
	char buffer[BUFFER_SIZE];
	src_fd = open(src,O_RDONLY);
	//dest_fd = open(dest,O_WRONLY | O_CREAT | O_TRUNC,0644);
	dest_fd = open(dest,O_WRONLY);
	while((bytes_read = read(src_fd,buffer,BUFFER_SIZE))>0)
	{
		bytes_written= write(dest_fd,buffer,bytes_read);
		}
	return EXIT_SUCCESS;
	
}
