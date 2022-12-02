#include <iostream>
#include <cmath>
#include <vector>
#include <memory>

using namespace std;

class Car {
public:
	Car (double fuel_capacity, double efficiency);
	bool move_to(double new_x, double new_y) {
		double distance;
		double required_fuel;

		distance = sqrt( pow(new_x - (this -> pos_x), 2) + pow(new_y - (this -> pos_y), 2));

		required_fuel = distance / (this -> fuel_efficiency);

		if (required_fuel <= (this -> fuel)) {
			// Move car to destination
			this -> pos_x = new_x;
			this -> pos_y = new_y;

			// Subtract appropriate fuel amount
			this -> fuel -= required_fuel;

			return true;
		} else return false;
	}

	// Check if car can move, don't move car either way
	bool enough_fuel(double new_x, double new_y) {
		double distance;
		double required_fuel;

		distance = sqrt( pow(new_x - (this -> pos_x), 2) + pow(new_y - (this -> pos_y), 2));
		required_fuel = distance / (this -> fuel_efficiency);

		// Debug stuff
		// cout << "Distance: " << distance << endl;
		// cout << "Required Fuel: " << required_fuel << endl;

		if (required_fuel <= (this -> fuel)) return true;
		else return false;
	}
	bool operator==(const Car& other);

private:
	double pos_x;
	double pos_y;

	double fuel_efficiency;
	double tank_size;
	double fuel;
};

Car::Car (double fuel_capacity, double efficiency){
	tank_size = fuel_capacity;
	fuel = fuel_capacity;
	fuel_efficiency = efficiency;

	double pos_x = 0.0;
	double pos_y = 0.0;
}

bool Car::operator==(const Car& other){
	if (this -> fuel_efficiency != other.fuel_efficiency) return false;
	if (this -> tank_size != other.tank_size) return false;
	if (this -> fuel != other.fuel) return false;

	return true;
}

/* 
To Do: 
- Write enough_fuel method (done)
- For each car in input array, if enough_fuel(x,y) == true, add to vector (done)
- Look up how vectors work (done)
- Write car tests (done)
- Write can_move tests
*/

shared_ptr<vector<Car> >can_move(double dest_x, double dest_y, vector<Car> cars) {
	shared_ptr<vector<Car> > cars_able;


	for(int i = 0; i < (cars.size() - 1); i++) {
		if (cars[i].enough_fuel(dest_x,dest_y)) {
			// Duplicate car by implicitly calling copy constructor
			Car car_copy = cars[i];

			car_copy.move_to(dest_x,dest_y);		// Move car copy to destination
			cars_able -> push_back(car_copy);		// Add car copy to output list
		}
	}

	return cars_able;
}



