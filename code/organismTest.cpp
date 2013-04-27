#include <string>
#include <iostream>
#include <cstdlib>
#include "Organism.h"

using namespace std;

int main()
{
	
	cout << "Hello" << endl;

	Organism cow;
	cout << cow.getCommonName() << endl;
	cout << cow.getScientificName() << endl;
	cow.setCommonName("cow");
	cow.setScientificName("bigCowCow");
	cout << cow.getCommonName() << endl;
	cout << cow.getScientificName() << endl;
	cow.setName("donky", "mule");
	cout << cow.getCommonName() << endl;
	cout << cow.getScientificName() << endl;

	/* code */
	return 0;
}