#include <iostream>
#include <cassert>
#include <vector>
#include "cars.hh"

using namespace std;

int main(int argc, char* argv[]){
	cout << "help how do you do console output" << endl;
	cerr << "Error: brain cells not found (hehe letting me play with stderr was a mistake)" << endl;

	cout << endl;

	cout << "Beginning Car tests." << endl;

	Car hummer = Car(100.0, 5.0);
	Car prius = Car(100.0, 20.0);

	cout << "hummer.enough_fuel(1000.0,1000.0) = " << hummer.enough_fuel(1000.0, 1000.0) << endl;

	assert(hummer.enough_fuel(1000.0,1000.0) == false);
	assert(prius.enough_fuel(1000.0,1000.0) == true);

	cout << "Car tests finished." << endl;

	cout << "Beginning can_move tests." << endl;

	shared_ptr<vector<Car> > test_cars(new vector<Car>);
	test_cars -> push_back(hummer);
	test_cars -> push_back(prius);

	// This one was a pain because Charlie's one example on overloading operators didn't work
	assert((*test_cars)[0] == hummer);
	assert((*test_cars)[1] == prius);
	assert((hummer == prius) == false); // Yes I'm too lazy to overload !=

	shared_ptr<vector<Car> > cars_able = can_move(1000.0, 1000.0, *test_cars);
	assert(*cars_able.size() == 1);
	assert(*cars_able[0] == prius);
	return 0;
}