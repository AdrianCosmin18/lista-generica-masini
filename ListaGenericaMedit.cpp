#include "ControlMasina.h"

int main() {


	Persoana* eu = new Persoana("Nedelcu Adrian,M,1.78");
	Persoana* p = new Persoana("Nacu", "Emilian", 1.8);
	Lista<Persoana*>* pers = new Lista<Persoana*>();



	//Lista<Masina*>* l = new Lista<Masina*>();
	//l->add(new Masina("Skoda,Octavia 4,2022"));
	//l->add(new Masina("Renault,Megane,2019"));
	//l->add(new Masina("Dacia,Duster,2021"));
	//l->add(new Masina("Mercedes,Benz,2009"));
	//Masina* ford = new Masina("Ford,Puma,2020");
	//l->add(ford);
	//Masina* fluence = new Masina("Renault,Fluence,2014");
	//l->add(fluence);

	//Node<Masina*>* n1 = new Node<Masina*>();
	//n1->set_data(fluence);

	//Node<Masina*>* n2 = new Node<Masina*>();
	//n2->set_data(ford);


	ControlMasina* cm = new ControlMasina();

	cm->add_masina(new Masina("Audi,A5,2020"));
	cm->traverse();
}

