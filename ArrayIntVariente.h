#pragma once

#include <iostream>
#include <cstdint>
#include <fstream>
#include <string>
#include <bitset>
#include "ArrayInt.h"



template<typename T> 
class ArrayIntVariente : public VariantInterface {
public:
	
	~ArrayIntVariente() {
		//std::cerr << "stonks" << endl;
		delete DNA;
	}
	


	void read(string input) override {
		DNA = new ArrayInt<T>(input);
	
		return;
	}

	void write(string output) override {
		ofstream myfile;
		myfile.open(output);
		string result;
		for (int x = 0; x < DNA->length(); x++){
			result = result + DNA->at(x);
		}
		myfile << result << '\n';
		return;
	}

	string opdracht(int start, int einde, string optie, string seq = "") override {
		if (optie == ">") {
			subtitutie(start, einde, seq);
		}else if (optie == "ins") {
			incerties(start, einde, seq);
		}else if (optie == "del") {
			delitie(start, einde);
		}else if (optie == "delins") {
			delitieIncertie(start, einde, seq);
		}else if (optie == "inv") {
			inversie(start, einde);
		}else {
			return "dit is geen bestaande naam";
		}
		
		return "success";
	}

private:

	ArrayInt<T>* DNA = nullptr;

	string subtitutie(int start, int einde, string seq) override {

		if (start != einde) {
			return "parameters zijn niet gelijk, er kan geen subtitutie plaatsvinden";
		}
		else if ((start > DNA->length()) || (einde > DNA->length())) {
			return "parameters are wrong, they will result in an array out of bound";
		}else if(start == 0){
			ArrayInt<T> sequentie(seq, true);
			ArrayInt<T> TweedeDeel = DNA->slice(1, DNA->length());
			ArrayInt<T> total = sequentie.concat(TweedeDeel);
			delete DNA;
			DNA = new ArrayInt<T>(total);
		}
		else {
			ArrayInt<T> Eerstehelft = DNA->slice(0, start-1);
			ArrayInt<T> Tweedehelft = DNA->slice(start, DNA->length() );

			ArrayInt<T> sequentie(seq, true);
			
			
			ArrayInt<T> stap1 = Eerstehelft.concat(sequentie);
			ArrayInt<T> total = stap1.concat(Tweedehelft);
			
			delete DNA;
			DNA = new ArrayInt<T>(total);
		}

		cout << "eerstehelft concat sequentie: " << DNA->length() << endl;
		for (int x = 0; x < DNA->length(); x++) {
			cout << DNA->at(x);
		}
		cout << endl;

		return "success";
	}

	string delitie(int start, int einde) override {
		if ((start > DNA->length()) || (einde > DNA->length())) {
			return "parameters are wrong, they will result in an array out of bound";
		}

		ArrayInt<T> Eerstehelft = DNA->slice(0, start );
		ArrayInt<T> Tweedehelft = DNA->slice(einde, DNA->length());

		delete DNA;
		ArrayInt<T> total = Eerstehelft.concat(Tweedehelft);
		DNA = new ArrayInt<T>(total);

		cout << "delitie" << DNA->length() << endl;
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

		ArrayInt<T> Eerstehelft = DNA->slice(0, start);
		ArrayInt<T> Tweedehelft = DNA->slice(start, DNA->length());
		
		ArrayInt<T> sequentie(seq, true);

		ArrayInt<T> stap1 = Eerstehelft.concat(sequentie);
		
		delete DNA;
		ArrayInt<T> total = stap1.concat(Tweedehelft);
		DNA = new ArrayInt<T>(total);

		cout << "resultaat" << DNA->length() << endl;
		for (int x = 0; x < DNA->length(); x++) {
			cout << DNA->at(x);
		}
		cout << endl;

		return "geslaagt";
	}

	string delitieIncertie(int start, int einde, string seq) override {
		if ((start > DNA->length()) || (einde > DNA->length())) {
			return "parameters are wrong, they will result in an array out of bound";
		}

		ArrayInt<T> Eerstehelft = DNA->slice(0, start);
		ArrayInt<T> Tweedehelft = DNA->slice(einde, DNA->length());

		ArrayInt<T> sequentie(seq, true);

		ArrayInt<T> stap1 = Eerstehelft.concat(sequentie);

		delete DNA;
		ArrayInt<T> total = stap1.concat(Tweedehelft);
		DNA = new ArrayInt<T>(total);

		cout << "delitie-incertie" << DNA->length() << endl;
		for (int x = 0; x < DNA->length(); x++) {
			cout << DNA->at(x);
		}
		cout << endl;

		return "success";
	}

	string inversie(int start, int einde) override {
		if (start == einde) {
			return "parameters zijn gelijk, er kan geen slice plaatsvinden";
		}
		else if ((start > DNA->length()) || (einde > DNA->length())) {
			return "parameters are wrong, they will result in an array out of bound";
		}

		ArrayInt<T> Eerstehelft = DNA->slice(0, start);
		ArrayInt<T> Tweedehelft = DNA->slice(einde, DNA->length());
		
		string stonks;
		for (int x = start; x < einde; x++) {
			char test = DNA->at(x);
			cout << x << " " << test << endl;
			switch (test){
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
		

		ArrayInt<T> sequentie(stonks, true);
		

		ArrayInt<T> stap1 = Eerstehelft.concat(sequentie);
		

		delete DNA;
		ArrayInt<T> total = stap1.concat(Tweedehelft);
		DNA = new ArrayInt<T>(total);
		
		cout << "inv" << DNA->length() << endl;
		for (int x = 0; x < DNA->length(); x++) {
			cout << DNA->at(x);
		}
		cout << endl;

		return "success";
	}

};