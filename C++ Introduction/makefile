objects = cars.o

tests : ${objects}
	g++ tests.cpp -o tests ${objects}

cars.o : cars.cpp  
	g++ -c cars.cpp

clean : 
	rm ${objects}; rm tests

rebuild : 
	make clean; make && ./tests