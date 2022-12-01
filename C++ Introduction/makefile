tests : tests.cpp cars.h
	g++ tests.cpp -o tests

cars.o : cars.cpp  
	g++ -c cars.cpp

clean : 
	rm tests

rebuild : 
	make clean; make && ./tests