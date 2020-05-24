#pragma once
#include <iostream>
#include <string>
#include <bitset>
#include "LinkedList.h"

using namespace std;

template<typename T>
class LinkedListVariente: public VariantInterface {
public:

	LinkedListVariente() {

	}

	~LinkedListVariente() {
		delete DNA;
	}

	void read(string input) override {
		DNA = new LinkedList<T>(input);
		return;
	}
	
	void write() override {
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

private:
	LinkedList<T>* DNA;

	string subtitutie(int start, int einde, string seq) override {
		LinkedList<T> eerstedeel = DNA->slice(0, start);
		LinkedList<T> tweededeel = DNA->slice(start, DNA->length());

		//LinkedList<T> total = eerstedeel.concat(tweededeel);
		
		LinkedList<T> total(seq, true);
		delete DNA;
		DNA = new LinkedList<T>(total);

		cout << "eerstehelft concat sequentie: " << DNA->length() << endl;
		for (int x = 0; x < DNA->length(); x++) {
			cout << DNA->at(x);
		}
		cout << endl;

		return "";
	}

	string delitie(int start, int einde) override {
		return "";
	}
	string incerties(int start, int einde, string seq) override {
		return "";
	}
	string delitieIncertie(int start, int einde, string seq) override {
		return "";
	}
	string inversie(int start, int einde) override {
		return "";
	}
};