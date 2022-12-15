#include <iostream>
#include <cmath>
#include <vector>
#include <memory>
#include <utility>

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

	double refill_amount(){
		return tank_size - fuel;
	}

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

// You would not believe how long it took me to figure this out
bool Car::operator==(const Car& other){
	if (this -> fuel_efficiency != other.fuel_efficiency) return false;
	if (this -> tank_size != other.tank_size) return false;
	if (this -> fuel != other.fuel) return false;

	return true;
}

// Using a vector because manual array management is annoying, and what else is 
// C++ for if not making that easier
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


class GasStation {
public:
	double pos_x;
	double pos_y;

	double price;

private:

}

/*
road_trip function

- Takes x-coord, y-coord, vector of Cars, and vector of GasStations as input
- Pass 1: See if any cars can drive straight to the destination, if they can then drive
- Pass 2: 
- Return list containing two vectors, one of cars that can make it and one of their gas prices

*/

// Problem 1 part d
pair <vector<Car>, vector<double> > road_trip(double dest_x, double dest_y, vector<Car> cars, vector<GasStation> gas_stations){
	new shared_ptr<vector<Car> > cars_able;
	new shared_ptr<vector<double> > gas_prices;


	for (int i = 0; i < (*cars.size() - 1); i++){
		// If car has enough fuel to go directly to destination
		if (*cars[i].enough_fuel(dest_x, dest_y)){

			Car car_copy = *cars[i]; 			// make a copy of the car
			car_copy.move_to(dest_x, dest_y);	// move to destination
			cars_able.push_back(car_copy);		// add to output list
			gas_prices.push_back(0.0); 			// add price of 0 refills to gas costs list
		}

		// If car can't go directly
		else{
			double travel_cost = 0.0;

			// For each gas station, 
			for (int a = 0, a < (*gas_stations.size() - 1), a++){
				GasStation next_station = *gas_stations[a];

				// if the car can reach the station,
				if (*cars[i].enough_fuel(next_station)){

					// Add cost of going to station to total trip cost
					travel_cost += (*cars[i].refill_amount() * next_station.price);

					// If the car can get to the destination from here,
					if (*cars[i].enough_fuel(dest_x, dest_y)){

						Car car_copy = *cars[i]; 			// make a copy of the car
						car_copy.move_to(dest_x, dest_y);	// move to destination
						cars_able.push_back(car_copy);		// add to output list
						gas_prices.push_back(travel_cost); 	// add price of refills to gas costs list

					} 
					else {
						// Do nothing
					}
				}
				// If the car can't reach the next station
				else{
					break;	// break out of the loop
				}
			}
		}
	}

pair<vector<Car>, vector<double> > return_values;
return_values.first = cars_able;
return_values.second = gas_prices;

return return_values; 
// *bursts out of the heap covered in blood*
// *picks pieces of the stdlib out of my hair*
// What. was that. 
}



