#ifndef DnaDatabase_H
#define DnaDatabase_H
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include "Organism.h"


using namespace std;

/*
* Class defines a database of organisms and their DNA sequence
* This Database (DB) allows:
* - basic DB operations: add/update/delete
* - counting records/searching records
*
* While adding a sequence record: if the organism already exists,
* simply the new requested sequence is appended to the existing
* sequence for this organism; only a single "record" should exist
* per organism.
*
*/

class DnaDatabase {
	public:
		DnaDatabase();
		// add record by objects of appropriate class
		void addRecord(Organism organism, DnaSequence sequence);
		// add record by string values
		void addRecord(string organismName, string sequence);
		// given an organism, return the sequence
		DnaSequence getSequence(Organism organism);
		// delete the entry for a given organism
		void deleteRecord(Organism organism);
		// delete the entry for a given organism name
		void deleteRecord(string organismName);
		// print all existing organisms in the DB
		// one, per line.
		void printAllOrganisms();
		// returns the number of organisms
		int countAllOrganisms();
		// returns the number of organisms that have a given
		// partial sequence within their entire sequence
		int countOrganismsWithSequence(string partialSequence);
		// prints all the organisms that have
		// a given partial sequence within their entire sequence
		void searchAllOrganismsWithSequence(string partialSequence);
	private:
		//'db' is the container (vector) for the records of class Organism//
		//Organism inherits from the DnaSequenceClass //
		vector<Organism> db;
};


DnaDatabase::DnaDatabase():db(0) {}


void DnaDatabase::addRecord(Organism organism, DnaSequence sequence) {
    organism.setSequence(sequence.getSequence());            
    db.push_back(organism);
}

DnaSequence DnaDatabase::getSequence(Organism organism) {
    //class Organism inherits from DnaSequence, so technically
    //the child class is of "equivalent" type as the parent class
    return organism;
}


int DnaDatabase::countAllOrganisms(){
    return db.size();
}

void DnaDatabase::deleteRecord(string organismName) {
    Organism tester;
    //cout << tester.getSequence() << endl;
	for (vector<Organism>::iterator it = db.begin(); it != db.end(); ++it) {
        tester = *it;
        if (tester.getScientificName() == organismName) {
            db.erase(it);
            break;             
        }
    }
}


#endif /*DnaDatabase_H*/



