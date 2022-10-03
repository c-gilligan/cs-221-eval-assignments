#include <stdio.h>
#include <assert.h>

#include "conditional.h"
#include "negation.h"

int main(int argc, char* argv[]){
	if(argc > 1){
		printf("Error: This program does not take arguments. \n");

		return 1;
	}

	// tests for conditional

	assert(conditional(0, 2, 3) == 3);
	assert(conditional(1, 2, 3) == 2);

	printf("conditional test 2 value: %d \n", conditional(2,2,3));
	assert(conditional(2, 2, 3) == 2);

	assert(conditional(-1, 2, 3) == 2);

	// tests for negation
	printf("\n");
	printf("negation test 1 value: %d \n", negation(0));
	assert(negation(0) == 1);

	printf("negation test 2 value: %d \n", negation(1));
	assert(negation(1) == 0);

	printf("negation test 3 value: %d \n", negation(2));
	assert(negation(2) == 0);

}