// Reminder: You are only allowed to use Tiny Floating Point numbers that contain 8 bits.
#include <stdint.h>

int conditional(int32_t x, int32_t y, int32_t z){

	int32_t index = (x != 0);

	return (z - ((z - y)*index));
}