#include"ControlRent_Car.h"

class View
{
private:
	ControlMasina* cm;
	ControlPersoana* cp;
	ControlRent_Car* crc;

public:

	View() {

		cm = new ControlMasina();
		cp = new ControlPersoana();
		crc = new ControlRent_Car();
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

		cout << "\nPentru a iesi, tast 18";

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
				delete_car();
				break;

			case 4:
				get_describe_by_marca_model();
				break;

			case 5:
				modify_year();
				break;

			case 6:
				exist_car();
				break;

			case 7:
				cp->traverse();
				break;

			case 8:
				add_person();
				break;

			case 9:
				delete_person();
				break;

			case 10:
				get_describe_by_name_gander();
				break;

			case 11:
				modify_height();
				break;

			case 12:
				get_describe_by_name_gander();
				break;

			case 13:
				crc->traverse();
				break;

			case 14:
				add_rent();
				break;

			case 15:
				get_descibe_rent();
				break;

			case 16:
				delete_rent_car();
				break;

			case 17:
				modify_rent();
				break;

			case 18:
				play = true;
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

			//updatam fisierul cu masini
			cm->save_to_file();
		}
		else {

			cout << "\nExista deja o masina cu aceasta marca si acest model, nu se mai poate aduga una cu acelasi denumiri";
		}

	}

	void delete_car() {

		cout << "\nMarca masina : ";
		string marca;
		getline(cin, marca);

		cout << "\nModel masina  : ";
		string model;
		getline(cin, model);

		if (cm->exista_masina(marca, model)) {

			cm->remove(marca, model);
			cout << "\Masina a fost stearsa cu succes" << endl;

			//updatam fisierul cu masini
			cm->save_to_file();
		}
		else {

			cout << "\nNu se poate sterge aceasta masina pentru ca nu exista in baza de date";
		}
	}

	void get_describe_by_marca_model() {

		cout << "\nMarca masina : ";
		string marca;
		getline(cin, marca);

		cout << "\nModel masina  : ";
		string model;
		getline(cin, model);

		int poz = cm->Get_poz_by_marca_model(marca, model);
		if (poz != -1) {

			Node<Masina*>* node = cm->Get_Node_by_index(poz);
			cout << *(node->get_data());
		}
		else {

			cout << "\nNu exista aceasta masina";
		}
	}

	void modify_year() {

		cout << "\nModificam anul unei masini : ";
		cout << "\nMarca masina  : ";
		string marca;
		getline(cin, marca);

		cout << "\nModel masina  : ";
		string model;
		getline(cin, model);

		cout << "\nNoul an : ";
		string a;
		getline(cin, a);
		int an = stoi(a);

		if (cm->exista_masina(marca, model)) {

			cm->modify(marca, model, an);
			cout << "\nMasina modificata cu succes";

			//updatam fisierul cu masini
			cm->save_to_file();
		}
		else {

			cout << "\nNu se poate modifica aceasta masina pentru ca nu exista";
		}
	}

	void exist_car() {

		cout << "\nModificam anul unei masini : ";
		cout << "\nMarca masina  : ";
		string marca;
		getline(cin, marca);

		cout << "\nModel masina  : ";
		string model;
		getline(cin, model);

		if (cm->exista_masina(marca, model)) {

			cout << "\nMasina exista"<<endl;
		}
		else {

			cout << "\nMasina NU exista"<<endl;
		}
	}


	

	void add_person() {

		cout << "\nNume persoana : ";
		string nume;
		getline(cin, nume);

		cout << "\nGen persoana : ";
		string gen;
		getline(cin, gen);

		cout << "\nInaltime persoana : ";
		string a;
		getline(cin, a);
		double h = stod(a);

		if (!cp->exists_person(nume, gen)) {

			cp->add_persoana(new Persoana(nume, gen, h));
			cout << "\nPersoana adaugata cu succes";

			//updatam lista
			cp->save_to_file();
		}
		else {

			cout << "\nExista deja o persoana in lista cu acest nume, nu pot exsita mai mule";
		}
	}

	void delete_person() {

		cout << "\nNume persoana : ";
		string nume;
		getline(cin, nume);

		cout << "\nGen persoana : ";
		string gen;
		getline(cin, gen);

		if (cp->exists_person(nume, gen)) {

			cp->remove(nume, gen);
			cout << "\nPersoana stersa cu succes";

			//updatam lista
			cp->save_to_file();
		}
		else {

			cout << "\nNu exista aceasta persoana";
		}
	}

	void get_describe_by_name_gander() {

		cout << "\nNume persoana : ";
		string nume;
		getline(cin, nume);

		cout << "\nGen persoana : ";
		string gen;
		getline(cin, gen);

		if (cp->exists_person(nume, gen)) {

			int p = cp->get_index_by_nume_si_gen(nume, gen);
			cout << *(cp->get_node_by_index(p)->get_data());
		}
		else {

			cout << "\nNu exista aceasta persoana";
		}
	}

	void modify_height() {

		cout << "\nNume persoana : ";
		string nume;
		getline(cin, nume);

		cout << "\nGen persoana : ";
		string gen;
		getline(cin, gen);

		cout << "\nNoua Inaltime : ";
		string a;
		getline(cin, a);
		double h = stod(a);

		if (cp->exists_person(nume, gen)) {

			cp->modify(nume, gen, h);
			cout << "\nInaltimea persoanei a fost modificata cu succes";

			//updatam lista
			cp->save_to_file();
		}
		else {

			cout << "\nNu exista aceasta persoana";
		}
	}

	void exist_person() {

		cout << "\nNume persoana : ";
		string nume;
		getline(cin, nume);

		cout << "\nGen persoana : ";
		string gen;
		getline(cin, gen);

		if (cp->exists_person(nume, gen)) {

			cout << "\nPersoana exista";
		}
		else {

			cout << "\nPersoana NU exista";
		}
	}



	
	void add_rent() {

		cout << "\nNumele persoanei care inchiriaza : ";
		string nume;
		getline(cin, nume);

		cout << "\nGenul persoanei : ";
		string gen;
		getline(cin, gen);

		cout << "\nMarca masinii pe care o inchiriaza : ";
		string marca;
		getline(cin, marca);

		cout << "\nModelul masinii : ";
		string model;
		getline(cin, model);

		int id = crc->get_next_available_id();

		if (cm->exista_masina(marca, model) && cp->exists_person(nume, gen)) {

			crc->add(new Rent_Car(id, nume, marca, model));

			crc->save_to_file();
			cout << "\nInchirierea a fost adaugata cu succes ";
		}
		else {

			cout << "\nNu exista aceasta masina sau nu exista aceasta persoana";
		}
	}

	void get_descibe_rent() {

		cout << "\nID-ul inchirierii  : ";
		string i;
		getline(cin, i);
		int id = stoi(i);

		if (crc->exist(id)) {

			cout << *(crc->get_node_by_id(id)->get_data());
		}
		else {

			cout << "\nNu exista o inchiriere cu acest ID";
		}
	}

	void delete_rent_car() {

		cout << "\nID-ul inchirierii  : ";
		string i;
		getline(cin, i);
		int id = stoi(i);

		if (crc->exist(id)) {

			crc->remove(id);
			cout << "\nInregistrare stearsa cu succes";

			crc->save_to_file();
		}
		else {

			cout << "\nNu exista aceasta inregistrare";
		}

	}

	void modify_rent() {

		cout << "\nID-ul inchirierii  : ";
		string i;
		getline(cin, i);
		int id = stoi(i);

		if (crc->exist(id)) {


			cout << "\nNumele modificat al persoanei care inchiriaza : ";
			string nume;
			getline(cin, nume);

			cout << "\nGenul persoanei : ";
			string gen;
			getline(cin, gen);

			cout << "\nMarca modificata a masinii pe care o inchiriaza : ";
			string marca;
			getline(cin, marca);

			cout << "\nModelul modificat al masinii pe care o inchiriaza: ";
			string model;
			getline(cin, model);

			if (cp->exists_person(nume, gen) && cm->exista_masina(marca, model)) {

				crc->get_node_by_id(id)->get_data()->set_marca_masina(marca);
				crc->get_node_by_id(id)->get_data()->set_model_masina(model);
				crc->get_node_by_id(id)->get_data()->set_nume_persoana(nume);

				cout << "\nDatele inchirieri au fost modificate cu succes";

				crc->save_to_file();
			}
			else {

				cout << "\nNu exista aceasta persoana in lista";
			}
		}
		else {

			cout << "\nNu exista o inchiriere de masina cu acest ID";
		}
	}
};

