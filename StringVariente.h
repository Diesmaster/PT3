#pragma once
#include <iostream>
#include <string>
#include <bitset>
#include <fstream>
#include "DNAstring.h"
#include "VarianteInterface.h"


class StringVariente : public VariantInterface {
public:
	//leest een filepath in
	 void read(string input);
	//schrijft DNA weg naar een output file, output is filepath
	 void write(string output);
	//de opdracht
	 string opdracht(int start, int einde, string optie, string seq = "");
	//destructor
	 ~StringVariente();

private:
	DNAstring* DNA = nullptr;

	//veranderd 1 char voor een andere
	 string subtitutie(int start, int einde, string seq) ;
	//voegt een string toe op een plek
	 string incerties(int start, int einde, string seq) ;
	//een grote subtitiutie
	 string delitieIncertie(int start, int einde, string seq) ;
	//maakt een stukje string invers
	 string inversie(int start, int einde) ;
	//delete een stukje string
	 string delitie(int start, int einde) ;
	
};