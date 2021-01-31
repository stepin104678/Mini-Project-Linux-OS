## Badges
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/06f57ff9c1124867a789516ea1d17f32)](https://app.codacy.com/gh/stepin104678/Mini-Project-Linux-OS?utm_source=github.com&utm_medium=referral&utm_content=stepin104678/Mini-Project-Linux-OS&utm_campaign=Badge_Grade)
![C/C++ CI](https://github.com/stepin104678/Mini-Project-Linux-OS/workflows/C/C++%20CI/badge.svg)
![cppcheck-action](https://github.com/stepin104678/Mini-Project-Linux-OS/workflows/cppcheck-action/badge.svg)

# LINUX MINIPROJECT

The aim of the project is to create a bus tracking system in the bus stand in which the input of how many buses coming inside the bus stand at a particular time frame (1 hour) is given and send to the receiver. We are using a structure as a data type which holds the message type and no.of buses. This object is input through the mutex_send.c/sem_send.c and reaches the mutex_receive.c/sem_receive.c through IPC. This IPC is used in Mutex and Semaphore methods and the objects gets locked and unlocked during the critical section of the execution.

## Mutex with Message Queue : Refer to mutex_send.c and mutex_receive.c

    pthread_mutex_lock(&lock); is used for locking.
    pthread_mutex_unlock(&lock); is used for unlocking.
    pthread_mutex_destroy(&lock); is used for destroying.
    
## Semaphore with Message Queue : Refer to sem_send.c and sem_receive.c

    sem_wait(&s) for lock/wait.
    sem_post(&s) for releasing the lock.
    sem_destroy(&s) for destroying.

**********************************************************************************************************************************************************************
## IMPLEMENTATION

### MUTEX
1) Goto the Mutex folder	    -   cd Mutex
2) Run the makefile		        -	make
3) Run the sender object file 	-> 	./send.out
4) Give 5 inputs.
5) Run the receiver object file -> 	./receive.out
6) O/P will be displayed.

### SEMAPHORE
1) Goto the Semaphore folder	-	cd Semaphore
2) Run the makefile 		    - 	make
3) Run the sender object file	-> 	./send.out
4) Give 5 inputs
5) Run the receiver object file -> 	./receive.out
6) O/P will be displayed.

**********************************************************************************************************************************************************************
