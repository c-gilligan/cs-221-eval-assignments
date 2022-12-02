#include <memory>
#include <vector>

#ifndef CAR
#define CAR

class Car {
public:
	Car(double fuel_capacity, double efficiency);
	bool move_to(double new_x, double new_y);
	bool enough_fuel(double new_x, double new_y);
	bool operator== (const Car& other);
	double refill_amount();

private:
	double pos_x;
	double pos_y;

	double fuel_efficiency;
	double tank_size;
	double fuel;
};
#endif 

// This is the worst function signature I've ever seen
pair <vector<Car>, vector<double> > road_trip(double dest_x, double dest_y, vector<Car> cars, vector<GasStation> gas_stations);

std::shared_ptr<std::vector<Car> >can_move(double dest_x, double dest_y, std::vector<Car> cars);