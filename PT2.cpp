#include <iostream>
#include <string>
#include <bitset>
#include <vector>

//#include "ArrayInt.h"
#include "LinkedList.h"
#include "DNAstring.h"

#include "StringVariente.h"
//#include "VarianteInterface.h"

#include "LinkedListVariente.h"
#include "ArrayIntVariente.h"


//deze start het prigramma
bool startProgram(VariantInterface* ptr) {
	bool stop = false;
	
	//selecteer het type interactie
	string antwoord;
	cout << "wilt u automaties de taken uitvoeren? ja/nee" << endl;
	cin >> antwoord;
	
	//de automatische kant
	if (antwoord == "ja") {
		
		string input; //krijg de input file
		cout << "welke file wilt u gebruiken?" << endl;
		cin >> input;
		
		//maak de instructies
		vector<string> instructies;
		std::ifstream fin(input);
		string instructie;
		fin >> instructie;
		
		while(!fin.eof()){
			instructies.push_back(instructie);
			fin >> instructie;
		}
		
		//geef de instructies door
		ptr->supplyVector(instructies);

		//vraag of je het wilt wegschrijven in een bestand
		cout << "wilt u de file wegschrijven naar een document? (ja/nee)" << endl;
		cin >> antwoord;
		
		//krijg het path naar het bestand
		string output;
		if (antwoord == "ja") {
			cout << "naar welke file?" << endl;
			cin >> output;
			ptr->write(output);
		}

	}else {
		//handmatig klieren
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
	}
	//je hebt het overleeft
	return true;
}


int main() {

	//kies het type opslag bestand
	int keuze = -1;
	while ((keuze != 1) && (keuze != 2) && (keuze != 3)) {
		cout << "Wilt u het opslaan in een array(1), of in een pointerlijst(2), of een string(3)?" << endl;
		cout << "druk op 1 of 2 of 3 respectivelijk" << endl;
		cin >> keuze;
	}

	//kies het type type opslag bestand
	int groote = -1;
	while ((groote != 8) && (groote != 16) && (groote != 32)) {
		cout << "Wilt u het opslaan in 8, 16, of 32 bit integers?" << endl;
		cout << "typ de groote in die u verlangt" << endl;
		cin >> groote;
	}

	//geef de file name waar het basis dna in is opgeslagen
	std::string input;
	std::cout << "Geef alst u blieft de file name" << std::endl;
	std::cin >> input;
	
	//start het programma met het correcte object
	if (keuze == 2) { //linked list
		switch (groote) {
		case 8:
		{
			LinkedListVariente<uint8_t>* oeps = new LinkedListVariente<uint8_t>();
			oeps->read(input);
			startProgram(oeps);
			delete oeps;
		}
		break;
		case 16:
		{
			LinkedListVariente<uint16_t>* oeps2 = new LinkedListVariente<uint16_t>();
			oeps2->read(input);
			startProgram(oeps2);
			delete oeps2;
		}
		break;
		case 32:
		{
			LinkedListVariente<uint32_t>* oeps3 = new LinkedListVariente<uint32_t>();
			oeps3->read(input);
			startProgram(oeps3);
			delete oeps3;
		}
		break;
		}
	}
	else if(keuze == 1){ //arrayint
		switch (groote) {
		case 8:
		{
			ArrayIntVariente<uint8_t>* oof1 = new  ArrayIntVariente<uint8_t>;
			oof1->read(input);
			startProgram(oof1);
			delete oof1;
		}
		break;
		case 16:
		{
			ArrayIntVariente<uint16_t>* oof2 = new  ArrayIntVariente<uint16_t>;
			oof2->read(input);
			startProgram(oof2);
			delete oof2;
		}
		break;
		case 32:
		{
			ArrayIntVariente<uint32_t>* oof3 = new  ArrayIntVariente<uint32_t>;
			oof3->read(input);
			startProgram(oof3);
			delete oof3;
		}
		break;
	}
	}else if(keuze == 3){ //string
		StringVariente* String = new StringVariente();
		String->read(input);
		startProgram(String);
		delete String;
	}
	//we zijn klaar
	return 0;
}

/*nog een fijne dag <3*/



