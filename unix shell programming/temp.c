#include <stdio.h>
#include <unistd.h>

int main() {
	    pid_t pid = fork();

	        if (pid == -1) {
			        perror("Error forking");
				        return 1;
					    }

		    if (pid == 0) {
			            printf("Child process\n");
				        } else {
						        printf("Parent process\n");
							    }

		        return 0;
}

