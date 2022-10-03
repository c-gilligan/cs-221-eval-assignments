objects = conditional.o negation.o

tests : tests.c $(objects)
	gcc tests.c -o tests $(objects)

conditional.o : conditional.c
	gcc conditional.c -c

negation.o : negation.c 
	gcc negation.c -c

clean : 
	rm *.o && rm tests

rebuild : 
	make clean && make && ./tests