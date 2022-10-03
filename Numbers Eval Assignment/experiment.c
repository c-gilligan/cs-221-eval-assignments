#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	if (argc == 2){
		int tc_arg2 = atoi(argv[1]);
		int x = (tc_arg2== 0);

		printf("Second argument: %s \n", argv[1]);
		printf("Does 2nd arg == 0: %d \n", x);
		printf("Does 0 == 0: %d \n", (0 == 0));

		return x;
	} 
	else{
		printf("Incorrect number of arguments."); 
		
		return 0;
	}
}
