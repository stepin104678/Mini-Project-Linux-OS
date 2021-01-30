all: send receive

send: sem_send.c
	gcc sem_send.c -o send.out -pthread

receive: sem_receive.c
	gcc sem_receive.c -o receive.out -pthread

run:
	./send.out
	./receive.out

clean:
	rm -rf *.out