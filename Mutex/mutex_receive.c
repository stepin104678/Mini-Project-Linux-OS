#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h> 
#include <sys/msg.h> 

pthread_t my_thread[5];
pthread_mutex_t lock;
int time1=1, time2=2;

struct msg_buff { 
	char mesg_text[100]; 
} message; 

void* m_receiver(void *arg)
{
	key_t key; 
	int msgid; 
	
	// ftok to generate unique key 
	key = ftok("progfile", 65); 

	// msgget creates a message queue and returns identifier 
	msgid = msgget(key, 0666 | IPC_CREAT); 
	
	// Locking
	pthread_mutex_lock(&lock);

	// msgrcv to receive message 
	msgrcv(msgid, &message, sizeof(message), 1, 0); 

	// Display the message 
	printf("The no. buses entering the bus stand from %d to %d: %s\n",time1, time2, message.mesg_text); 
	time1++;
	time2++;

	// Unlock
	pthread_mutex_unlock(&lock);    
	return NULL;
}


int main(void)
{
    int i=0, err;

    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }

    while(i < 5)
    {
        err = pthread_create(&(my_thread[i]), NULL, &m_receiver, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        i++;
    }

    pthread_join(my_thread[0], NULL);
    pthread_join(my_thread[1], NULL);
    pthread_join(my_thread[2], NULL);
    pthread_join(my_thread[3], NULL);
    pthread_join(my_thread[4], NULL);
    pthread_mutex_destroy(&lock);

    return 0;
}
