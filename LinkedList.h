
#pragma once
#include <iostream>
#include <cstdint>
#include <fstream>
#include <string>

using namespace std;

template <typename T>
class LinkedList {
	int numberBases = 0;
	const int intsize = sizeof(T) * 4;
	int listSize = 0;

	struct object {
		T number;
		object* next;
		object* prev;

		object() {
			number = 0;
			next = nullptr;
			prev = nullptr;
		}
	};

	void add_back(T value) {
		object* temp;
		temp = new object;
		temp->number = value;

		if (front) {
			temp->prev = end;
			end->next = temp;
			end = temp;
		}
		else {
			front = temp;
			temp->prev = nullptr;
			temp->next = nullptr;
			end = temp;
		}
		listSize++;
	}

	void leftShift(T& number, char base) const {
		if (base == 'A') {
			number <<= 2;
		}
		if (base == 'T') {
			number = (number << 2) | 1;
		}
		if (base == 'C') {
			number = (number << 2) | 2;
		}
		if (base == 'G') {
			number = (number << 2) | 3;
		}
	}

	bool isValidInput(int start, int end) const {
		if (start < 0 || start > numberBases || end < 0 || end > numberBases || end < start || start == end) {
			return false;
		}
		return true;
	}

	LinkedList(int start, int end) {
		numberBases = end - start;
	}

	

public:

	object* front = nullptr;
	object* end = nullptr;

	LinkedList() {
		numberBases = 0;
	}


	LinkedList(const LinkedList& other) {
		numberBases = other.numberBases;
		object* help = other.front;
		while (help) {
			add_back(help->number);
			help = help->next;
		}
	}

	~LinkedList() {
		while (front) {
			object* current = front;
			front = front->next;
			delete current;
		}
	}

	LinkedList(std::string input, bool bigPeen) {
		//std::ifstream fin(input);
		char base = input[0];
		int x = 1;
		bool end = false;
		//fin.get(base);

		while (!end) {
			T number = 0;
			for (int i = 0; i < intsize; ++i) {
				if (x > (int)input.length()) {
					number <<= 2;
					//fin.get(base);
					x++;
					end = true;
					continue;
				}
				leftShift(number, base);
				numberBases++;
				base = input[x];
				x++;
			}
			add_back(number);
		}
	}


	LinkedList(std::string input) {
		std::ifstream fin(input);
		char base;
		bool end = false;
		fin.get(base);

		while (!fin.eof() && !end) {
			T number = 0;
			for (int i = 0; i < intsize; ++i) {
				if (fin.eof() || (base != 'A' && base != 'T' && base != 'C' && base != 'G')) {
					number <<= 2;
					fin.get(base);
					end = true;
					continue;
				}
				leftShift(number, base);
				numberBases++;
				fin.get(base);
			}
			add_back(number);
		}
	}

	int length() const {
		return numberBases;
	}

	bool equal(const LinkedList<T> seq) const {
		if (seq.numberBases != numberBases) {
			return false;
		}

		object* a = seq.front;
		object* b = front;

		while (b->next != nullptr) {
			if (a->number != b->number) {
				return false;
			}
			a = a->next;
			b = b->next;
		}
		return true;
	}

	LinkedList<T> concat(const LinkedList<T> &seq) const{
		LinkedList<T> concseq;
		concseq.numberBases = numberBases + seq.numberBases;

		object* temp = front;

		while (temp) {
			concseq.add_back(temp->number);
			temp = temp->next;
		}

		T number = concseq.end->number;

		int freespace = intsize - (numberBases % intsize);
		

		for (int i = 0; i < freespace; ++i) {
			number >>= 2;
		}

		if (freespace != 0) {
			for (int i = 0; i < freespace; ++i) {
				char base = seq.at(i);
				if (base == ' ') {
					number <<= 2;
				}
				leftShift(number, base);
			}
			concseq.end->number = number;
			number = 0;
		}

		int counter = 0;
		for (int i = freespace; i < seq.numberBases; ++i) {
			char base = seq.at(i);
			leftShift(number, base);
			counter++;
			if (counter % intsize == 0) {
				concseq.add_back(number);
				counter = 0;
			}
		}

		while (counter % intsize != 0) {
			number <<= 2;
			counter++;
			if (counter % intsize == 0) {
				concseq.add_back(number);
			}
		}

		return concseq;
	}

	LinkedList<T> slice(int start, int end) const {
		if (!isValidInput(start, end)) {
			std::cout << "invalid parameters!" << std::endl;
			LinkedList<T> error;
			return error;
		}

		LinkedList<T> temp(start, end);

		int counter = 0;
		T number = 0;

		for (int i = start; i < end; ++i) {
			char base = at(i);
			leftShift(number, base);
			counter++;
			if (counter % intsize == 0) {
				temp.add_back(number);
				number = 0;
			}
		}

		while (counter % intsize != 0) {
			number <<= 2;
			counter++;
			if (counter % intsize == 0) {
				temp.add_back(number);
			}
		}
		
		return temp;
	}

	char at(int pos) const {
		if (pos >= numberBases || pos < 0) {
			return ' ';
		}

		int intlocation = pos / intsize;
		int shiftamount = intsize - ((pos + 1) % intsize);

		if (shiftamount == intsize) {
			shiftamount = 0;
		}
		T tempnumber = 0;

		object* temp = front;
		for (int i = 0; i <= intlocation; ++i) {
			tempnumber = temp->number;
			temp = temp->next;
		}

		for (int i = 0; i < shiftamount; ++i) {
			tempnumber >>= 2;
		}
		tempnumber &= 3;

		if (tempnumber == 0) {
			return 'A';
		}
		else if (tempnumber == 1) {
			return 'T';
		}
		else if (tempnumber == 2) {
			return 'C';
		}
		else if (tempnumber == 3) {
			return 'G';
		}
		return ' ';
	}

};