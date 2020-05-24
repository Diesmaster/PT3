#pragma once
#include <iostream>
#include <string>
#include <bitset>
#include "LinkedList.h"

using namespace std;

template<typename T>
class LinkedListVariente: public VariantInterface {
public:

	void read(string input) override {
		return;
	}
	
	void write() override {
		return;
	}
	
	string opdracht(int start, int einde, string optie, string seq = "") override {
		/*switch (optie) {
		case ">":
			subtitutie(start, einde, seq);
			break;
		case "ins":
			incerties(start, einde, seq);
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
	LinkedList<T>* DNA;

	string subtitutie(int start, int einde, string seq) override {
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