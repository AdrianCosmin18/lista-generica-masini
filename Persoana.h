#include"Masina.h"

class Persoana
{
private:
	string nume;
	string gen;
	double h;

public:


	string get_nume() { return nume; }
	string get_gen() { return gen; }
	double get_h() { return h; }

	void set_nume(string n) { nume = n; }
	void set_gen(string g) { gen = g; }
	void set_h(double h) { this->h = h; }


	Persoana() :nume{ "anonim" }, gen{ "M" }, h{ 1.8 }{}

	Persoana(string n, string g, double inaltime) : nume{ n }, gen{ g }, h{ inaltime }{}

	Persoana(string prp) {

		string v[3];
		int poz = prp.find(',');
		int k = -1;
		while (poz != string::npos) {

			k++;
			v[k] = prp.substr(0, poz);
			prp.erase(0, poz + 1);
			poz = prp.find(',');
		}
		v[2] = prp;


		nume = v[0];
		gen = v[1];
		h = stod(v[2]);
	}

	bool operator< (Persoana p){

		return (this->h < p.h);
	}

	bool operator== (Persoana p){
	
		return (this->h == p.h);
	}

	friend ostream& operator<<(ostream& os, const Persoana& p) {


		string text = "";
		text = "\nNume : " + p.nume;
		text += "\nGen : " + p.gen;
		text += "\nInaltime : " + to_string(p.h);
		text += "\n";

		os << text;

		return os;
	}

	string describe_to_file() {

		string text = nume + "," + gen + "," + to_string(h);
		return text;
	}
};

