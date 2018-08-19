/*write a  C program like the assignment 1(a). But here use the
  system call wait() system to synchronize the execution of parent
  program in your program until child process finishes.*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
	int x = fork();
	if(x == 0){
		//In child procress
		printf("In child:  pid: %d , ppid: %d\n",getpid(),getppid());
		exit(0);
	}else if(x > 0 ){
		//In Parent procress
		wait(NULL); //waits for the child procress to complete and then executes
		printf("In Parent: pid: %d , ppid: %d\n",getpid(),getppid());
		exit(0);
	}else {
		//Fork not executed successfully
		printf("Fatal fork not executed\n");
		exit(1);
	}
	return 0;
}
