#pragma once

class Toy {

protected:
	std::string name;
	float price;

public:
	virtual void prepareParts() = 0;
	virtual void combineParts() = 0;
	virtual void assembleParts() = 0;
	virtual void applyLabel() = 0;
	virtual void showProduct() = 0;
};

class Car : public Toy {

public:
	void prepareParts() {
		std::cout << "Preparing CAR parts\n";
	}
	void assembleParts() {
		std::cout << "Assembling CAR parts\n";
	}
	void combineParts() {
		std::cout << "Combining CAR parts\n";
	}
	void applyLabel() {
		std::cout << "Applying Label...\n";
		name = "Car";
		price = 15;
	}
	void showProduct() {
		std::cout << "Name: " << name << "\n" << "Price: " << price << "\n";
	}
};

class Bike : public Toy {

public:
	void prepareParts() {
		std::cout << "Preparing BIKE parts\n";
	}
	void assembleParts() {
		std::cout << "Assembling BIKE parts\n";
	}
	void combineParts() {
		std::cout << "Combining BIKE parts\n";
	}
	void applyLabel() {
		std::cout << "Applying Label...\n";
		name = "Bike";
		price = 100;
	}
	void showProduct() {
		std::cout << "Name: " << name << "\n" << "Price: " << price << "\n";
	}

};

class Plane : public Toy {

public:
	void prepareParts() {
		std::cout << "Preparing PLANE parts\n";
	}
	void assembleParts() {
		std::cout << "Assembling PLANE parts\n";
	}
	void combineParts() {
		std::cout << "Combining PLANE parts\n";
	}
	void applyLabel() {
		std::cout << "Applying Label...\n";
		name = "Plane";
		price = 30;
	}
	void showProduct() {
		std::cout << "Name: " << name << "\n" << "Price: " << price << "\n";
	}

};