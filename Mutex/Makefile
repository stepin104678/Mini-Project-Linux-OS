all: send receive

send: mutex_send.c
	gcc mutex_send.c -o send.out -pthread

receive: mutex_receive.c
	gcc mutex_receive.c -o receive.out -pthread

run:
	./send.out
	./receive.out

clean:
	rm -rf *.out