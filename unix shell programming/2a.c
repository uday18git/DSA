#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	    if(argc != 2)    
		            return 1;

	        struct stat fileStat;
		    if(stat(argv[1],&fileStat) < 0)    
			            return 1;

		        printf("Information for %s\n",argv[1]);
			    printf("---------------------------\n");
			        printf("File Size: \t\t%ld bytes\n",fileStat.st_size);
				    printf("Number of Links: \t%ld\n",fileStat.st_nli:wq printf("File inode: \t\t%ld\n",fileStat.st_ino);

					   
}
