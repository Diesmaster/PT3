#include <iostream>
#include <string>
#include <bitset>

#include "ArrayInt.h"
#include "LinkedList.h"

#include "VarianteInterface.h"

#include "LinkedListVariente.h"
#include "ArrayIntVariente.h"
#include "StringVariente.h"


string manipulatie(VariantInterface* ptr) {
	return "success";
}

bool startProgram(VariantInterface* ptr) {
	bool stop = false;
	while (stop != true) {
		int start, einde;
		string type, seq;
		cout << "als u wilt stoppen met de varianten voer dan stop waar type moet in." << endl;
		cout << "als u varianten wilt maken druk gebruik dan deze manier: " << endl;
		cout << "start, end, type, seq(optioneel). Typ een enter waar een comma staat" << endl;
		cin >> start;
		cin >> einde;
		cin >> type;
		cin >> seq;
		if (type == "stop") {
			return true;
		}
		cout << ptr->opdracht(start, einde, type, seq) << endl;
	}
	return true;
}


int main() {
	int keuze = -1;
	while ((keuze != 1) && (keuze != 2)) {
		cout << "Wilt u het opslaan in een array(1), of in een pointerlijst(2), of een string(3)?" << endl;
		cout << "druk op 1 of 2 of 3 respectivelijk" << endl;
		cin >> keuze;
	}
	int groote = -1;
	while ((groote != 8) && (groote != 16) && (groote != 32)) {
		cout << "Wilt u het opslaan in 8, 16, of 32 bit integers?" << endl;
		cout << "typ de groote in die u verlangt" << endl;
		cin >> groote;
	}

	std::string input;
	std::cout << "Geef alst u blieft de file name" << std::endl;
	std::cin >> input;
	

	//VariantInterface* ptr;

	if (keuze == 2) {
		switch (groote) {
		case 8:
		{
			LinkedListVariente<uint8_t> oeps;
		}
		break;
		case 16:
		{
			LinkedListVariente<uint16_t> oeps2;
		}
		break;
		case 32:
		{
			LinkedListVariente<uint32_t> oeps3;
		}
		break;
		}
	}
	else if(keuze == 1){
		switch (groote) {
		case 8:
		{
			ArrayIntVariente<uint8_t>* oof1 = new  ArrayIntVariente<uint8_t>;
			oof1->read(input);
			startProgram(oof1);
		}
		break;
		case 16:
		{
			ArrayIntVariente<uint16_t>* oof2 = new  ArrayIntVariente<uint16_t>;
			oof2->read(input);
			startProgram(oof2);
		}
		break;
		case 32:
		{
			ArrayIntVariente<uint32_t>* oof3 = new  ArrayIntVariente<uint32_t>;
			oof3->read(input);
			startProgram(oof3);
		}
		break;
		}
	}else {
		StringVariente(input);
	}
	return 0;
}



