CC = gcc
CFLAGS = -Wall

all: scheduler_sim

scheduler_sim: main.o scheduler.o
	$(CC) -o scheduler_sim main.o scheduler.o

main.o: main.c scheduler.h task_struct.h
	$(CC) $(CFLAGS) -c main.c

scheduler.o: scheduler.c scheduler.h task_struct.h
	$(CC) $(CFLAGS) -c scheduler.c

clean:
	rm -f *.o scheduler_sim
