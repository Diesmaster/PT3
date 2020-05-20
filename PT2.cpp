// PT2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DNAstring.h"

using namespace std;

int main()
{
	DNAstring test("hello world");
	test.print();
	cout << test.length() << endl;
	cout << test.char_at(2) << endl;
	DNAstring* tester = test.concat(" big peen");
	tester->print();
	DNAstring* hulp = tester->slice(0, 11);
	hulp->print();
	cout << test.equal(hulp->getString()) << endl;

	delete tester;
	delete hulp;
}

