#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
#include <sys/ipc.h> 
#include <sys/msg.h>
#include <string.h>

sem_t s; 
int time1=1, time2=2;

struct mesg_buffer { 
	char mesg_text[100]; 
} message;

void* s_sender(void* arg) 
{ 
	key_t key; 
	int msgid;

	// ftok to generate unique key 
	key = ftok("progfile", 65); 

	// msgget creates a message queue 
	// and returns identifier 
	msgid = msgget(key, 0666 | IPC_CREAT); 

	//wait 
	sem_wait(&s); 

	printf("Enter the no. buses entering the bus stand from %d to %d: ",time1,time2); 
	time1++;
	time2++;

	scanf("%s", message.mesg_text);
	// msgsnd to send message 
	msgsnd(msgid, &message, sizeof(message), 0); 
	
	sem_post(&s); 
} 


int main() 
{ 
	int err, i=0;
	sem_init(&s, 0, 1); 

	pthread_t my_thread[5];

	while(i < 5)
    {
		err = pthread_create(&(my_thread[i]), NULL, &s_sender, NULL);
        if (err != 0)
            printf("\nThread creation failed :[%s]", strerror(err));
        i++;
    }
	
	pthread_join(my_thread[0], NULL);
    pthread_join(my_thread[1], NULL);
    pthread_join(my_thread[2], NULL);
    pthread_join(my_thread[3], NULL);
    pthread_join(my_thread[4], NULL);

	sem_destroy(&s); 
	return 0; 
} 

