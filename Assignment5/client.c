#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buf{
	long msg_type;
	char msg_text[100];
}message;

int main(){
	key_t key;
	int msgId;

	key=ftok("progfile",65);

	msgId = msgget(key, 0666 | IPC_CREAT);

	msgrcv(msgId, &message, sizeof(message), 1, 0);

	printf("Data recieved is : %s \n", message.msg_text);

	//destroy the queue
	msgctl(msgId, IPC_RMID, NULL);
	return 0;
}
