#include"ControlRent_Car.h"

int main(){


	ControlRent_Car* crc = new ControlRent_Car();

	crc->add(new Rent_Car(crc->get_next_available_id(), "Nedelcu Adrian", "Mercedes", "Benz"));
	crc->traverse();

}

