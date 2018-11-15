#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
        key_t key;
        int shmid;
        char *msg;

        key = ftok("keyFile",65);
        shmid = shmget(key,1024,0666|IPC_CREAT);
        msg = (char *)shmat(shmid,(void *)0,0);

        printf("Data read from shared memory: %s\n",msg);

        shmdt(msg);
        shmctl(shmid,IPC_RMID,NULL);
        return 0;
}