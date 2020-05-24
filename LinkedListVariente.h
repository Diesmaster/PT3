#pragma once
#include <iostream>
#include <string>
#include <bitset>
#include <fstream>
#include "LinkedList.h"

using namespace std;

template<typename T>
class LinkedListVariente : public VariantInterface {
public:
	//destructor
	~LinkedListVariente() {
		delete DNA;
	}

	//lees het dna in
	void read(string input) override {
		DNA = new LinkedList<T>(input);
		return;
	}

	//schrijf het dna weg
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

	//doe de opdrachten
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

private:
	LinkedList<T>* DNA = nullptr;

	string subtitutie(int start, int einde, string seq) override {
		if (start != einde) {
			return "parameters zijn niet gelijk, er kan geen subtitutie plaatsvinden";
		}
		else if ((start > DNA->length()) || (einde > DNA->length())) {
			return "parameters are wrong, they will result in an array out of bound";
		}
		else if (start == 0) { //als het 0 is kan je hem niet aftrekken
			LinkedList<T> eerstedeel = DNA->slice(1, DNA->length()); //moet je dus een andere tactiek gebruiken

			LinkedList<T> sequence(seq, true); //plak

			LinkedList<T> total = eerstedeel.concat(sequence); //plak

		}
		else {
			//snij
			LinkedList<T> eerstedeel = DNA->slice(0, start - 1); 
			LinkedList<T> tweededeel = DNA->slice(start, DNA->length());

			//plak
			LinkedList<T> sequence(seq, true);

			//plak
			LinkedList<T> stap1 = eerstedeel.concat(sequence);
			LinkedList<T> total = stap1.concat(tweededeel);

			//sla op
			delete DNA;
			DNA = new LinkedList<T>(total);

		}
		//print
		cout << "sub: " << DNA->length() << endl;
		for (int x = 0; x < DNA->length(); x++) {
			cout << DNA->at(x);
		}
		cout << endl;

		//jeeh
		return "success";

	}
	//delete
	string delitie(int start, int einde) override {
		if (start == einde) {
			return "parameters zijn niet gelijk, er kan geen subtitutie plaatsvinden";
		}
		else if ((start > DNA->length()) || (einde > DNA->length())) {
			return "parameters are wrong, they will result in an array out of bound";
		}
		//snij
		LinkedList<T> eerstedeel = DNA->slice(0, start);
		LinkedList<T> tweededeel = DNA->slice(einde, DNA->length());
		//plak het aan elkaar
		LinkedList<T> total = eerstedeel.concat(tweededeel);

		//sla op
		delete DNA;
		DNA = new LinkedList<T>(total);

		//druk af
		cout << "del: " << DNA->length() << endl;
		for (int x = 0; x < DNA->length(); x++) {
			cout << DNA->at(x);
		}
		cout << endl;

		//jeeeh
		return "success";
	}

	//inscert dingen
	string incerties(int start, int einde, string seq) override {
		if (start != einde) {
			return "parameters zijn niet gelijk, er kan geen subtitutie plaatsvinden";
		}
		else if ((start > DNA->length()) || (einde > DNA->length())) {
			return "parameters are wrong, they will result in an array out of bound";
		}//check params

		//snij
		LinkedList<T> eerstedeel = DNA->slice(0, start);
		LinkedList<T> tweededeel = DNA->slice(start, DNA->length());
		/*
		insert TF2 comments....
		vraag me er niet naar...
		vraag maar aan mijn groepsgenoot...
		*/

		bool supersain = false; //of mijn bugfix geimplement moet worden
		int pos; //de positie van de fix

		if (seq.length() <= 2) {
			seq = "TA" + seq; //voer iets toe zodat de string grooter worden dan 2
			supersain = true; //yes
			pos = start + 2; //set
		}

		//plak zoals normaal
		LinkedList<T> sequence(seq, true);

		//plak rustig verder
		LinkedList<T> stap1 = eerstedeel.concat(sequence);
		LinkedList<T> stap2 = stap1.concat(tweededeel);

		if (supersain == true) {
			//als de bugfix erin stond, dan moet hij er weer uit.
			LinkedList<T> tussenstap1 = stap2.slice(0, start);
			LinkedList<T> tussenstap2 = stap2.slice(pos, stap2.length());
			
			//laaste fase
			LinkedList<T> total = tussenstap1.concat(tussenstap2);

			//sla op
			delete DNA;
			DNA = new LinkedList<T>(total);

		}
		else {
			//plak
			LinkedList<T> total = stap1.concat(tweededeel);

			//sla op
			delete DNA;
			DNA = new LinkedList<T>(total);
		}

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
		}

		//plak
		LinkedList<T> eerstedeel = DNA->slice(0, start);
		LinkedList<T> tweededeel = DNA->slice(einde, DNA->length());

		//zelfde verhaal als net
		bool supersain = false;
		int pos;

		//TF2
		if (seq.length() <= 2) {
			seq = "TA" + seq;
			supersain = true;
			pos = start + 2;
		}

		//plak
		LinkedList<T> sequence(seq, true);
		
		//plak
		LinkedList<T> stap1 = eerstedeel.concat(sequence);
		LinkedList<T> stap2 = stap1.concat(tweededeel);

	if(supersain == true ){
		//plak
		LinkedList<T> tussenstap1 = stap2.slice(0, start);
		LinkedList<T> tussenstap2 = stap2.slice(pos, stap2.length());

		//plak
		LinkedList<T> total = tussenstap1.concat(tussenstap2);
		
		//sla op
		delete DNA;
		DNA = new LinkedList<T>(total);

	}
	else {
		//plak
		LinkedList<T> total = stap1.concat(stap2);

		//sla op
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

	//inversie
	string inversie(int start, int einde) override {
		if (start == einde) {
			return "parameters zijn niet gelijk, er kan geen subtitutie plaatsvinden";
		}
		else if ((start > DNA->length()) || (einde > DNA->length())) {
			return "parameters are wrong, they will result in an array out of bound";
		}//check params

		//snij
		LinkedList<T> eerstedeel = DNA->slice(0, start);
		LinkedList<T> tweededeel = DNA->slice(einde, DNA->length());

		//stonks is dna maar omgedraaid
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

		//plak
		LinkedList<T> sequence(stonks, true);
		
		//plak
		LinkedList<T> stap1 = eerstedeel.concat(sequence);
		LinkedList<T> total = stap1.concat(tweededeel);

		//sla op
		delete DNA;
		DNA = new LinkedList<T>(total);

		//print
		cout << "sub: " << DNA->length() << endl;
		for (int x = 0; x < DNA->length(); x++) {
			cout << DNA->at(x);
		}
		cout << endl;

		return "sucsess";
	}

};