#pragma once

#include <iostream>
#include <string>
#include <bitset>
#include "ArrayInt.h"


template<typename T> 
class ArrayIntVariente : public VariantInterface {
public:
	
	~ArrayIntVariente() {
		delete DNA;
	}
	
	ArrayIntVariente() {
	
	}


	void read(string input) override {
		ArrayInt<T>* stonks = new ArrayInt<T>(input);
		DNA = stonks;
		return;
	}

	void write() override {
		return;
	}

	string opdracht(int start, int einde, string optie, string seq = "") override {
		if (optie == ">") {
			subtitutie(start, einde, seq);
		}else if (optie == "ins") {
			incerties(start, einde, seq);
		}

		/*case ">":
			break;
		case "ins":
			
			break;
		case "del":
			delitie(start, einde);
			break;
		case "delins":
			delitieIncertie(start, einde, seq);
			break;
		case "inv":
			inversie(start, einde);
			break;
		}*/
		
		return "success";
	}

private:
	ArrayInt<T>* DNA;

	string subtitutie(int start, int einde, string seq) override {

		if (start != einde) {
			return "parameters zijn niet gelijk, er kan geen subtitutie plaatsvinden";
		}
		else if ((start > DNA->length()) || (einde > DNA->length())) {
			return "parameters are wrong, they will result in an array out of bound";
		}else if(start == 0){
			//ArrayInt<T> sequentie(seq, true);
			//ArrayInt<T> total = sequentie.concat(*DNA);
			//delete DNA;
			//DNA = new ArrayInt<T>(total);
		}
		else {
			ArrayInt<T> Eerstehelft = DNA->slice(0, start);
			ArrayInt<T> Tweedehelft = DNA->slice(start, DNA->length() );

			ArrayInt<T> sequentie(seq, true);
			
			ArrayInt<T> stap1 = Eerstehelft.concat(sequentie);
			ArrayInt<T> total = stap1.concat(Tweedehelft);
			
			delete DNA;
			DNA = new ArrayInt<T>(sequentie);
		}

		cout << "resultaat: " << DNA->length() << endl;
		for (int x = 0; x < DNA->length(); x++) {
			cout << DNA->at(x);
		}
		cout << endl;

		return "success";
	}

	string delitie(int start, int einde) override {
		return "";
	}

	string incerties(int start, int einde, string seq) override {
		if (start != einde) {
			return "parameters zijn niet gelijk, er kan geen subtitutie plaatsvinden";
		}
		else if ((start > DNA->length()) || (einde > DNA->length())) {
			return "parameters are wrong, they will result in an array out of bound";
		}

		ArrayInt<T> Eerstehelft = DNA->slice(0, start);
		ArrayInt<T> Tweedehelft = DNA->slice(start, einde);
		
		//ArrayInt<T> sequentie(seq, true);

		//rrayInt<T> stap1 = Eerstehelft.concat(sequentie);
		
		delete DNA;
		ArrayInt<T> total = Eerstehelft.concat(Tweedehelft);
		DNA = new ArrayInt<T>(total);

		cout << "resultaat" << DNA->length() << endl;
		for (int x = 0; x < DNA->length(); x++) {
			cout << DNA->at(x);
		}
		cout << endl;

		return "geslaagt";
	}

	string delitieIncertie(int start, int einde, string seq) override {
		return "";
	}

	string inversie(int start, int einde) override {
		return "";
	}

};