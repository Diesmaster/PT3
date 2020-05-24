#pragma once
#include <iostream>
#include <string>
#include <bitset>
#include <fstream>
#include "DNAstring.h"


class StringVariente : public VariantInterface {
public:

	//het zelfde als bij alle andere hahahaha
	void read(string input) override {
		DNA = new DNAstring(input, true);
		return;
	}

	//begin je het al saai te vinde?
	//ik zou dit best in de base clase hebben willen zetten
	//helaas in DNA in elke class een andere type, en zijn er geen abstractclasses daarvoor gebruikt.

	void write(string output) override {
		ofstream myfile;
		myfile.open(output);
		string result;
		for (int x = 0; x < DNA->length(); x++) {
			result = result + DNA->at(x);
		}
		myfile << result << '\n';
		return;
	}

	//dit doet de opdrachten
	string opdracht(int start, int einde, string optie, string seq = "") override {
		if (optie == ">") {
			return subtitutie(start, einde, seq);
		}
		else if (optie == "ins") {
			return incerties(start, einde, seq);
		}
		else if (optie == "del") {
			return delitie(start, einde);
		}
		else if (optie == "delins") {
			return delitieIncertie(start, einde, seq);
		}
		else if (optie == "inv") {
			return inversie(start, einde);
		}
		else {
			return "dit is geen bestaande naam";
		}

		return "success";
	}


	~StringVariente() {
		delete DNA;
	}

private:
	//het dna
	DNAstring* DNA = nullptr;

	//weer de zelfde grap maken of toch niet?
	string subtitutie(int start, int einde, string seq) override {
		if (start != einde) {
			return "parameters zijn niet gelijk, er kan geen subtitutie plaatsvinden";
		}
		else if ((start > DNA->length()) || (einde > DNA->length())) {
			return "parameters are wrong, they will result in an array out of bound";
		}
		else if (start == 0) {
			//maak de snee
			DNAstring eerstedeel = DNA->slice(1, DNA->length());

			DNAstring sequence(seq, true);
			//plak
			DNAstring total = eerstedeel.concat(sequence.getString());
			
			//sla op
			delete DNA;
			DNA = new DNAstring(total);

		}
		else {
			//maak de snee
			DNAstring eerstedeel = DNA->slice(0, start - 1);
			DNAstring tweededeel = DNA->slice(start, DNA->length());
			//plak
			DNAstring sequence(seq, true);
			//plak
			DNAstring stap1 = eerstedeel.concat(sequence.getString());
			DNAstring total = stap1.concat(tweededeel.getString());

			delete DNA;
			DNA = new DNAstring(total);
		}
		//print
		cout << "sub: " << DNA->length() << endl;
		for (int x = 0; x < DNA->length(); x++) {
			cout << DNA->at(x);
		}
		cout << endl;
		//jeeh
		return "sucsess";
	}

	string delitie(int start, int einde) override {
		if (start == einde) {
			return "parameters zijn niet gelijk, er kan geen subtitutie plaatsvinden";
		}
		else if ((start > DNA->length()) || (einde > DNA->length())) {
			return "parameters are wrong, they will result in an array out of bound";
		}
		//snee
		DNAstring eerstedeel = DNA->slice(0, start);
		DNAstring tweededeel = DNA->slice(einde, DNA->length());
		//plak
		DNAstring total = eerstedeel.concat(tweededeel.getString());

		//sla op
		delete DNA;
		DNA = new DNAstring(total);

		//print
		cout << "del: " << DNA->length() << endl;
		for (int x = 0; x < DNA->length(); x++) {
			cout << DNA->at(x);
		}
		cout << endl;


		return "success";
	}

	string incerties(int start, int einde, string seq) override {
		if (start != einde) {
			return "parameters zijn niet gelijk, er kan geen subtitutie plaatsvinden";
		}
		else if ((start > DNA->length()) || (einde > DNA->length())) {
			return "parameters are wrong, they will result in an array out of bound";
		}//check prarms

		//snee
		DNAstring eerstedeel = DNA->slice(0, start);
		DNAstring tweededeel = DNA->slice(start, DNA->length());
		//plak
		DNAstring sequence(seq, true);
		//plak
		DNAstring stap1 = eerstedeel.concat(sequence.getString());
		DNAstring total = stap1.concat(tweededeel.getString());

		//sla op
		delete DNA;
		DNA = new DNAstring(total);

		//print
		cout << "sub: " << DNA->length() << endl;
		for (int x = 0; x < DNA->length(); x++) {
			cout << DNA->at(x);
		}
		cout << endl;

		return "sucsess";

	}


	string delitieIncertie(int start, int einde, string seq) override {
		if (start == einde) {
			return "parameters zijn niet gelijk, er kan geen subtitutie plaatsvinden";
		}
		else if ((start > DNA->length()) || (einde > DNA->length())) {
			return "parameters are wrong, they will result in an array out of bound";
		}//params

		//snee
		DNAstring eerstedeel = DNA->slice(0, start);
		DNAstring tweededeel = DNA->slice(einde, DNA->length());
		//plak
		DNAstring sequence(seq, true);
		//plak
		DNAstring stap1 = eerstedeel.concat(sequence.getString());
		DNAstring total = stap1.concat(tweededeel.getString());
		//sla op
		delete DNA;
		DNA = new DNAstring(total);
		//print
		cout << "sub: " << DNA->length() << endl;
		for (int x = 0; x < DNA->length(); x++) {
			cout << DNA->at(x);
		}
		cout << endl;

		return "sucsess";
	}

	string inversie(int start, int einde) override {
		if (start == einde) {
			return "parameters zijn niet gelijk, er kan geen subtitutie plaatsvinden";
		}
		else if ((start > DNA->length()) || (einde > DNA->length())) {
			return "parameters are wrong, they will result in an array out of bound";
		}//check

		//snee
		DNAstring eerstedeel = DNA->slice(0, start);
		DNAstring tweededeel = DNA->slice(einde, DNA->length());

		//oeee afwisseling
		string stonks; //sla het inverse op
		for (int x = start; x < einde; x++) {
			char test = DNA->at(x); //oh nee wacht dit heb ik toch al een keer gedaan
			cout << x << " " << test << endl;
			switch (test) {
			case 'A':
				stonks = stonks + 'T';
				break;
			case 'T':
				stonks = stonks + 'A';
				break;
			case 'C':
				stonks = stonks + 'G';
				break;
			case 'G':
				stonks = stonks + 'C';
				break;
			}
		}
		//plak
		DNAstring sequence(stonks, true);
		//plak
		DNAstring stap1 = eerstedeel.concat(sequence.getString());
		DNAstring total = stap1.concat(tweededeel.getString());

		//sla op
		delete DNA;
		DNA = new DNAstring(total);

		//print
		cout << "sub: " << DNA->length() << endl;
		for (int x = 0; x < DNA->length(); x++) {
			cout << DNA->at(x);
		}
		cout << endl;

		return "sucsess";
	}

};