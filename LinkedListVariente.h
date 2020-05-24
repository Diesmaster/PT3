#pragma once
#include <iostream>
#include <string>
#include <bitset>
#include "LinkedList.h"

using namespace std;

template<typename T>
class LinkedListVariente : public VariantInterface {
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
		if (start != einde) {
			return "parameters zijn niet gelijk, er kan geen subtitutie plaatsvinden";
		}
		else if ((start > DNA->length()) || (einde > DNA->length())) {
			return "parameters are wrong, they will result in an array out of bound";
		}
		else if (start == 0) {
			LinkedList<T> eerstedeel = DNA->slice(1, DNA->length());

			LinkedList<T> sequence(seq, true);

			LinkedList<T> total = eerstedeel.concat(sequence);

		}
		else {
			LinkedList<T> eerstedeel = DNA->slice(0, start - 1);
			LinkedList<T> tweededeel = DNA->slice(start, DNA->length());

			LinkedList<T> sequence(seq, true);

			LinkedList<T> stap1 = eerstedeel.concat(sequence);
			LinkedList<T> total = stap1.concat(tweededeel);

			delete DNA;
			DNA = new LinkedList<T>(total);

		}
		cout << "sub: " << DNA->length() << endl;
		for (int x = 0; x < DNA->length(); x++) {
			cout << DNA->at(x);
		}
		cout << endl;

		return "success";

	}

	string delitie(int start, int einde) override {
		if (start == einde) {
			return "parameters zijn niet gelijk, er kan geen subtitutie plaatsvinden";
		}
		else if ((start > DNA->length()) || (einde > DNA->length())) {
			return "parameters are wrong, they will result in an array out of bound";
		}

		LinkedList<T> eerstedeel = DNA->slice(0, start);
		LinkedList<T> tweededeel = DNA->slice(einde, DNA->length());

		LinkedList<T> total = eerstedeel.concat(tweededeel);

		delete DNA;
		DNA = new LinkedList<T>(total);

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

		LinkedList<T> eerstedeel = DNA->slice(0, start);
		LinkedList<T> tweededeel = DNA->slice(start, DNA->length());

		bool supersain = false;
		int pos;

		if (seq.length() <= 2) {
			seq = "TA" + seq;
			supersain = true;
			pos = start + 2;
		}

		LinkedList<T> sequence(seq, true);

		LinkedList<T> stap1 = eerstedeel.concat(sequence);
		LinkedList<T> stap2 = stap1.concat(tweededeel);

		if (supersain == true) {
			LinkedList<T> tussenstap1 = stap2.slice(0, start);
			LinkedList<T> tussenstap2 = stap2.slice(pos, stap2.length());

			LinkedList<T> total = tussenstap1.concat(tussenstap2);

			delete DNA;
			DNA = new LinkedList<T>(total);

		}
		else {
			LinkedList<T> total = stap1.concat(stap2);

			delete DNA;
			DNA = new LinkedList<T>(total);
		}

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

		LinkedList<T> eerstedeel = DNA->slice(0, start);
		LinkedList<T> tweededeel = DNA->slice(einde, DNA->length());

		bool supersain = false;
		int pos;

		if (seq.length() <= 2) {
			seq = "TA" + seq;
			supersain = true;
			pos = start + 2;
		}

		LinkedList<T> sequence(seq, true);

		LinkedList<T> stap1 = eerstedeel.concat(sequence);
		LinkedList<T> stap2 = stap1.concat(tweededeel);

	if(supersain == true ){
		LinkedList<T> tussenstap1 = stap2.slice(0, start);
		LinkedList<T> tussenstap2 = stap2.slice(pos, stap2.length());


		LinkedList<T> total = tussenstap1.concat(tussenstap2);

		delete DNA;
		DNA = new LinkedList<T>(total);

	}
	else {
		LinkedList<T> total = stap1.concat(stap2);

		delete DNA;
		DNA = new LinkedList<T>(total);
	}
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

		LinkedList<T> eerstedeel = DNA->slice(0, start);
		LinkedList<T> tweededeel = DNA->slice(einde, DNA->length());

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

		LinkedList<T> sequence(stonks, true);

		LinkedList<T> stap1 = eerstedeel.concat(sequence);
		LinkedList<T> total = stap1.concat(tweededeel);

		delete DNA;
		DNA = new LinkedList<T>(total);

		cout << "sub: " << DNA->length() << endl;
		for (int x = 0; x < DNA->length(); x++) {
			cout << DNA->at(x);
		}
		cout << endl;

		return "sucsess";
	}

};