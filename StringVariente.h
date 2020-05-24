#pragma once
#include <iostream>
#include <string>
#include <bitset>
#include <fstream>
#include "DNAstring.h"


class StringVariente : public VariantInterface {
public:

	void read(string input) override {
		DNA = new DNAstring(input, true);
		return;
	}

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

	string opdracht(int start, int einde, string optie, string seq = "") override {
		if (optie == ">") {
			subtitutie(start, einde, seq);
		}
		else if (optie == "ins") {
			incerties(start, einde, seq);
		}
		else if (optie == "del") {
			delitie(start, einde);
		}
		else if (optie == "delins") {
			delitieIncertie(start, einde, seq);
		}
		else if (optie == "inv") {
			inversie(start, einde);
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
	DNAstring* DNA = nullptr;

	string subtitutie(int start, int einde, string seq) override {
		if (start != einde) {
			return "parameters zijn niet gelijk, er kan geen subtitutie plaatsvinden";
		}
		else if ((start > DNA->length()) || (einde > DNA->length())) {
			return "parameters are wrong, they will result in an array out of bound";
		}
		else if (start == 0) {
			DNAstring eerstedeel = DNA->slice(1, DNA->length());

			DNAstring sequence(seq, true);

			DNAstring total = eerstedeel.concat(sequence.getString());

		}
		else {
			DNAstring eerstedeel = DNA->slice(0, start - 1);
			DNAstring tweededeel = DNA->slice(start, DNA->length());

			DNAstring sequence(seq, true);

			DNAstring stap1 = eerstedeel.concat(sequence.getString());
			DNAstring total = stap1.concat(tweededeel.getString());

			delete DNA;
			DNA = new DNAstring(total);

			cout << "sub: " << DNA->length() << endl;
			for (int x = 0; x < DNA->length(); x++) {
				cout << DNA->at(x);
			}
			cout << endl;

			return "success";
		}
		return "oof";
	}

	string delitie(int start, int einde) override {
		if (start == einde) {
			return "parameters zijn niet gelijk, er kan geen subtitutie plaatsvinden";
		}
		else if ((start > DNA->length()) || (einde > DNA->length())) {
			return "parameters are wrong, they will result in an array out of bound";
		}

		DNAstring eerstedeel = DNA->slice(0, start);
		DNAstring tweededeel = DNA->slice(einde, DNA->length());

		DNAstring total = eerstedeel.concat(tweededeel.getString());

		delete DNA;
		DNA = new DNAstring(total);

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
		}

		DNAstring eerstedeel = DNA->slice(0, start);
		DNAstring tweededeel = DNA->slice(start, DNA->length());

		DNAstring sequence(seq, true);

		DNAstring stap1 = eerstedeel.concat(sequence.getString());
		DNAstring total = stap1.concat(tweededeel.getString());

		delete DNA;
		DNA = new DNAstring(total);

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
		}

		DNAstring eerstedeel = DNA->slice(0, start);
		DNAstring tweededeel = DNA->slice(einde, DNA->length());

		DNAstring sequence(seq, true);

		DNAstring stap1 = eerstedeel.concat(sequence.getString());
		DNAstring total = stap1.concat(tweededeel.getString());

		delete DNA;
		DNA = new DNAstring(total);

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
		}

		DNAstring eerstedeel = DNA->slice(0, start);
		DNAstring tweededeel = DNA->slice(einde, DNA->length());

		string stonks;
		for (int x = start; x < einde; x++) {
			char test = DNA->at(x);
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

		DNAstring sequence(stonks, true);

		DNAstring stap1 = eerstedeel.concat(sequence.getString());
		DNAstring total = stap1.concat(tweededeel.getString());

		delete DNA;
		DNA = new DNAstring(total);

		cout << "sub: " << DNA->length() << endl;
		for (int x = 0; x < DNA->length(); x++) {
			cout << DNA->at(x);
		}
		cout << endl;

		return "sucsess";
	}

};