CC = g++
CFLAGS = -std=c++11 -Wall -Wextra -pedantic

main: main.o reservoir.o reverse_order.o
	$(CC) $(CFLAGS) -o main main.o reservoir.o reverse_order.o

main.o: main.cpp reservoir.h reverse_order.h
	$(CC) $(CFLAGS) -c main.cpp

reservoir.o: reservoir.cpp reservoir.h
	$(CC) $(CFLAGS) -c reservoir.cpp

reverse_order.o: reverse_order.cpp reverse_order.h
	$(CC) $(CFLAGS) -c reverse_order.cpp

test: main
	./main
	
clean:
	rm -f main main.o reservoir.o reverse_order.o