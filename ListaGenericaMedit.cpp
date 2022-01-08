#include "Lista.h"

int main() {


	Persoana* eu = new Persoana("Nedelcu Adrian,M,1.78");
	Persoana* p = new Persoana("Nacu", "Emilian", 1.8);


	//Node<Persoana> x;

	Lista<Masina*>* l = new Lista<Masina*>();
	l->add(new Masina("Skoda,Octavia 4,2022"));
	l->add(new Masina("Renault,Megane,2019"));
	l->add(new Masina("Dacia,Duster,2021"));
	l->add(new Masina("Mercedes,Benz,2009"));

	Masina megane("Renault,Megane,2019");
	Masina* ford = new Masina("Ford,Puma,2020");
	l->add(ford);

	cout<<l->remove(&megane);
	//l->traverse();


	
		
		



	//cout << eu->operator==(*p);



}

