#include <iostream>
#include "cars.h"

using namespace std;

int main(int argc, char* argv[]){
	cout << "help how do you do console output" << endl;
	cerr << "Error: brain cells not found (hehe letting me play with stderr was a mistake)" << endl;

	cout << endl;

	cout << "Beginning Car tests." << endl;

	Car hummer = Car(100.0, 5.0);

	return 0;
}