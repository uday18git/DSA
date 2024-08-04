#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
int main()
{
	const char *filename = "example.txt";
	mode_t mode = 0644;
	if(creat(filename,mode)<0)
	{
		perror("creat");
		exit(EXIT_FAILURE);
	}
	printf("File %s created with mode 0644\n",filename);
	if(chmod(filename,0755)<0)
	{
		perror("chmod");
		exit(EXIT_FAILURE);
	}
	printf("Changed permission of '%s' to 0755\n",filename);
	return 0;
}
