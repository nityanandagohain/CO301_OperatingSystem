#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	int x = fork();
	if(x==0){
		//In child procress 
		//A null terminated array of pointers
		printf("Child : \n");
		//compile the subprogram before gcc 1c_asset.c -o 1c_asset
		char *args[]={"./1c_asset",NULL};
		execv(args[0],args);
	}else if(x>0){
		wait(NULL);
		printf("Parent : \n");
	}else{
		printf("FATAL ERROR");
	}
	return 0;
}
