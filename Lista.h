#include"iList.h"

template<typename T>
class Lista
{
private:
	Node<T>* head = NULL;

public:

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

	//probleme
	int indexOf(string fst, string sec) {

		Node<T>* node = head;
		int poz = -1;

		while (node != NULL) {

			poz++;
			//if(node->get_data()->)
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


};

