#ifndef CAR
#define CAR

class Car {
public:
	bool move_to(double new_x, double new_y);
	bool enough_fuel(double new_x, double new_y);

private:
	double pos_x;
	double pos_y;

	double fuel_efficiency;
	double tank_size;
	double fuel;
};
#endif