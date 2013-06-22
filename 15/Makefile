red_black: red_black_tree.o queue.o
	gcc -lm -o red_black_tree red_black_tree.o queue.o

red_black_tree.o: red_black_tree.c rb.h
	gcc -c -o red_black_tree.o red_black_tree.c

queue.o: queue.c rb.h
	gcc -c -o queue.o queue.c

clean:
	rm *.o red_black_tree
