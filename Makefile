all: lab1arc
CFLAGS =-g -O3

lab1arc: bstree.o lab1arc.o
	cc -o $@ $^

bstree.o: bstree.c bstree.h
	cc -c $(CFLAGS) bstree.c

lab1arc.o: lab1arc.c bstree.h
	cc -c $(CFLAGS) lab1arc.c

clean:
	rm -f *.o lab1arc

demo: lab1arc
	./lab1arc 
