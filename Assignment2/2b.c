#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle();
int main(){
	if(signal(SIGINT, handle)==SIG_ERR){
		printf("\n FATAL ERROR");
	}
	while(1){
		sleep(1);
	}
	return 0;
}

void handle(){
	int p=fork();	
	if(p==0){
		printf("Child: pid = %d ppid = %d\n", getpid(),getppid());
		while(1)
			sleep(1);
	}else if(p>0){
		printf("Parent: pid = %d ppid = %d\n", getpid(),getppid());
	}else{
		printf("Not created");
		exit(1);
	}
}
