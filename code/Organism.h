#ifndef Organism_H
#define Organism_H
#include <string>
#include <cstdlib>
#include "DnaSequence.h"

using namespace std;

/*
* Class defines an organism type
* Organisms have common names and scientific names
* The default constructor should set "unknown" for both
*/

/*try inherting from bass class DnaSequence*/
/*An organism "is a" series of DnaSequences*/

class Organism : public DnaSequence {
	public:
		Organism();
		Organism(string commonName, string scientificName);
		void setName(string commonName, string scientificName);
		void setCommonName(string commonName);
		string getCommonName();
		void setScientificName(string scientificName);
		string getScientificName();
	 private:
	 	string commonName;
	 	string scientificName;
};


Organism::Organism(): DnaSequence(), commonName("unknown"), scientificName("unknown") {}

Organism::Organism(string commonName, string scientificName): DnaSequence(), commonName(commonName), scientificName(scientificName) {} 


void Organism::setName(string setCommonName, string setScientificName){
	commonName = setCommonName;
	scientificName= setScientificName;
}

void Organism::setCommonName(string setCommonName){
	commonName = setCommonName;
}

string Organism::getCommonName(){
	return commonName;
}

void Organism::setScientificName(string setScientificName){
	scientificName= setScientificName;
}

string Organism::getScientificName(){
	return scientificName;
}

#endif /*Organism_H*/
