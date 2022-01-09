#include"Rent_Car.h"
class ControlRent_Car
{
private:

	Lista<Rent_Car*>* list;

public:

	void load() {

		ifstream f("rent_cars.txt");
		while (!f.eof()) {

			string m;
			getline(f, m);
			list->add(new Rent_Car(m));
		}
	}

	ControlRent_Car() {

		list = new Lista<Rent_Car*>();
		load();
	}

	void traverse() {

		Node<Rent_Car*>* node = list->get_head();
		while (node != NULL) {

			cout << *(node->get_data())<<endl;
			node = node->get_next();
		}
	}

	void add(Rent_Car* rc) {

		list->add(rc);
	}

	int get_next_available_id() {

		return list->get_last()->get_data()->get_id() + 1;
	}

	int get_index_by_id(int id) {

		for (int i = 0; i < list->size(); i++) {

			if (list->get_data_by_index(i)->get_id() == id) {

				return i;
			}
		}
		return -1;
	}

	void remove(int id) {

		int index = get_index_by_id(id);

		if (index != -1) {

			if (index == 0) {

				list->remove_first();
			}
			else {

				list->remove(index);
			}
			
		}
	}

	void modify(int id, string nume, string marca, string model) {

		int index = get_index_by_id(id);

		if (index != -1) {

			list->get_data_by_index(index)->set_marca_masina(marca);
			list->get_data_by_index(index)->set_model_masina(model);
			list->get_data_by_index(index)->set_nume_persoana(nume);
		}
	}
};
