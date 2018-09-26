#include <stdio.h>      /*************  Read Lock Setter  *************/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	struct flock lock, savelock;
	int fd;
	
	FILE *fp = fopen("xyz.txt","r");
	while(!feof(fp)){
		printf("%c",fgetc(fp));
	}

	fd = open("xyz.txt", O_RDONLY);
	lock.l_type = F_RDLCK;
	lock.l_start = 0;
	lock.l_whence = SEEK_SET;
	lock.l_len = 0;
	savelock = lock;
	fcntl(fd, F_GETLK, &lock);
	if (lock.l_type == F_WRLCK)
	{
		printf("File is write-locked by process %ld.\n", lock.l_pid);
		exit(1);
	}
	fcntl(fd, F_SETLK, &savelock);
	printf("File locked\n");
	getchar();
	printf("Unlocking\n");
	savelock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &savelock);
	getchar();
	return 0;
}
