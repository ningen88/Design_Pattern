#pragma once

#include <iostream>
#include <memory>
#include <unordered_map>

// Un prototype � usato quando abbiamo la necessit� di creare molti oggetti (esempio proiettili di un fucile) che variano in pochi parametri, quindi piuttosto che creare nuovi
// oggetti vengono semplicemente "clonati" a partire da un prototipo di base. Nell'esempio del proiettile ci saranno tanti proiettili simili nella fattura, che variano solo
// nella loro direzione.

// BasePrototype � il prototipo di base

class BasePrototype {

protected:                        // Nella sezione protetta vi sono i parametri che saranno ereditati
	std::string _nome;
	int _type;
	float _val;

public:
	BasePrototype(){}
	BasePrototype(std::string nome, int type): _nome(nome), _type(type){}
	virtual ~BasePrototype(){}
	virtual std::unique_ptr<BasePrototype> clone() = 0;                                            // La funzione virtuale pura clone() permette di clonare l'oggetto
	void action(float val) {                                                                       // La funzione action() setta il valore e stampa l'oggetto
		_val = val;
		std::cout << "Nome: " << _nome << "\nTipo: " << _type << "\nValore: " << _val << "\n\n";
	}
};

class I1Prototype : public BasePrototype {                                                         // La classe I1Prototype � una concretizzazione di BasePrototype

public:
	I1Prototype(std::string nome, int type): BasePrototype(nome, type){}

	std::unique_ptr<BasePrototype> clone() override {                                             // Implementiamo la funzione clone() facendoci ritornare un unique_ptr
		return std::make_unique<I1Prototype>(*this);                                              // della stessa istanza della classe I1Prototype
	}
};

class I2Prototype : public BasePrototype {                                                        // La classe I2Prototype � una concretizzazione di BasePrototype
public:
	I2Prototype(std::string nome, int type): BasePrototype(nome, type){}                          

	std::unique_ptr<BasePrototype> clone() override {                                             // Implementiamo la funzione clone() facendoci ritornare un unique_ptr
		return std::make_unique<I2Prototype>(*this);                                              // della stessa istanza della classe I2Prototyp
	} 
};

enum TypeP {
	I1, 
	I2 
};


// PrototypeFactory � il client

class PrototypeFactory {

private: 
	std::unordered_map<TypeP, std::unique_ptr<BasePrototype>, std::hash<int> > oggetti;                  // Conterr� i possibili oggetti

public:
	PrototypeFactory() {
		oggetti[I1] = std::make_unique<I1Prototype>("Oggetto1", 1);                                     // Inserisce i due possibili oggetti nella unordered_map
		oggetti[I2] = std::make_unique<I2Prototype>("Oggetto2", 2);
	}

	std::unique_ptr<BasePrototype> createObject(TypeP t) {                                             // Richiama la versione di clone() corrispondente al tipo di oggetto
		return oggetti[t]->clone();                                                                    // selezionato
	}
};