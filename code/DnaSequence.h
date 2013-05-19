//Daniel Gabrieli
/*All ".h" and ".cpp" files compile together using the following command: g++ *.h *.cpp  */

#ifndef DnaSequence_H
#define DnaSequence_H

#include <string>

using namespace std;

/*
* Class defines a DNA Sequence of nucleotides (G,A,T,C)
* When sequences are added, they can be added in any case
* However, when asked to return the sequence, it should
* be all-caps
*/
class DnaSequence {
	public:
		DnaSequence();
		// the following constructor can take another DNA sequence
		// object and copy over its sequence into its own
		DnaSequence(const DnaSequence& dnaSequence);
		// for both of these functions, if there was
		// an existing sequence, the older sequence
		// is overwritten
		void setSequence(string sequence);
		void setSequence(const char *sequence);
		// for all these functions, appends to the tail end
		// of the existing sequence. If none exists,
		// the sequence becomes what was being requested to be
		// added (even if it is a single nucleotide)
		void append(string sequence);
		void append(char nucleotide);
		// return should be all caps
		string getSequence() const;
		// return the total size of the sequence
		int getSize() const;
	private:
		string dna;
};


#endif /* DnaSequence_H */



//IGNORE IGNORE IGNORE
//JUST THE TEST FUNCTION DEFINITIONS
// DnaSequence::DnaSequence(): dna("")  {}
// DnaSequence::DnaSequence(const DnaSequence& dnaSequence){
// 	string tempDna = dnaSequence.getSequence();
// 	dna = tempDna;
// }
// void DnaSequence::setSequence(string sequence) {
// 	dna = sequence;
// }
// void DnaSequence::setSequence(const char *sequence) {
// // might need to cast from char to string
// 	dna = sequence;
// }
// void DnaSequence::append(string sequence) {
// 	dna += sequence;
// }
// void DnaSequence::append(char nucleotide) {
// 	// might need to cast from char to string
// 	dna += nucleotide;
// }
// string DnaSequence::getSequence() const {
// 	string sequence = dna;
// 	std::transform(sequence.begin(), sequence.end(),sequence.begin(), ::toupper);
// 	return sequence;
// }
// int DnaSequence::getSize() const {
// 	return dna.length();
// }
