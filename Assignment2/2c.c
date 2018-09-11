#include <stdio.h>
#include <pthread.h>

void *thFunc(void* arg){
	printf("HELLO WORLD\n");
}
int main(){
	pthread_t tid;
	pthread_create(&tid,NULL,thFunc,NULL);
	pthread_join(tid,NULL);
	return 0;
}
