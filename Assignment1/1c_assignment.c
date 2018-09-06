#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(){
	int x = fork();
	int status;
	if(x==0){
		//In child procress 
		//A null terminated array of pointers
		printf("Child : \n");
		//compile the subprogram before gcc 1c_asset.c -o 1c_asset
		char *args[]={"./1c_asset",NULL};
		execv(args[0],args);
	}else if(x>0){
		wait(&status);
		if(WIFEXITED(status)){
			printf("Child exec successfully\n");
		}else{
			printf("Fatal error");
			exit(1);
		}
		printf("Parent : \n");
	}else{
		printf("FATAL ERROR");
	}
	return 0;
}
