#include"ControlPersoana.h"

int main(){


	ControlPersoana* cp = new ControlPersoana();

	cp->add_persoana(new Persoana("Anne,F,1.7"));
	cp->modify("Anne", "F", 1.61);
	cp->traverse();
}

