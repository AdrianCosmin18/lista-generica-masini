#include"ControlPersoana.h"
class Rent_Car
{
private:
	int id;
	string nume_persoana;
	string marca_masina;
	string model_masina;

public:

	int get_id() { return id; }
	string get_nume_persoana() { return nume_persoana; }
	string get_marca_masina() { return marca_masina; }
	string get_model_masina() { return model_masina; }

	void set_id(int id) { this->id = id; }
	void set_nume_persoana(string nume) { nume_persoana = nume; }
	void set_marca_masina(string marca) { marca_masina = marca; }
	void set_model_masina(string model) { model_masina = model; }

	Rent_Car(int ID, string nume_p, string marca, string model):id{ID}, nume_persoana{nume_p}, marca_masina{marca}, model_masina{model}{}

	Rent_Car(string prp) {

		string v[4];
		int k = -1;
		int poz = prp.find(',');

		while (poz != string::npos) {

			k++;
			v[k] = prp.substr(0, poz);
			prp.erase(0, poz + 1);
			poz = prp.find(',');
		}

		v[3] = prp;

		id = stoi(v[0]);
		nume_persoana = v[1];
		marca_masina = v[2];
		model_masina = v[3];
	}

	friend ostream& operator<<(ostream& os, const Rent_Car& rc) {


		string text = "";
		text += "\nID : " + to_string(rc.id);
		text += "\nNume persoana: " + rc.nume_persoana;
		text += "\nMarca masina : " + rc.marca_masina;
		text += "\nModel masina : " + rc.model_masina;
		text += "\n";

		os << text;

		return os;
	}

	bool operator== (Rent_Car rc) {

		return this->get_marca_masina() == rc.get_marca_masina() && this->get_model_masina() == rc.get_model_masina(); 
	}

	string describe_to_file() {

		string text = to_string(id) + "," + nume_persoana + "," + marca_masina + "," + model_masina;
		return text;
	}
};

