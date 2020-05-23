CC = g++

CompileParms = -c -Wall -Werror -pedantic

OBJS = main.o

Opdr: $(OBJS)
	$(CC) $(OBJS) -o DNA

main.o: main.cc ArrayInt.h LinkedList.h
	$(CC) $(CompileParms)  main.cc

