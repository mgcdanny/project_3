#include <string>
#include <iostream>
#include <cstdlib>
#include "DnaSequence.h"

using namespace std;

int main()
{
	
	cout << "Hello" << endl;

	DnaSequence cow;
	cout << cow.getSequence() << endl;
	cow.setSequence("ABCD"); 
	cout << cow.getSequence() << endl;
	cow.append("EFG");
	cout << cow.getSequence() << endl;	
	cout << cow.getSize() << endl;

	/* code */
	return 0;
}