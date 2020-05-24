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
	
	//destrutor
	~ArrayIntVariente() {
		//std::cerr << "stonks" << endl;
		delete DNA;
	}
	

	//read functie implementatie
	void read(string input) override {
		DNA = new ArrayInt<T>(input);
	
		return;
	}

	//write functie implementatie
	void write(string output) override {
		std::ofstream myfile;
		myfile.open(output); //output file
		string result; //string die je boutw
		for (int x = 0; x < DNA->length(); x++){ //loop door DNA heen
			result = result + DNA->at(x); //krijg alle kars
		}
		myfile << result << '\n'; //schrijf het weg
		return; //back 
	}

	string opdracht(int start, int einde, string optie, string seq = "") override {
		//swtichen mag niet met strings......
		if (optie == ">") {
			return subtitutie(start, einde, seq);
		}else if (optie == "ins") {
			return incerties(start, einde, seq);
		}else if (optie == "del") {
			return delitie(start, einde); //dan doen we het maar zo hahaha
		}else if (optie == "delins") {
			return delitieIncertie(start, einde, seq);
		}else if (optie == "inv") {
			return inversie(start, einde);
		}else {
			return "dit is geen bestaande naam"; //typfout?
		}
		
		return "success";//helemaal top;
	}

private:

	//waar het allemaal om gaat
	ArrayInt<T>* DNA = nullptr;


	//dna is blijbaar geen dom, logisch ook geen JS in zicht...
	string subtitutie(int start, int einde, string seq) override {

		//ff een kleine check
		if (start != einde) {
			return "parameters zijn niet gelijk, er kan geen subtitutie plaatsvinden";
		}
		else if ((start > DNA->length()) || (einde > DNA->length())) {
			return "parameters are wrong, they will result in an array out of bound";
		}else if(start == 0){ //sub's worden anders als ze daadwerkelijk niks waard zijn, je kan dan niet meer aftrekken
			ArrayInt<T> sequentie(seq, true); //je kan hier nml geen -1 op start doen
			ArrayInt<T> TweedeDeel = DNA->slice(1, DNA->length()); //wel makkelijker voor de rest
			ArrayInt<T> total = sequentie.concat(TweedeDeel);
			delete DNA;
			DNA = new ArrayInt<T>(total);
		}
		else {
			ArrayInt<T> Eerstehelft = DNA->slice(0, start-1); //slice netjes het caracter wat je weg wilt 
			ArrayInt<T> Tweedehelft = DNA->slice(start, DNA->length() ); //uit je string

			ArrayInt<T> sequentie(seq, true); //wat we erbij willen stoppen
		
			
			ArrayInt<T> stap1 = Eerstehelft.concat(sequentie); //concat het allemaal
			ArrayInt<T> total = stap1.concat(Tweedehelft); 
			
			delete DNA;
			DNA = new ArrayInt<T>(total); //sla de totaal op
		}

		//printen
		std::cout << "eerstehelft concat sequentie: " << DNA->length() << endl;
		for (int x = 0; x < DNA->length(); x++) {
			std::cout << DNA->at(x);
		}
		std::cout << endl;

		//gelukt
		return "success";
	}

	//haalt een stukje weg, zonder er iets voor in de plaats te zetten
	string delitie(int start, int einde) override {
		if ((start > DNA->length()) || (einde > DNA->length())) {
			return "parameters are wrong, they will result in an array out of bound";
		} //wel checken die handel

		//snei het ding weg
		ArrayInt<T> Eerstehelft = DNA->slice(0, start );
		ArrayInt<T> Tweedehelft = DNA->slice(einde, DNA->length());

		delete DNA; //voeg het weer samen
		ArrayInt<T> total = Eerstehelft.concat(Tweedehelft);
		DNA = new ArrayInt<T>(total); //stop het in DNA


		std::cout << "delitie" << DNA->length() << endl; //print
		for (int x = 0; x < DNA->length(); x++) {
			std::cout << DNA->at(x);
		}
		std::cout << endl;
		
		//gelukt
		return "success";
	}

	//stop ergens een getal tussen
	string incerties(int start, int einde, string seq) override {
		if (start != einde) {
			return "parameters zijn niet gelijk, er kan geen subtitutie plaatsvinden";
		}
		else if ((start > DNA->length()) || (einde > DNA->length())) {
			return "parameters are wrong, they will result in an array out of bound";
		} //geen gekke getallen als je blieft

		//maak netjes een snee
		ArrayInt<T> Eerstehelft = DNA->slice(0, start);
		ArrayInt<T> Tweedehelft = DNA->slice(start, DNA->length());
		
		//prepare het perperaat
		ArrayInt<T> sequentie(seq, true);

		ArrayInt<T> stap1 = Eerstehelft.concat(sequentie);
		
		delete DNA; //laat het erin glijden
		ArrayInt<T> total = stap1.concat(Tweedehelft); //goed vast lijmen
		DNA = new ArrayInt<T>(total); //lekker klemmen

		//print het
		std::cout << "resultaat" << DNA->length() << endl;
		for (int x = 0; x < DNA->length(); x++) {
			std::cout << DNA->at(x);
		}
		std::cout << endl; 

		//vlag uit?
		return "geslaagt";
	}

	//een deletie en een incertie
	string delitieIncertie(int start, int einde, string seq) override {
		if ((start > DNA->length()) || (einde > DNA->length())) {
			return "parameters are wrong, they will result in an array out of bound";
		}//check de params

		//maak de snee
		ArrayInt<T> Eerstehelft = DNA->slice(0, start);
		ArrayInt<T> Tweedehelft = DNA->slice(einde, DNA->length());

		ArrayInt<T> sequentie(seq, true);

		ArrayInt<T> stap1 = Eerstehelft.concat(sequentie);
		
		//plak het erin
		delete DNA;
		ArrayInt<T> total = stap1.concat(Tweedehelft);
		DNA = new ArrayInt<T>(total);

		//print
		std::cout << "delitie-incertie" << DNA->length() << endl;
		for (int x = 0; x < DNA->length(); x++) {
			std::cout << DNA->at(x);
		}
		std::cout << endl;
		//jeeeh
		return "success";
	}

	//omgekeerd
	string inversie(int start, int einde) override {
		if (start == einde) {
			return "parameters zijn gelijk, er kan geen slice plaatsvinden";
		}
		else if ((start > DNA->length()) || (einde > DNA->length())) {
			return "parameters are wrong, they will result in an array out of bound";
		}//check params

		//maak de snee
		ArrayInt<T> Eerstehelft = DNA->slice(0, start);
		ArrayInt<T> Tweedehelft = DNA->slice(einde, DNA->length());
		
		//draai alles om
		string stonks;
		for (int x = start; x < einde; x++) {
			char test = DNA->at(x);
			std::cout << x << " " << test << endl;
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
		
		//maar er een arrayint van
		ArrayInt<T> sequentie(stonks, true);
		
		//plak hem
		ArrayInt<T> stap1 = Eerstehelft.concat(sequentie);
		

		delete DNA;
		ArrayInt<T> total = stap1.concat(Tweedehelft);
		DNA = new ArrayInt<T>(total);
		
		//print
		std::cout << "inv" << DNA->length() << endl;
		for (int x = 0; x < DNA->length(); x++) {
			std::cout << DNA->at(x);
		}
		std::cout << endl;

		//jeeh
		return "success";
	}

};