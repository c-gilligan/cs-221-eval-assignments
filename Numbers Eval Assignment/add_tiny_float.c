#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int32_t int_pow(int32_t base, int32_t exponent){
	int32_t output = base;

	for(int32_t i = (exponent - 1); i > 0; i--){
		output *= output;
	}

	return output;
}

/* 
Tiny float format: (8 bits)
10000000 | bit 1      | sign 
01111000 | bits 2 - 5 | exponent (bias: (2^3) - 1 = 7)
00000111 | bits 6 - 8 | significand
*/

/* Functions for extracting float components */

uint8_t tiny_sign(uint8_t input_float){
	uint8_t sign = (input_float >> 7) & 0x01;

	return sign; 
}

uint8_t tiny_exponent(uint8_t input_float){
	uint8_t exponent = (input_float >> 3) & 0x0F;

	return exponent;
}

uint8_t tiny_significand(uint8_t input_float){
	uint8_t significand = input_float & 0x07;

	return significand;
}

uint8_t recombine_float(uint8_t sign, uint8_t exponent, uint8_t significand){
	uint8_t recombined = 0x00;

	// Set sign
	if (sign == 0x01){
		recombined = 0x10;

	}else if(sign == 0x00){
		recombined = 0x00;

	}else{
		printf("recombine_float fucky wucky detected: invalid sign value %x \n", sign);

		return -1;
	}

	// Set exponent
	uint8_t shifted_exponent = (exponent << 3) & 0x78;
	recombined = (recombined | shifted_exponent);

	// Set significand
	recombined = (recombined | significand);

	return recombined;
}

/* Function to add two normalized floats */
uint8_t add_normalized_floats(uint8_t fl_1, uint8_t fl_2){
	int16_t sum_significand;
	uint8_t sum_exponent;
	uint8_t sum_sign; 

	// If exponents are equal
	if (tiny_exponent(fl_1) == tiny_exponent(fl_2)){
		sum_exponent = tiny_exponent(fl_1);

		// If fl_1 is positive
		if (tiny_sign(fl_1) == 0){

			// If fl_2 is positive
			if (tiny_sign(fl_2) == 0){
				sum_sign = 0x00;
				sum_significand = tiny_significand(fl_1) + tiny_significand(fl_2);

				if (sum_significand > 7){
					sum_significand -= 7;
					sum_exponent++;

					printf("Debug: incrementing exponent \n");
				}



			} // If fl_2 is negative 
			else if (tiny_sign(fl_2) == 1){
				sum_significand = tiny_significand(fl_1) - tiny_significand(fl_2);

				if (sum_significand < 0){
					sum_sign = 0x01;
					sum_exponent--;
					sum_significand = 7 + sum_significand;
				}
				else if (sum_significand == 0x00){
					sum_sign = 0x00;
					sum_exponent = 0x00;
				}
				else{
					sum_sign = 0x00;
				}

				printf("Debug: fl_1 is positive and fl_2 is negative \n");
			}

		}

		else if (tiny_sign(fl_1) == 1){
			printf("Debug: fl_1 is negative. Unimplemented feature warning! \n");
		}
		else {
			printf("Error: Invalid sign in add_normalized_floats \n");
		}
	}
	else {
		printf("Exponents in add_normalized_floats not equal. Unimplemented feature warning! \n");
	}

	return recombine_float(sum_sign, sum_exponent, sum_significand);
}


/* Add float function */
uint8_t add_tiny_float(uint8_t fl_1, uint8_t fl_2){
	// Extract exponents
	uint8_t exp_1 = tiny_exponent(fl_1);
	uint8_t exp_2 = tiny_exponent(fl_2);

	// If either has specialized encoding, return the first number that has specialized encoding
	if (exp_1 == 0x0E){
		printf("Debug: Specialized encoding in fl_1. \n");
		return fl_1;
	}
	else if(exp_2 == 0x0E){
		printf("Debug: Specialized encoding in fl_2. \n");
		return fl_2;
	}


	switch (exp_1) { // Detect encoding of fl_1
		case 0x0E: // fl_1 uses specialized
			printf("Debug: Specialized encoding in fl_1. \n");
			return fl_1;

		case 0x00: // fl_1 uses denormalized

			switch (exp_2) { // Detect encoding of fl_2
				case 0x0E: // fl_2 uses specialized
					printf("Debug: Specialized encoding in fl_2. \n");
					return fl_2;

				case 0x00:
					// Use function for adding two denormalized floats

				default:
					// Use function for adding normalized to denormalized

					// stand-in
					return -1;

			}

		default: // fl_1 uses normalized
			switch (exp_2) { // Detect encoding of fl_2
				case 0x0E: // fl_2 uses specialized
					return fl_2;

				case 0x00: 
					// Use function for adding normalized + denormalized 

					// stand-in return value
					printf("Warning: Unimplemented feature! (adding normalized + denormalized) \n");
					return 0x01;

				default: 
					// Use function for adding two normalized floats

					return add_normalized_floats(fl_1, fl_2);

			}
	}



}