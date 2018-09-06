#include <sys/signal.h>
#include <stdio.h>
int main(){
	int x;
	printf("Enter pid: ");
	scanf("%d",&x);
	printf("ret %d",kill(x,SIGKILL));
	return 0;
}
