#include"ControlMasina.h"

class ControlPersoana
{
private:

	Lista<Persoana*>* list;

public:

	ControlPersoana() {

		list = new Lista<Persoana*>();
		load();
	}

	void load() {

		ifstream f("persoane.txt");
		while (!f.eof()) {

			string m;
			getline(f, m);

			if (m != "") {

				list->add(new Persoana(m));
			}
		}
	}

	void traverse() {

		Node<Persoana*>* node = list->get_head();
		for (int i = 0; i < list->size(); i++) {

			cout << *(list->get_data_by_index(i))<<endl;
		}
	}

	void add_persoana(Persoana* p) {

		list->add(p);
	}

	int get_index_by_nume_si_gen(string nume, string gen) {

		Node<Persoana*>* node = list->get_head();
		int poz = -1;

		while (node != NULL) {

			poz++;
			if (node->get_data()->get_nume() == nume && node->get_data()->get_gen() == gen) {

				return poz;
			}
			node = node->get_next();
		}
		return -1;
	}

	Node<Persoana*>* get_node_by_index(int index) {

		Node<Persoana*>* node = list->get_head();
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

	void remove(string nume, string gen) {

		int index = get_index_by_nume_si_gen(nume, gen);

		if (index != -1) {

			list->remove(index);
		}
	}
	
	//modificam inaltimea
	void modify(string nume, string gen, double h) {


		int index = get_index_by_nume_si_gen(nume, gen);

		if (index != -1) {

			Node<Persoana*>* node = get_node_by_index(index);

			node->get_data()->set_h(h);
		}
	}
};

