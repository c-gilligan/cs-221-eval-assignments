#include <vector>
#include <memory>
#include "cars.hh"

class Bus : public Car {
public: 
	vector<int> generate_route(int starting_stop) {

	}

	bool move_to(double new_x, double new_y) {
		double distance;
		double required_fuel;

		distance = sqrt( pow(new_x - (this -> pos_x), 2) + pow(new_y - (this -> pos_y), 2));
		
		// Incorporate mileage penalty per passenger into fuel calculations
		total_penalty = mileage_penalty * (this -> stop_numbers.size());
		required_fuel = distance / ((this -> fuel_efficiency) + total_penalty);

		if (required_fuel <= (this -> fuel)) {
			// Move car to destination
			this -> pos_x = new_x;
			this -> pos_y = new_y;

			// Subtract appropriate fuel amount
			this -> fuel -= required_fuel;

			return true;
		} else return false;
	}

	bool enough_fuel(double new_x, double new_y) {
		double distance;
		double required_fuel;

		distance = sqrt( pow(new_x - (this -> pos_x), 2) + pow(new_y - (this -> pos_y), 2));
		
		// Incorporate mileage penalty per passenger into fuel calculations
		total_penalty = mileage_penalty * (this -> stop_numbers.size());
		required_fuel = distance / ((this -> fuel_efficiency) + total_penalty);

		if (required_fuel <= (this -> fuel)) return true;
		else return false;
	}

private:
	int max_passengers;
	vector<int> stop_numbers;
	double mileage_penalty;

}