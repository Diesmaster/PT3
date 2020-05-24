

#include <iostream>
#include <cstdint>
#include <fstream>
#include <string>
#include <bitset>

template <typename T>
class ArrayInt {
	T* array;
	int numberBases = 0;
	const int intsize = sizeof(T) * 4;
	int elemInArray = 0;

	void fillArray(std::string input) {
		std::ifstream fin(input);
		char kar;
		fin.get(kar);
		int pos = 0;
		bool end = false;

		while (!fin.eof() && !end) {
			T number = 0;
			for (int i = 0; i < intsize; ++i) {
				if (fin.eof() || (kar != 'A' && kar != 'T' && kar != 'C' && kar != 'G')) {
					number <<= 2;
					fin.get(kar);
					end = true;
					continue;
				}
				leftShift(number, kar);
				numberBases++;
				fin.get(kar);
			}
			array[pos] = number;
			pos++;
		}
	}

	ArrayInt(int numberBases, int seqnumberBases, int totElem) {
		this->numberBases = seqnumberBases + numberBases;
		elemInArray = totElem;
		array = new T[totElem];
	}

	ArrayInt(int start, int end) {
		int size = end - start;
		numberBases = size;

		if (size % intsize != 0) {
			size = (size / intsize) + 1;
		}
		else { size = size / intsize; }
		array = new T[size];
		elemInArray = size;
	}

	ArrayInt() {
		numberBases = 0;
		array = new T[0];
		elemInArray = 0;
	}

	bool isValidInput(int start, int end) const {
		if (start < 0 || start > numberBases || end < 0 || end > numberBases || end < start || start == end) {
			return false;
		}
		return true;
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

	void fillArrayString(std::string &PassedString) {
		//std::ifstream fin(input);
		char kar;
		kar = PassedString[0];
		int pos = 0;
		int x = 1;
		bool end = false;
		while (!end) {
			T number = 0;
			for (int i = 0; i < intsize; ++i) {
				if (x > PassedString.length()) {
					number <<= 2;
				
					x++;
					end = true;
					continue;
				}
				leftShift(number, kar);
				numberBases++;
				
				kar = PassedString[x];
				x++;
			}
			array[pos] = number;
			
			pos++;
		}
	}

public:
	ArrayInt(std::string &stringpassed, bool dikkelul) {

		size_t size = stringpassed.size();

		if (size % intsize != 0) {
			size = (size / intsize) + 1;
		}
		else { size = size / intsize; }

		array = new T[size + 1];
		elemInArray = size;

		

		fillArrayString(stringpassed);
	}

	~ArrayInt() {
		delete[] array;
	}

	ArrayInt(const ArrayInt& object) {
		std::cout << "ik copy " << object.elemInArray << " " << object.numberBases;
		if (&object == this) return;
		numberBases = object.numberBases;
		array = new T[object.elemInArray];
		elemInArray = object.elemInArray;
		for (int i = 0; i < object.elemInArray; ++i) {
			array[i] = object.array[i];
		}

	}

	ArrayInt(std::string input) {
		std::ifstream fin(input);
		while (!fin) {
			std::cout << std::endl << "File not found!" << std::endl;
			std::cout << std::endl << "Enter file name: " << std::endl;
			input.clear();
			std::cin >> input;
			fin.open(input);
		}
		std::string stringInFile;
		fin >> stringInFile;

		size_t size = stringInFile.size();
		if (size % intsize != 0) {
			size = (size / intsize) + 1;
		}
		else { size = size / intsize; }

		array = new T[size + 1];
		elemInArray = size;

		fillArray(input);
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
		T tempnumber = array[intlocation];

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

	int length() const {
		return numberBases;
	}

	ArrayInt<T> concat(const ArrayInt<T>& seq) const {
		int totElem = seq.numberBases + numberBases;
		if (totElem % intsize != 0) {
			totElem = (totElem / intsize) + 1;
		}
		else { totElem = totElem / intsize; }

		ArrayInt<T> concseq(numberBases, seq.numberBases, totElem);

		for (int i = 0; i < elemInArray; ++i) {
			concseq.array[i] = array[i];
		}

		T number = array[elemInArray - 1];

		int freespace = intsize - (numberBases % intsize);

		for (int i = 0; i < freespace; ++i) {
			number >>= 2;
		}

		if (freespace == intsize) {
			freespace = 0;
		}

		if (freespace != 0) {
			for (int i = 0; i < freespace; ++i) {
				char base = seq.at(i);
				if (base == ' ') {
					number <<= 2;
				}
				leftShift(number, base);
			}

			concseq.array[elemInArray - 1] = number;
			number = 0;
		}

		int counter = 0;
		int pos = elemInArray;
		for (int i = freespace; i < seq.numberBases; ++i) {
			char base = seq.at(i);
			leftShift(number, base);
			counter++;
			if (counter % intsize == 0) {
				concseq.array[pos] = number;
				counter = 0;
				pos++;
			}
		}

		while (counter % intsize != 0) {
			number <<= 2;
			counter++;
			if (counter % intsize == 0) {
				concseq.array[pos] = number;
			}
		}

		return concseq;
	}

	ArrayInt<T> slice(int start, int end) const {
		if (!isValidInput(start, end)) {
			std::cout << "Incorrect Parameters to Slice!" << std::endl;
			exit(0);
		}

		ArrayInt<T> temp(start, end);

		int counter = 0;
		int pos = 0;
		T number = 0;

		for (int i = start; i < end; ++i) {
			char base = at(i);
			leftShift(number, base);
			counter++;

			if (counter % intsize == 0) {
				temp.array[pos] = number;
				pos++;
				number = 0;
			}
		}
		while (counter % intsize != 0) {
			number <<= 2;
			counter++;
			if (counter % intsize == 0) {
				temp.array[pos] = number;
			}
		}
		return temp;
	}

	bool equal(const ArrayInt<T>& seq) const {
		if (seq.numberBases != numberBases) {
			return false;
		}

		for (int i = 0; i < elemInArray; ++i) {
			if (seq.array[i] != array[i]) {
				return false;
			}
		}
		return true;
	}
};






