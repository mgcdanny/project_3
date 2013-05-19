//Daniel Gabrieli
/*All ".h" and ".cpp" files compile together using the following command: g++ *.h *.cpp  */

#ifndef DnaDatabase_H
#define DnaDatabase_H
// #include <string>
#include <vector>
// #include <algorithm>
// #include <iostream>
// #include <cstdlib>
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
		//NOTE: changed this to pass by refrence
		void addRecord(Organism& organism, DnaSequence& sequence);
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


#endif /*DnaDatabase_H*/





//IGNORE IGNORE IGNORE
//JUST THE TEST FUNCTION DEFINITIONS

// DnaDatabase::DnaDatabase():db(0) {}
// //Note: I changed this to pass-by-refrence
// void DnaDatabase::addRecord(Organism& organism, DnaSequence& sequence) { 
//     int found = -1;
//     for (vector<Organism>::iterator it = db.begin(); it != db.end(); ++it) {
//         found = (*it).getScientificName().find(organism.getScientificName());
//         if (found != -1) { /*when found do this:*/
//             /*update the copy of organism stored 'inside' the vector*/
//             (*it).setSequence((*it).getSequence()+sequence.getSequence());
//             /*update the 'original' organism that was copied to the vector ('outside the vector')*/
//             organism.setSequence(organism.getSequence()+sequence.getSequence());
//             break;             
//         }
//     }   
//     if(found == -1) { /*when not found do this:*/
//         /*set the sequence and copy to vector*/
//         organism.setSequence(sequence.getSequence());
//         db.push_back(organism);
//     }
// }


// void DnaDatabase::addRecord(string organismName, string sequence) {
//     int found = -1;
//     for (vector<Organism>::iterator it = db.begin(); it != db.end(); ++it) {
//         found = (*it).getScientificName().find(organismName);
//         if (found != -1) {
//             /*update the copy of organism stored 'inside' the vector*/
//             (*it).setSequence((*it).getSequence()+sequence);
//             break;             
//         }
//     }
//     if(found == -1) {
//         Organism newOrganism(organismName,sequence);
//         db.push_back(newOrganism);
//     }
// }


// DnaSequence DnaDatabase::getSequence(Organism organism) {
//     //NO ERROR HANDELING !! INPUT MUST EXIST IN DnaDatabase 
//     //class Organism inherits from DnaSequence, so technically
//     //the child class is of "equivalent" type as the parent class
//     int found = -1;
//     for (vector<Organism>::iterator it = db.begin(); it != db.end(); ++it) {
//         found = (*it).getScientificName().find(organism.getScientificName());
//         if (found != -1) {
//             /*update the copy of organism stored 'inside' the vector*/
//             return (*it);             
//         }
//     }
// }


// void DnaDatabase::deleteRecord(Organism organism) {
//     Organism tempOrganism;
//     string organismName = organism.getScientificName();
//     //cout << tempOrganism.getSequence() << endl;
//  for (vector<Organism>::iterator it = db.begin(); it != db.end(); ++it) {
//         tempOrganism = *it;
//         if (tempOrganism.getScientificName() == organismName) {
//             db.erase(it);
//             break;             
//         }
//     }
// }


// void DnaDatabase::deleteRecord(string organismName) {
//     Organism tempOrganism;
//     //cout << tempOrganism.getSequence() << endl;
//  for (vector<Organism>::iterator it = db.begin(); it != db.end(); ++it) {
//         tempOrganism = *it;
//         if (tempOrganism.getScientificName() == organismName) {
//             db.erase(it);
//             break;             
//         }
//     }
// }


// void DnaDatabase::printAllOrganisms() {
//  Organism tempOrganism;
//  for (vector<Organism>::iterator it = db.begin(); it != db.end(); ++it) {
//      tempOrganism = *it;
//      cout << tempOrganism.getScientificName() << endl;
//  }
// }


// int DnaDatabase::countAllOrganisms(){
//     return db.size();
// }


// int DnaDatabase::countOrganismsWithSequence(string partialSequence){
//     Organism tempOrganism;
//     int found = -1;
//     int counter = 0;
//     string tempSequence;
//     std::transform(partialSequence.begin(), partialSequence.end(),partialSequence.begin(), ::toupper);
//  for (vector<Organism>::iterator it = db.begin(); it != db.end(); ++it) {
//         tempOrganism = *it;
//         tempSequence = tempOrganism.getSequence();
//         found = tempSequence.find(partialSequence);
//         if (found != -1) {
//             counter++;             
//         }
//     }
//     return counter;
// }


// void DnaDatabase::searchAllOrganismsWithSequence(string partialSequence){
//     Organism tempOrganism;
//     int found = -1;
//     string tempSequence;
//  for (vector<Organism>::iterator it = db.begin(); it != db.end(); ++it) {
//         tempOrganism = *it;
//         tempSequence = tempOrganism.getSequence();
//         found = tempSequence.find(partialSequence);
//         if (found != -1) {
//             cout << tempOrganism.getScientificName() << endl;             
//         }
//  }
// }



