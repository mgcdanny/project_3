#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#include "DnaDatabase.h"

using namespace std;

int main() {

    DnaDatabase db;
    Organism me;
    DnaSequence tester;
    Organism me2;
    DnaSequence tester2;
    cout << db.countAllOrganisms() << endl;
    db.addRecord(me, tester);
    db.addRecord(me2, tester2);
    cout << db.countAllOrganisms() << endl;
    db.deleteRecord("William");
    cout << db.countAllOrganisms() << endl;
    //cout << me.getCommonName();
    //cout << "hey" << endl;
    //DnaSequence meat;
    //cout << meat.getSequence() << endl;
    //tester = db.getSequence(me);
    //cout << tester.getSequence() << endl;

    return 0;
}

