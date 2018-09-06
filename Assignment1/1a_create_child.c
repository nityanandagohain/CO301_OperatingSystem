/*Write a C program to create a child process using the system
call fork( ) and from the child process, display the PID and PPID and
also display the same from parent process. Demonstarte the use of
exit(0) and exit(1).*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(){
	int x = fork();
	if(x == 0){
		//In child procress
		printf("In child:  pid: %d , ppid: %d\n",getpid(),getppid());
		exit(0);
	}else if(x > 0 ){
		//In Parent procress
		printf("In Parent: pid: %d , ppid: %d\n",getpid(),getppid());
		exit(0);
	}else {
		//Fork not executed successfully
		printf("Fatal fork not executed\n");
		exit(1);
	}
	return 0;
}
