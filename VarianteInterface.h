
#include <iostream>
#include <cstdint>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class VariantInterface {

public:
	virtual void read(string input) = 0;
	virtual void write() = 0;
	virtual string opdracht(int start, int einde, string optie, string seq = "") = 0;
	virtual ~VariantInterface() {};

	string supplyVector(vector< string > opdrachten) {
		for (int x = 0; x < (int)opdrachten.size(); x++) {
			string test = opdrachten[x];
			string strStart;
			string strEinde;
			int start, einde;
			string optie;
			string seq = "";
			
			char kar;
			int p = 0;
			int t = 0;

			while (kar != '.') {
				kar = test[x];
				if (kar == ',') {
					t++;
				}else {
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
				x++;
			}
			start = std::stoi(strStart);
			einde = std::stoi(strEinde);

			opdracht(start, einde, optie, seq);
		}
	}

private:
	virtual string subtitutie(int start, int einde, string seq) = 0;
	virtual string incerties(int start, int einde, string seq) = 0;
	virtual string delitieIncertie(int start, int einde, string seq) = 0;
	virtual string inversie(int start, int einde) = 0;
	virtual string delitie(int start, int einde) = 0;

};