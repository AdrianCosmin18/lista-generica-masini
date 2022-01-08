#include <iostream>
#include<string>
using namespace std;

class Masina
{
private:
	string marca;
	string model;
	int an;

public:

	string get_marca() { return marca; }
	string get_model() { return model; }
	int get_an() { return an; }

	void set_marca(string m) { marca = m; }
	void set_model(string m) { model = m; }
	void set_an(int a) { an = a; }

	Masina() :marca{ "anonima" }, model{ "anonim" }, an{ 0 }{}

	Masina(string marc, string mod, int a) :marca{ marc }, model{ mod }, an{ a }{}

	Masina(string prp) {

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


		marca = v[0];
		model = v[1];
		an = stoi(v[2]);
	}


	virtual string describe() {

		string text = "";
		text = "\nMarca : " + marca;
		text += "\nModel : " + model;
		text += "\nAn : " + to_string(an);
		text += "\n";

		return text;
	}

	//suprascriem operatorii de comparare
	bool operator< (Masina m1) {

		return (this->an < m1.an);
	}

	bool operator== (Masina m1) {

		return (this->marca == m1.marca && this->model == m1.model && this->an == m1.an);
	}//equals

	friend ostream& operator<<(ostream& os, const Masina& m) {


		string text = "";
		text = "\nMarca : " + m.marca;
		text += "\nModel : " + m.model;
		text += "\nAn : " + to_string(m.an);
		text += "\n";

		os << text;

		return os;
	}


};

