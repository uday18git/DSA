#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
int main()
{
	DIR *dp;
	struct dirent *dir;
	int n,fd;
	dp = opendir(".");
	if(dp)
	{
		while((dir = readdir(dp))!=NULL)
		{
			fd = open(dir->d_name,O_RDWR,0777);
			n = lseek(fd,0,SEEK_END);
			if(!n)
			{
				unlink(dir->d_name);
			}
		}
	}
}
