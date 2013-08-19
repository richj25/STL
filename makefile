CC=/usr/bin/g++
CFLAGS= -g -std=c++11 -Wall

OBJS=array          \
     bitset         \
     deque          \
     forward_list   \
     list           \
     map            \
     multimap       \
     multiset       \
     priority_queue \
     queue          \
     set            \
     stack          \
     vector 

all: $(OBJS)

array: array.cc
	$(CC) $(CFLAGS) -o array array.cc

bitset: bitset.cc
	$(CC) $(CFLAGS) -o bitset bitset.cc

deque: deque.cc
	$(CC) $(CFLAGS) -o deque deque.cc

forward_list: forward_list.cc
	$(CC) $(CFLAGS) -o forward_list forward_list.cc

list: list.cc
	$(CC) $(CFLAGS) -o list list.cc

map: map.cc
	$(CC) $(CFLAGS) -o map map.cc

multimap: multimap.cc
	$(CC) $(CFLAGS) -o multimap multimap.cc

multiset: multiset.cc
	$(CC) $(CFLAGS) -o multiset multiset.cc

priority_queue: priority_queue.cc
	$(CC) $(CFLAGS) -o priority_queue priority_queue.cc

queue: queue.cc
	$(CC) $(CFLAGS) -o queue queue.cc

set: set.cc
	$(CC) $(CFLAGS) -o set set.cc

stack: stack.cc
	$(CC) $(CFLAGS) -o stack stack.cc

vector: vector.cc
	$(CC) $(CFLAGS) -o vector vector.cc

clean:
	rm $(OBJS)
