//Daniel Gabrieli
/*All ".h" and ".cpp" files compile together using the following command: g++ *.h *.cpp  */

#include "Organism.h"
#include <string>
#include <cstdlib>

using namespace std;

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
