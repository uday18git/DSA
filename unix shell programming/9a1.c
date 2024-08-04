#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
int main()
{
	mode_t mask;
	mask = umask(0);
	printf("Current umask value: %03o\n",mask);
	umask(023);	
	printf("new umask value: 077");
	return 0;
}

