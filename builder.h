#pragma once
#include <iostream>

// La classe Tank rappresente l'oggetto generale principale. Sono presenti gli attributi principali e le funzioni di base oltre al costruttore.
// in questo caso è anche presente una funzione, show() e toString che mostrano lo stato dell'oggetto.

class Tank {

private:
	std::string _model;
	std::string _engine;
	std::string _body;
	float _power;
	int _number;

public:
	Tank(std::string type) : _model(type) {}
	void setEngine(std::string engine) { _engine = engine; }
	void setBody(std::string body) { _body = body; }
	void setPower(float power) { _power = power; }
	void setNumber(int number) { _number = number; }

	std::string getEngine() {
		return _engine;
	}

	std::string getBody() {
		return _body;
	}

	float getPower() {
		return _power;
	}

	int getNumber() {
		return _number;
	}

	void show() {
		std::cout << "Tank model: " << _model << "\n" << "Engine: " << _engine << "\n" << "Body: " << _body << "\n" << "Power: " << _power << "\n" << "Number id: " << _number << "\n\n";
	}

	std::string toString() {
		return "Tank model: " + _model + "\nEngine: " + _engine + "\nBody: " + _body + "\nPower: " + std::to_string(_power) + "\nNumber id: " + std::to_string(_number) + "\n";
	}
};

// La classe TankBuilder presenta le funzioni astratte che dovranno essere implementate dai builder degli oggetti specifici, oltre ad un puntatore all'oggetto generale principale

class TankBuilder {

protected:
	Tank* _tank;

public:
	Tank* getTank() { return _tank; }
	virtual void getPartsDone() = 0;
	virtual void buildBody() = 0;
	virtual void buildEngine() = 0;
	virtual void assignPower() = 0;
};

// Le classi PanzerBuilder e TigerBuilder implementano le funzioni astratte presenti nella classe TankBuilder e permettono di costruire 2 tipi differenti di Tank 

class PanzerBuilder : public TankBuilder {

public:
	void getPartsDone() { _tank = new Tank("Panzer Tank"); }
	void buildBody() { _tank->setBody("Panzer Body"); }
	void buildEngine() { _tank->setEngine("Panzer Engine"); }
	void assignPower() { _tank->setPower(300); }
};

class TigerBuilder : public TankBuilder {

public:
	void getPartsDone() { _tank = new Tank("Tiger Tank"); }
	void buildBody() { _tank->setBody("Tiger Body"); }
	void buildEngine() { _tank->setEngine("Tiger Engine"); }
	void assignPower() { _tank->setPower(230); }
};

// La classe Director contiene il metodo createTank() che determina l'ordine con cui le parti dell'oggetto sono costruite.

class Director {

private:
//	TankBuilder* builder;
	int num_dir = rand()%1001;

public:
	Tank* createTank(TankBuilder *builder) {
		num_dir++;
		builder->getPartsDone();
		builder->buildBody();
		builder->buildEngine();
		builder->assignPower();
		builder->getTank()->setNumber(num_dir);
		return builder->getTank();
	}
};