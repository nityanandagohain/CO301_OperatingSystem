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

	//Gen unique key
	key = ftok("progfile",65);

	//create queue and identifer stored
	msgId = msgget(key, 0666 | IPC_CREAT);
	message.msg_type = 1;

	printf("Enter Data: ");
	gets(message.msg_text);

	//send to the queue
	msgsnd(msgId, &message, sizeof(message), 0);

	//display the message
	printf("SENT: %s \n", message.msg_text);

	return 0;
}
