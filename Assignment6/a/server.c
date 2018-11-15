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
        msg = (char*)shmat(shmid,(void*)0,0);

        printf("Enter message to send: ");
        gets(msg);
        printf("Data sent to shared memory: %s\n",msg);

        shmdt(msg);
        return 0;
}
