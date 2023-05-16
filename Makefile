CC = g++
CFLAGS = -c -Wall

all: RK2

RK2: main.o tasks_rk2.o
	$(CC) main.o tasks_rk2.o -o RK2

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

tasks_rk2.o: tasks_rk2.cpp
	$(CC) $(CFLAGS) tasks_rk2.cpp

clean:
	rm -rf *.o RK2