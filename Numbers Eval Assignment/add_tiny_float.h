#include <stdint.h>

uint8_t tiny_sign(uint8_t input_float);
uint8_t tiny_exponent(uint8_t input_float);
uint8_t tiny_significand(uint8_t input_float);

uint8_t add_normalized_floats(uint8_t fl_1, uint8_t fl_2);

uint8_t add_tiny_float(uint8_t fl_1, uint8_t fl_2);
