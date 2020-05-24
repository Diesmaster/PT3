
#include <iostream>
#include <cstdint>
#include <fstream>
#include <string>

using namespace std;

class VariantInterface {

public:
	virtual void read(string input) = 0;
	virtual void write() = 0;
	virtual string opdracht(int start, int einde, string optie, string seq = "") = 0;

private:
	virtual string subtitutie(int start, int einde, string seq) = 0;
	virtual string incerties(int start, int einde, string seq) = 0;
	virtual string delitieIncertie(int start, int einde, string seq) = 0;
	virtual string inversie(int start, int einde) = 0;
	virtual string delitie(int start, int einde) = 0;

};