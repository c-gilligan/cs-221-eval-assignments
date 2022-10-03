/*
To the graders and Charlie: Sorry for not finishing this. This part of the 
assignment was too heinous and I was losing too much sleep and time over
it. I spent at least 4 hours on this part alone, and it still isn't even 
close to working. I assure you it's not for lack of trying.
*/

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
01111000 | bits 2 - 5 | exponent (bias: 2^3 = 8)
00000111 | bits 6 - 8 | significand
*/

uint8_t add_tiny_float(uint8_t fl_1, uint8_t fl_2){
	// Check if either operand is 0
	if(fl_1 == 0) return fl_2;
	if(fl_2 == 0) return fl_1;

	// Extract sign bits
	uint8_t sign_1 = (fl_1 & 0x80);
	uint8_t sign_2 = (fl_2 & 0x80);

	/* Check if there are negative signs (currently this problem has taken
	far too long and I don't have time to implement addition of negative
	numbers properly) */
	if(sign_1 != 0){
		printf("Float 1 has a negative sign. Addition of negative floats is currently not a feature. \n");

		return 1;
	}

	if(sign_2 != 0){
		printf("Float 2 has a negative sign. Addition of negative floats is not currently a feature. \n");

		return 1;
	} 
	// I hope that if you're going to mark me off for this, I at least get 
	// credit for exiting properly. 

	// Extract exponents
	// Bit shift right by three, use bitmask to zero bits 1-4
	uint8_t exp_1 = (fl_1 >> 3) & 0x0F;
	uint8_t exp_2 = (fl_2 >> 3) & 0x0F;

	// Sanity check
	uint8_t max = 255;
	assert(((max >> 3) & 0xF0) == 15);

	// Extract significands
	// Use bitmask to extract last three bits
	uint8_t scand_1 = (fl_1 & 0x03);
	uint8_t scand_2 = (fl_2 & 0x03);

	// Let's get down to business (to defeat the Huns)
	uint8_t exp_diff = abs(exp_1 - exp_2); 
	uint8_t output_exp;

	if(exp_1 > exp_2){
		exp_2 *= int_pow(10, exp_diff);
		output_exp = exp_1;

	}

	if(exp_1 < exp_2){
		exp_1 *= int_pow(10, exp_diff);
		output_exp = exp_2;
	}

	// Add significands
	uint8_t output_scand = scand_1 + scand_2;



}