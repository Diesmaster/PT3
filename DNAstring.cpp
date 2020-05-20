#include "DNAstring.h"
#include <iostream>
#include <string>

using namespace std;


//constructor
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
DNAstring::DNAstring( string String) {
	DNA = String;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int DNAstring::length() {
	return (int)DNA.size();
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

char DNAstring::char_at(int pos) {
	return (char)DNA.at(pos);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

DNAstring* DNAstring::concat(string plakker) {
	string helper = DNA + plakker;
	DNAstring* hulpje;
	hulpje = new DNAstring(helper);
	return hulpje;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

DNAstring* DNAstring::slice(int start, int einde) {
	string helper = DNA.substr(start, einde);
	DNAstring* hulpje;
	hulpje = new DNAstring(helper);
	return hulpje;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

bool DNAstring::equal(string test) {
	if (DNA == test) {
		return true;
	}
	return false;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void DNAstring::print() {
	cout << DNA << endl;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

string DNAstring::getString() {
	return DNA;
}