#include"Lista.h"
#include<fstream>

class ControlMasina
{
private:

	Lista<Masina*>* list;

public:

	ControlMasina() {

		list = new Lista<Masina*>();
		load();
	}

	void load() {

		ifstream f("masini.txt");
		while (!f.eof()) {

			string m;
			getline(f, m);

			if (m != "") {

				list->add(new Masina(m));
			}
		}
	}

	void traverse() {

		Node<Masina*>* node = list->get_head();

		for (int i = 0; i < list->size(); i++) {

			cout << *(list->get_data_by_index(i))<<endl;
		}
	}

	void add_masina(Masina* m) {

		list->add(m);
	}
};

