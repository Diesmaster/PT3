#pragma once

#include <string>

using namespace std;

class DNAstring
{
public:
	
	//constructor
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	DNAstring(string String) {
		DNA = String;
	}

	DNAstring(string input, bool bigPeen) {
		std::ifstream fin(input);
		string String;
		fin >> String;
		DNA = String;
	}

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	int  length() {
		return (int)DNA.size();
	}

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	char at(int pos) {
		return (char)DNA.at(pos);
	}

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	DNAstring concat(string plakker) {
		string helper = DNA + plakker;
		DNAstring hulpje(helper);
		return hulpje;
	}

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	DNAstring  slice(int start, int einde) {
		string helper = DNA.substr(start, einde);
		DNAstring hulpje(helper);
		return hulpje;
	}

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	bool  equal(string test) {
		if (DNA == test) {
			return true;
		}
		return false;
	}

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	void  print() {
		cout << DNA << endl;
	}

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	string  getString() {
		return DNA;
	}

private:
	string DNA;
};

