#pragma once

//testing di una FACTORY

#include <iostream>
#include "toy.h"

class Factory {

public:
	static Toy* createToy(int type) {
		Toy* t = NULL;
		switch (type) {
		       case 1: {
				   t = new Car;
				   break;
        	   }
			   case 2: {
				   t = new Bike;
				   break;
			   }
			   case 3: {
				   t = new Plane;
				   break;
			   }
			   default: {
				   std::cout << "Invalid type\n";
			   }
		}

		t->prepareParts();
		t->combineParts();
		t->assembleParts();
		t->applyLabel();

		return t;
	}
};