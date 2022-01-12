#include"ControlRent_Car.h"

class View
{
private:
	ControlMasina* cm;
	ControlPersoana* cp;

public:

	View() {

		cm = new ControlMasina();
		cp = new ControlPersoana();
	}

	void meniu() {

		cout << "\nSetari pentru grupul de masini : "<<endl;
		cout << "\nLista masini, tasta 1";
		cout << "\nAdauga o masina, tasta 2";
		cout << "\nSterge o masina, tasta 3";
		cout << "\nAfiseaza o masina dupa marca si model, tasta 4";
		cout << "\nModifica anul unei masini, tasta 5";
		cout << "\nVerifica existenta unei masini, tasat 6" << endl<<endl;

		cout << "\nSetari pentru grupul de perosane : " << endl;
		cout << "\nLista persoane, tasta 7";
		cout << "\nAdauga o persoana, tasta 8";
		cout << "\nSterge o persoana, tasta 9";
		cout << "\nAfiseaza o persoana dupa nume si gen, tasta 10";
		cout << "\nModifica inaltimea unei persoane, tasta 11";
		cout << "\nVerifica existenta unei persoane, tasat 12"<<endl<<endl;

		cout << "\nSetari pentru grupul de inchirieri masini :" << endl;
		cout << "\nLista de inchirieri, tasta 13 ";
		cout << "\nInregistreaza o noua inchriere, tasta 14";
		cout << "\nAfiseaza o inchiriere dupa id, tasta 15";
		cout << "\nSterge o inchiriere, tasta 16";
		cout << "\nModifica o inchiriere, tasta 17"<<endl;

	}


	void play() {

		bool play = 0;
		while (play == false) {

			meniu();

			int tasta;
			string t;
			cout << "\nTasta : ";
			getline(cin, t);
			tasta = stoi(t);

			switch (tasta) {

			case 1:
				cm->traverse();
				break;

			case 2:
				add_car();
				break;

			case 3:

			}
		}
	}

	void add_car() {

		cout << "\nMarca masina noua : ";
		string marca;
		getline(cin, marca);

		cout << "\nModel masina noua : ";
		string model;
		getline(cin, model);

		cout << "\nAnul noii masini : ";
		int an;
		string a;
		getline(cin, a);
		an = stoi(a);

		if (cm->Get_poz_by_marca_model(marca, model) == -1) {

			cm->add_masina(new Masina(marca, model, an));
		}
		else {

			cout << "\nExista deja o masina cu aceasta marca si acest model, nu se mai poate aduga una cu acelasi denumiri";
		}

		//updatam fisierul cu masini
		cm->save_to_file();
	}

	void delete_car() {

		cout << "\nMarca masina : ";
		string marca;
		getline(cin, marca);

		cout << "\nModel masina  : ";
		string model;
		getline(cin, model);
	}
};

