// function tests the implementation of project 3
// it creates a database, 3 organisms, multiple sequences
// and tests add/update/delete on the DB
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
assert(frogSeq1.getSize()==51);
// add organism1 & sequence1 to DB
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
assert(humanSeq1.getSize()==59);
humanSeq1.append('T');
assert(humanSeq1.getSequence() == testStr2);
// add organism2, sequence1
myGeneBank.addRecord(human,humanSeq1);
assert(myGeneBank.countAllOrganisms() == 2);
DnaSequence humanSeq2;
string testStr3 = "aataggataatagcagatgt";
humanSeq2.append(testStr3);
assert(humanSeq2.getSize()==22);
// add organism2, sequence2
myGeneBank.addRecord(human,humanSeq2);
assert(myGeneBank.countAllOrganisms() == 2);
DnaSequence humSeqFromBank = myGeneBank.getSequence(human);
assert(humSeqFromBank.getSize()==81);
// made-up organism
Organism bigFoot("sasquatch","gigantopithecus blacki");
// copy over human gene; most likely, some guy putting on
// a gorilla suite
DnaSequence bigFootSeq(humanSeq1);
// add organism3, sequence1
myGeneBank.addRecord(bigFoot, bigFootSeq);
assert(myGeneBank.countAllOrganisms() == 2);
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

