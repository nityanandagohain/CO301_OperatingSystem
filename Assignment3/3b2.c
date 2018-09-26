#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	int fd;
	char s[30];

	char *myfifo = "/tmp/myfifo";

	mknod(myfifo,0666,0);

	fd = open(myfifo,O_WRONLY);
	printf("Message for Program 1 = ");
	fgets(s,30,stdin);                                                                                          
	write(fd,s,strlen(s)+1);
	close(fd);

	strcpy(s,"");

	while(strlen(s)<=0){
		sleep(3);
		fd = open(myfifo,O_RDONLY);
		read(fd,s,30);
		close(fd);
	}
	printf("Program 1 :\n");
	printf("Message from Program 1 = %s\n",s);

	return 0;
}

