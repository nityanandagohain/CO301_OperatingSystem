#define _POSIX_SOURCE
#include <sys/times.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>

int main(){

	int status;
	long i, j;
	struct tms t;
	clock_t duration;
	int tics_per_second = sysconf(_SC_CLK_TCK);

	if (fork() == 0) {
		for (i=0, j=0; i<100000000; i++)
			j += i;
		exit(0);
	}
	if (wait(&status) == -1)
		perror("wait() error");
	else if (!WIFEXITED(status))
		puts("Child did not exit successfully");
	else if ((duration = times(&t)) == -1)
		perror("times() error");
	else {
		printf("parent:    usertime: %f       system time: %f\n",
				((double) t.tms_utime)/tics_per_second,
				((double) t.tms_stime)/tics_per_second);
		printf("child:     usertime: %f        systemtime: %f\n",
				((double) t.tms_cutime)/tics_per_second,
				((double) t.tms_cstime)/tics_per_second);
	} 

}
