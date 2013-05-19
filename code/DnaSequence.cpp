//Daniel Gabrieli
/*All ".h" and ".cpp" files compile together using the following command: g++ *.h *.cpp  */

#include <string>
#include <algorithm>
#include "DnaSequence.h"

using namespace std;

DnaSequence::DnaSequence(): dna("")  {}

DnaSequence::DnaSequence(const DnaSequence& dnaSequence){
	string tempDna = dnaSequence.getSequence();
	dna = tempDna;
}

void DnaSequence::setSequence(string sequence) {
	dna = sequence;
}

void DnaSequence::setSequence(const char *sequence) {
// might need to cast from char to string
	dna = sequence;
}

void DnaSequence::append(string sequence) {
	dna += sequence;
}

void DnaSequence::append(char nucleotide) {
	// might need to cast from char to string
	dna += nucleotide;
}

string DnaSequence::getSequence() const {
	string sequence = dna;
	std::transform(sequence.begin(), sequence.end(),sequence.begin(), ::toupper);
	return sequence;
}

int DnaSequence::getSize() const {
	return dna.length();
}
