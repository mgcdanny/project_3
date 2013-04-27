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
string getSequence();
// return the total size of the sequence
int getSize();
};
