#include <iostream>
#include <cmath>
#include <vector>
#include <memory>

using namespace std;

class Car {
public:
	Car (double fuel_capacity, double efficiency){
		tank_size = fuel_capacity;
		fuel = fuel_capacity;
		fuel_efficiency = efficiency;
	}

	bool move_to(double new_x, double new_y) {
		double distance;
		double required_fuel;

		distance = abs(((this -> pos_x) - new_x) / ((this -> pos_y) - new_y));
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

		distance = abs(((this -> pos_x) - new_x) / ((this -> pos_y) - new_y));
		required_fuel = distance / (this -> fuel_efficiency);

		if (required_fuel <= (this -> fuel)) return true;
		else return false;
	}

private:
	double pos_x;
	double pos_y;

	double fuel_efficiency;
	double tank_size;
	double fuel;
};

/* 
To Do: 
- Write enough_fuel method (done)
- For each car in input array, if enough_fuel(x,y) == true, add to vector (done)
- Look up how vectors work (done)
- Write car tests
- Write can_move tests
*/

vector<Car> can_move(double dest_x, double dest_y, vector<Car> cars) {
	shared_ptr<vector<Car>> cars_able;

	for(i = 0; i < (cars.size() - 1); i++) {
		if (cars[i].can_move(dest_x,dest_y)) {
			Car car_copy = cars[i];

			car_copy.move_to(dest_x,dest_y);	// Move car copy to destination
			cars_able.push_back(car_copy);		// Add car copy to output list
		}
	}

	return cars_able;
}



