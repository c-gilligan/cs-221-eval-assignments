#include <vector>
#include <map>
#include <memory>
#include "cars.hh"

using namespace std;

class Bus : public Car {
public: 

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

	vector<int> generate_route(int starting_stop) {
		/* The assignment says "STD list" and I have no idea if that means a standard
		C list, but if it does then that's too bad because I'm not adding memory
		leaks */
		shared_ptr<vector<int> > route;
		vector<int> wrapped_stops;
		vector<int> stops;

		// For each stop number in the list of stops
		for(int i = 0; i < stop_numbers.size(); i++){

			// If stop number is smaller than starting stop
			if (stop_numbers[i] < starting_stop) {

				// Add to appropriate place in wrapped_stops
				if(wrapped_stops.size() == 0){
					wrapped_stops.push_back(stop_numbers[i]);
				}
				else{
					// For each stop in wrapped_stops
					for(int a = 0; a < wrapped_stops.size(); a++){

						// If stop at index a is greater than the stop to insert
						if(stop_numbers[i] < wrapped_stops[a]){

							// Insert stop before index a
							wrapped_stops.insert(a);
						}
					}

					// If larger than all elements, insert at end
					wrapped_stops.push_back(stop_numbers[i]);
				}
			}
			// If stop number is larger than starting stop
			else{

				// If no elements in stops
				if(stops.size() == 0){
					// Add to stops
					stops.push_back(stop_numbers[i]);
				}
				// If elements in stops
				else{

					// For each stop in stops
					for(int a = 0; a < stops.size(); a++){

						// If stop at index a is larger than the stop to insert
						if(stop_numbers[i] < stops[a]){
							// Insert stop before a
							stops.insert(a);
						}
					}

					// If larger than all elements, insert at end
					stops.push_back(stop_numbers[i]);
				}
			}
		}

		// Assemble stops and wrapped_stops into route
		route = *stops;
		
		for(int i = 0; i < wrapped_stops.size(); i++){
			route -> push_back(wrapped_stops[i]);
		}

		return route;
	}

private:
	int max_passengers;
	vector<int> stop_numbers;
	double mileage_penalty;
}

class MedicalCenter {
public:


private:

}