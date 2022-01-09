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

	void remove(string marca, string model) {

		Node<Masina*>* node = list->get_head();
		int index = -1;
		bool ok = 1;

		while (node != NULL && ok == 1) {

			index++;
			if (node->get_data()->get_marca() == marca && node->get_data()->get_model() == model) {

				if (index == 0) {

					list->remove_first();
				}
				else {

					list->remove(index);
				}
				ok = 0;
			}
			node = node->get_next();
		}
	}

	int Get_poz_by_marca_model(string marca, string model) {

		Node<Masina*>* node = list->get_head();
		int index = -1;

		while (node != NULL) {

			index++;
			if (node->get_data()->get_marca() == marca && node->get_data()->get_model() == model) {

				return index;
			}
			node = node->get_next();
		}
		return -1;
	}

	Node<Masina*>* Get_Node_by_index(int index) {

		Node<Masina*>* node = list->get_head();
		int poz = -1;

		while (node != NULL) {

			poz++;
			if (poz == index) {

				return node;
			}
			node = node->get_next();
		}
		return NULL;
	}

	//modifica anul masinii
	void modify(string marca, string model, int an) {

		int index = Get_poz_by_marca_model(marca, model);

		if (index != -1) {

			Node<Masina*>* node = Get_Node_by_index(index);
			node->get_data()->set_an(an);
		}

	}
};

