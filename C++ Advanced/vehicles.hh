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

template <typename T>
<vector<unique_ptr<T> > improved_can_move(double dest_x, double dest_y, vector<unique_ptr<T> > cars);