#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include "Organism.h"

using namespace std;

int main()
{

	/*
	int myints[] = {16,2,77,29};
	std::vector<int> vec (myints, myints + sizeof(myints) / sizeof(int));
	
	std::cout << "The size: " << vec.size() <<  " The contents of vec are:";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    std::cout << ' ' << *it;
	std::cout << '\n';
	vec.erase(std::remove(vec.begin(), vec.end(), 77), vec.end());
	vec.push_back(99); //add an element (at the end)
	std::cout << "The size: " << vec.size() <<  " The contents of vec are:";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    std::cout << ' ' << *it;
	std::cout << '\n';
	*/

	vector<Organism> vec;
	Organism cow;
	Organism tempOrgan;
	vec.push_back(cow);
	cout << "The size: " << vec.size() <<  " The contents of vec are:";
	for (vector<Organism>::iterator it = vec.begin(); it != vec.end(); ++it)
    tempOrgan = *it;
	cout << tempOrgan.getSequence() << endl;
	tempOrgan.setSequence("asdfasdf");
	cout << tempOrgan.getSequence() << endl;
/*	
	vec.erase(std::remove(vec.begin(), vec.end(), cow), vec.end());
	//vec.push_back(99); //add an element (at the end)
	std::cout << "The size: " << vec.size() <<  " The contents of vec are:";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    std::cout << ' ' << *it;
	std::cout << '\n';

	
	cout << "Hello" << endl;

//	Organism cow;
	cow.setSequence("asdf");
	cout << cow.getSequence() << endl;

	// cout << cow.getCommonName() << endl;
	// cout << cow.getScientificName() << endl;
	// cow.setCommonName("cow");
	// cow.setScientificName("bigCowCow");
	// cout << cow.getCommonName() << endl;
	// cout << cow.getScientificName() << endl;
	// cow.setName("donky", "mule");
	// cout << cow.getCommonName() << endl;
	// cout << cow.getScientificName() << endl;

	/* code */

	return 0;
}