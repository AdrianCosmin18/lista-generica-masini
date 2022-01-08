#include"iList.h"

template<typename T>
class Lista: public IList<T>
{
private:
	Node<T>* head = NULL;

public:
	Node<T>* get_head() { return head; }

	void add_start(T t) {

		if (head == NULL) {

			head = new Node<T>();
			head -> data = t;
			head -> next = NULL;
		}
		else {

			Node<T>* node = new Node<T>();

			node->data = t;
			node->next = head;
			head = node;
		}
	}

	void traverse() {

		Node<T>* aux = head;

		while (aux != NULL) {

			cout << *(aux->data)<<endl;

			aux = aux->next;
		}
	}

	Node<T>* get_last() {

		Node<T>* node = head;
		Node<T>* aux = node;

		while (node != NULL) {

			aux = node;
			node = node->get_next();
		}

		return aux;
	}

	void add(T t) {

		
		if (head == NULL) {

			Node<T>* node = new Node<T>();
			node->set_data(t);
			node->set_next(NULL);

			head = node;
		}
		else {

			
			Node<T>* node = new Node<T>();
			node->set_data(t);

			Node<T>* last_node = new Node<T>();
			last_node = get_last();
			last_node->set_next(node);
		}
	}

	int indexOf(T t) {

		Node<T>* node = head;
		int poz = -1;

		while (node != NULL) {

			poz++;
			if (node->get_data()->operator==(*t)){

				return poz;
			}

			node = node->get_next();
		}


	}

	Node<T>* get_node_by_poz(int p) {

		Node<T>* node = head;
		int poz = -1;

		while (node != NULL) {

			poz++;
			if (poz == p) {

				return node;
			}
			node = node->get_next();
		}
		return NULL;
	}

	void remove_first() {

		Node<T>* aux = head;
		this->head = this->head->get_next();
		delete aux;
	}

	void remove(int index) {

		Node<T>* node = get_node_by_poz(index);
		Node<T>* priv = get_node_by_poz(index - 1);

		priv->set_next(node->get_next());

	}

	void remove(T t){

		int poz = indexOf(t);
		Node<T>* node = get_node_by_poz(poz);
		Node<T>* priv = get_node_by_poz(poz - 1);

		priv->set_next(node->get_next());
	}

	bool contains(T t) {

		Node<T>* node = head;

		while (node != NULL) {

			if (node->get_data()->operator==(*t)) {

				return true;
			}
			node = node->get_next();
		}
		return false;
	}

	bool isEmpty() {

		if (get_last() == NULL) {

			return true;
		}
		return false;
	}

	int size() {

		if (!isEmpty()) {

			int count = 0;
			Node<T>* node = head;
			while (node != NULL) {

				count++;
				node = node->get_next();
			}
			return count;
		}
		return 0;
	}

	T get_data_by_index(int index) {

		Node<T>* node = get_node_by_poz(index);
		if (node != NULL) {

			return node->get_data();
		}
		return NULL;
	}

	void replace(T t, int index) {

		Node<T>* node = get_node_by_poz(index);
		node->set_data(t);
	}

	void swap(Node<T>* n1, Node<T>* n2) {

		int index1 = indexOf(n1->get_data());
		int index2 = indexOf(n2->get_data());

		replace(n1->get_data(), index1);
		replace(n2->get_data(), index2);
	}

	void sort() {

		int flag = 0;

		do {

			flag = 0;

			for (int i = 0; i < size() - 1; i++) {

				if (get_data_by_index(i + 1)->operator< (*get_data_by_index(i))) {

					T aux = get_data_by_index(i);
					replace(get_data_by_index(i + 1), i);
					replace(aux, i + 1);

					flag = 1;
				}
			}
		} while (flag == 1);
	}
};

