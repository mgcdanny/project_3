#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cassert>

#include "DnaDatabase.h"

using namespace std;


void testCode() {
// create a new DB
DnaDatabase myGeneBank;
// DB should be blank...
assert(myGeneBank.countAllOrganisms() == 0);
// create the first organism
Organism frog("western clawed frog", "xenopus tropicalis");
// test sequences for first organism
DnaSequence frogSeq1;
frogSeq1.setSequence("GATA");
assert(frogSeq1.getSize()==4);
frogSeq1.setSequence("CTCT");
assert(frogSeq1.getSize()==4);
string testStr1 = "CTCT";
assert(frogSeq1.getSequence() == testStr1);
frogSeq1.append("TTCCTCCTCAGAGTCATCTGAGCTCTCACTGTCATCGGAGCTCTCA");

//should be 50, not 51right?
assert(frogSeq1.getSize()==50); 

// add organism1 & sequence1 to DB
// size of db == 1
myGeneBank.addRecord(frog,frogSeq1);
assert(myGeneBank.countAllOrganisms() == 1);
// test second organism
Organism human;
human.setCommonName("human");
human.setScientificName("homo sapiens");
char arr1[] ={"taaagcagctccagaaacgtttcttgtctagcaggaaagccctggctcttagagccag"};
DnaSequence tmpSequence;
tmpSequence.setSequence(arr1);
string testStr2;
testStr2 = "TAAAGCAGCTCCAGAAACGTTTCTTGTCTAGCAGGAAAGCCCTGGCTCTTAGAGCCAGT";
// note: capped and extra T added
DnaSequence humanSeq1(tmpSequence);

//MISTAKE should be 58, not 59, right?
assert(humanSeq1.getSize()==58); 
humanSeq1.append('T');

assert(humanSeq1.getSequence() == testStr2);

// add organism2, sequence1
// 2 records
myGeneBank.addRecord(human,humanSeq1);
assert(myGeneBank.countAllOrganisms() == 2);
DnaSequence humanSeq2;
string testStr3 = "aataggataatagcagatgt";
humanSeq2.append(testStr3);

//MISTAKE shoudl be 20, not 22 ???
assert(humanSeq2.getSize()==20); 

// add organism2, sequence2
myGeneBank.addRecord(human,humanSeq2);

cout << myGeneBank.countAllOrganisms() << endl; 
 myGeneBank.printAllOrganisms();

assert(myGeneBank.countAllOrganisms() == 2);

DnaSequence humSeqFromBank = myGeneBank.getSequence(human);

cout << humSeqFromBank.getSize() << endl;


//MISTAKE 80, not 81?
assert(humSeqFromBank.getSize()==80);


// made-up organism
Organism bigFoot("sasquatch","gigantopithecus blacki");
// copy over human gene; most likely, some guy putting on
// a gorilla suite
DnaSequence bigFootSeq(humanSeq1);
// add organism3, sequence1
myGeneBank.addRecord(bigFoot, bigFootSeq);
//MISTAKE there are 3 records (frog , human, bigfoot) in the db, not 2
assert(myGeneBank.countAllOrganisms() == 3);
// run some searches
myGeneBank.searchAllOrganismsWithSequence("tct");
assert(myGeneBank.countOrganismsWithSequence("tct")==3);
myGeneBank.searchAllOrganismsWithSequence("cac");
assert(myGeneBank.countOrganismsWithSequence("cac")==1);
myGeneBank.searchAllOrganismsWithSequence("GGAA");
assert(myGeneBank.countOrganismsWithSequence("GGAA")==2);
// test delete
myGeneBank.deleteRecord(bigFoot);
// run some more searches
myGeneBank.searchAllOrganismsWithSequence("tct");
assert(myGeneBank.countOrganismsWithSequence("tct")==2);
myGeneBank.searchAllOrganismsWithSequence("cac");
assert(myGeneBank.countOrganismsWithSequence("cac")==1);
myGeneBank.searchAllOrganismsWithSequence("GGAA");
assert(myGeneBank.countOrganismsWithSequence("GGAA")==1);
myGeneBank.printAllOrganisms();
// finish off the tests...
myGeneBank.deleteRecord(human);
myGeneBank.deleteRecord(frog);
assert(myGeneBank.countAllOrganisms() == 0);
}


int main() {

    testCode();

    return 0;
}

