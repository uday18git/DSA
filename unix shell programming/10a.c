#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<syslog.h>
void create_daemon(){
	pid_t pid, sid;
	pid = fork();
	printf("Initializing deamon");
	if(pid<0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	if(pid>0)
	{
		printf("Praent process exiting");
		exit(EXIT_SUCCESS);
	}
	printf("Child process (daemon) started");
	if(setsid()<0){
		perror("set fialed");
		exit(EXIT_FAILURE);
	}
	umask(0);
	if((chdir("/"))<0)
	{
		exit(EXIT_FAILURE);
	}
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
}
int main()
{
	create_deamon();
	openlog("daemon_example",LOG_PID,LOG_DAEMON);
	while(1){
		
}



