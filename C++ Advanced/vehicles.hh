#include <vector>
#include <map>
#include <string>
#include "cars.hh"

class Bus : protected Car {
public: 
	bool move_to(double new_x, double new_y);
	bool enough_fuel(double new_x, double new_y);
	std::vector<int> generate_route(int starting_stop);
}

class MedicalCenter;

class Ambulance : protected Car, protected MedicalCenter {
public: 
	bool move_to(double new_x, double new_y);
}