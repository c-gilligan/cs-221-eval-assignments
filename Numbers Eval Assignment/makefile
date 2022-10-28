objects = conditional.o negation.o add_tiny_float.o

tests : tests.c $(objects)
	gcc tests.c -o tests $(objects)

conditional.o : conditional.c
	gcc conditional.c -c

negation.o : negation.c 
	gcc negation.c -c

add_tiny_float.o : add_tiny_float.c
	gcc add_tiny_float.c -c

clean : 
	rm *.o && rm tests

rebuild : 
	make clean && make && ./tests
