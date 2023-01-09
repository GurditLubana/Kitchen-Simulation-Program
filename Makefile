CC=g++
CFLAGS=-std=c++11

objects = Node.o List.o Queue.o Stack.o Event.o Arrival.o Prepare.o completeService.o Execution.o PriorityQueue.o


# this rule builds A2 as the executable from the object files
all: main.o $(objects)
	$(CC) $(CFLAGS) -o A2 $< $(objects)

# this will build objects file from .cpp file


main.o: main.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
Node.o: Node.h Node.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
List.o: List.h List.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
Queue.o: Queue.h Queue.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
Stack.o: Stack.h Stack.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
Event.o: Event.h Event.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
Arrival.o: Arrival.h Arrival.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
Prepare.o: Prepare.h Prepare.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
completeService.o: completeService.h completeService.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
Execution.o: Execution.h Execution.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
PriorityQueue.o: PriorityQueue.h PriorityQueue.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
clean: 
	rm *.o
