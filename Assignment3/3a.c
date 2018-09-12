#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void handle();
int main(){

	if(signal(SIGINT, handle)==SIG_ERR){
		printf("\n FATAL ERROR");
	}
	while(1)
		sleep(0);
	return 0;
}

void handle(){
	int N;
	pid_t p;
	int mypipefd[2];
	int ret;
	char buff[20];
	printf("Enter the value of N : ");
	scanf("%d",&N);

	ret = pipe(mypipefd);
	/* pipe[0] refers to read end of the file
	   pipe[1] refers to write end of the file
	 */
	if(ret == -1){
		perror("pipe error");
		exit(1);
	}
	long int i,j,k;
	int x;
	char temp[5];
	p=fork();	
	if(p==0){
		/*Child Process*/
		fflush(stdin);
		printf("In child: \n");
		close(mypipefd[0]);
		/*Sending PID*/
		strcpy(buff,"child PID:");
		sprintf(temp,"%d",getpid());
		strcat(buff,temp);
		write(mypipefd[1],buff,20);
		/* Computing Fibonacci*/
		i=1;
		j=1;
		x=0;
		write(mypipefd[1],"1",20);
		write(mypipefd[1],"1",20);
		N-=2;
		while(x<N){
			x++;
			k=i+j;
			i=j;
			j=k;
			sprintf(buff,"%ld",k);
			write(mypipefd[1],buff ,20);
		}
		j=0;i=0;k=0;
		close(mypipefd[1]);
	}else if(p>0){
		/*Parent Process*/
		fflush(stdin);
		printf("In Parent: \n");
		close(mypipefd[1]);
		while(read(mypipefd[0], buff, sizeof(buff))>0){
			printf("rec: %s\n",buff);
		}
		close(mypipefd[0]);
	}else{
		printf("Not created");
		exit(1);
	}
}
