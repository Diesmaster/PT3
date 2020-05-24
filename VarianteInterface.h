
#include <iostream>
#include <cstdint>
#include <fstream>
#include <string>
#include <vector>

class VariantInterface {

public:
	//leest een filepath in en output niks
	virtual void read(string input) = 0;

	//schrijft DNA weg naar een output file, output is filepath
	virtual void write(string output) = 0;
	
	//leest een opdracht in, en output de message succses of error
	virtual string opdracht(int start, int einde, string optie, string seq = "") = 0;
	
	//destructor
	virtual ~VariantInterface() {};

	//de vector drugdealer, die opdrachten automatischeerd
	string supplyVector(vector< string > opdrachten) {
		for (int x = 0; x < (int)opdrachten.size(); x++) {
			string test = opdrachten[x];
			string strStart;
			string strEinde;
			int start, einde;
			string optie;
			string seq = "";
			
			char kar = ' ';
			int p = 0;
			int t = 1;

			while (kar != '.') {
				kar = test[p];
				if (kar == ',') {
					t++;
				}else if(kar != '.'){
					switch (t) {
					case 1:
						strStart = strStart + kar;
						break;
					case 2:
						strEinde = strEinde + kar;
						break;
					case 3:
						optie = optie + kar;
						break;
					case 4:
						seq = seq + kar;
						break;
					}
				}
				p++;
			}
			start = std::stoi(strStart);
			einde = std::stoi(strEinde);
			cout << strStart << " " << strEinde << " " << optie << " " << seq << " " << endl;
			//cout << "size: " << opdrachten.size() << endl;
			opdracht(start, einde, optie, seq);
		}
		return "sucses";
	}

private:
	//veranderd 1 char voor een andere
	virtual string subtitutie(int start, int einde, string seq) = 0;
	//voegt een string toe op een plek
	virtual string incerties(int start, int einde, string seq) = 0;
	//een grote subtitiutie
	virtual string delitieIncertie(int start, int einde, string seq) = 0;
	//maakt een stukje string invers
	virtual string inversie(int start, int einde) = 0;
	//delete een stukje string
	virtual string delitie(int start, int einde) = 0;

};