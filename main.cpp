#include "iostream"
#include "test.h"
#include "time.h"
#include "single.h"
#include "newString.h"
#include "factory.h"
#include "observer.h"
#include "prototype.h"
#include "builder.h"
#include <array>
#include <algorithm>
#include <functional>
#include <optional>
#include <variant>


void funzione_lambda(const std::array<int,5>& values, const std::function<void(int&)>& func) {
	for (int value : values) {
		func(value);
	}
}

//optional è usato quando si hanno valori di ritorno opzionali, cioè che possono essere presenti o meno
//nell'esempio la funzione ritorna la stringa "Not zero!" se value non è zero e non ritorna nulla se il valore è 0

std::optional<std::string> funzione_optional(int value) {
	if (value == 0) {
		return {};
	}
	else return "Not zero!";
}

//variant permette ad una funzione di poter ritornare uno fra due valori di tipo differente.
//l'esempio riprende quello della funzione_optional solo che questa volta facciamo ritornare un ErrorCode se value è 0 o se eccede il limite di 100

enum class ErrorCode {
	EQUALZERO = -1, EXCEED = 1
};

std::variant<std::string, ErrorCode> funzione_variant(int value) {
	if (value == 0) {
		return ErrorCode::EQUALZERO;
	}
	if (value > 100) {
		return ErrorCode::EXCEED;
	}
	else return "Value accepted!";
}



int main() {

	std::cout << "Test new feature C++ \n \n";


	// -------test unique pointer-------------
	

		std::array <std::unique_ptr<Prova>, 10> unique_prova;
		{
			
			Timer time;
			for (int i = 0; i < unique_prova.size(); i++) {
				unique_prova[i] = std::make_unique<Prova>(i, i, "unique");
				std::cout << "x: " << unique_prova[i]->getX() << " y: " << unique_prova[i]->getY() << " title: " << unique_prova[i]->getTitle() << "\n";
			}

			std::cout << " \nthe for loop of unique pointer ";
		}

		std::unique_ptr<Prova> p_u = std::make_unique<Prova>(5, 5, "unique");

		


		std::cout << "\nA Single unique pointer: " << p_u->toString();
			
		std::cout << "---------------------------------------------------------------- \n \n";


	// ---------------------------------------



    // -------test share pointer-------------

		{
			std::array<std::shared_ptr<Prova>, 10> shared_prova;
			{
				Timer time;
				for (int i = 0; i < shared_prova.size(); i++) {
					shared_prova[i] = std::make_shared<Prova>(i, i, "shared");
					std::cout << "x: " << shared_prova[i]->getX() << " y: " << shared_prova[i]->getY() << " title: " << shared_prova[i]->getTitle() << "\n";
				}

				std::cout << "\nthe for loop of shared pointer ";

				shared_prova[0]->setX(100);
				shared_prova[0]->setY(100);
				shared_prova[0]->setTitle("edited");
			}
			std::shared_ptr<Prova> copy_shared = shared_prova[0];
			std::shared_ptr<Prova> cc_shared = copy_shared;
			std::cout << "original shared: " << shared_prova[0]->getX() << ", " << shared_prova[0]->getY() << ", " << shared_prova[0]->getTitle() << "\n";
			std::cout << "\nUse_count shared pointer(original): " << shared_prova[0].use_count() << "\n";
			std::cout << "copy shared: " << copy_shared->getX() << ", " << copy_shared->getY() << ", " << copy_shared->getTitle() << "\n";
			std::cout << "\nUse_count shared pointer(copied): " << copy_shared.use_count() << "\n";

		}

		
		
		
			std::shared_ptr<Prova> p_s = std::make_shared<Prova>(2, 2, "shared");
			

			std::cout << "\nA Single shared pointer: " << p_s->toString();


		std::cout << "---------------------------------------------------------------- \n \n";
		

	// ---------------------------------------



	// -------test lambda-------------

		std::array<int, 5> l_array = {1, 7, 3, 4, 5};
		bool start = true;
		int max = 0;
		auto lambda = [start, &max](int& value) {
			
			if (start == true) {
				value++;
				if (value > max) {
					max = value;
				}
				

				std::cout << "Value: " << value << "\n";
			}
			else std::cout << "canot print!\n";
		
		};
		funzione_lambda(l_array, lambda);
		std::cout << "MAX: " << max << "\n";

	// ---------------------------------------



    // -------test optionals-------------

		std::optional<std::string> prova_optional = funzione_optional(0);
		std::string p = prova_optional.value_or("Zero!");
		std::cout << p << "\n";

		if (prova_optional) {
			std::cout << *prova_optional << "\n";
		}



	// ---------------------------------------



	// -------test variants-------------

		auto prova_variant = funzione_variant(800);

		if (auto value = std::get_if<std::string>(&prova_variant)) {

			std::string& s = *value;
			std::cout << s << "\n";
		}
		if (auto value = std::get_if<ErrorCode>(&prova_variant)) {
			auto r = (int)*value;
			
			std::cout << "Error, invalid value! Code error: " << r << "\n";
		}



	// ---------------------------------------

   // -------test faster string (std::string_view)-------------

		std::string test_string = "Hello people!";      // modo classico richiede 1 allocazione nel heap

		
		std::string_view new_string(test_string.c_str(), 6);   // utilizza std::string_view a partire dalla stringa creata in precedenza.
															   // non richiede utleriori allocazioni a parte quella iniziale dovuta a test_string
		                                                       
		std::cout << new_string << "\n";



		const char* test_string2 = "Hello people!";  // per ridurre a 0 allocazioni

		std::string_view new_string2(test_string2 + 7, 6);
		
		std::cout << new_string2 << "\n";





   // ---------------------------------------------------------

  // ---------------test singleton-----------------------------

		std::cout << "Singleton attivo\n\n";

		int test_single = Single::funzione();

		int test_single2 = Single::funzione();
		int test_single3 = Single::funzione();
		int test_single4 = Single::funzione();
		int test_single5 = Single::funzione();

		std::cout << "Test Singleton 1: " << test_single << "\n";
		std::cout << "Test Singleton 2: " << test_single2 << "\n";
		std::cout << "Test Singleton 3: " << test_single3 << "\n";
		std::cout << "Test Singleton 4: " << test_single4 << "\n";
		std::cout << "Test Singleton 5: " << test_single5 << "\n";




  // ----------------------------------------------------------
  



  // -----test copy constructor and move constractor-----------

		newString s_prova("PROVA!");

		newString copy = s_prova;                                   // copia
		newString moved = std::move(s_prova);                       // spostiamo la risorsa da s_prova a moved, di conseguenza s_prova non esiste più

		s_prova.print();                                            // stampa riga nulla!
		copy.print();
		moved.print();

		s_prova.print();



  // ----------------------------------------------------------


  // ---------------test prototype-----------------------------

		std::cout << "Prototype attivo\n\n";

		PrototypeFactory factory;

		auto oggetto = factory.createObject(I1);
		oggetto->action(50);

		oggetto = factory.createObject(I2);
		oggetto->action(100);

   // ----------------------------------------------------------

   // ---------------test builder-----------------------------

		std::cout << "Builder attivo\n\n";

		Director dir;
		PanzerBuilder pb;
		TigerBuilder tb;

		Tank* panzer = dir.createTank(&pb);
		Tank* tiger = dir.createTank(&tb);

		Tank* tiger2 = dir.createTank(&tb);

		panzer->show();
		tiger->show();
		tiger2->setPower(400);
		tiger2->show();

		std::cout << panzer->toString();

		delete panzer;
		delete tiger;
		

  // ----------------------------------------------------------
 
  // ---------------test factory-------------------------------

		std::cout << "Factory attivo\n\n";
		int type;
		while (1) {
			std::cout << "Enter type or zero for exit...";
			std::cin >> type;
			if (!type) break;
			Toy* t = Factory::createToy(type);
			if (t) {
				t->showProduct();
				delete t;
			}
		}
		std::cout << "Exit...\n";

		 

  // ----------------------------------------------------------

  // ---------------test observer-------------------------------
		std::cout << "Observer attivo\n\n";

		Subject *sub = new Subject();

		IObserver1 one(sub, "prova1", false);
		IObserver2 two(sub, "prova2", false);
		IObserver3 trhee(sub, "prova3", false);

		char pressedButton;
		bool stop = false;

		std::cout << "observer attivo\n";
		std::cout << "Inserire l, r, c oppure b per uscire\n";

		while (!stop) {
			std::cin >> pressedButton;
			switch (pressedButton) {
			       case 108:{
					   sub->setData(-1);
					   break;
				   }
				   case 99: {
					   sub->setData(0);
					   break;
				   }
				   case 114: {
					   sub->setData(1);
					   break;
				   }
				   case 98: {
					   stop = true;
					   break;
				   }
				   default: {
					   std::cout << "non atteso\n";
					   break;
				   }
			 
			}
		}
	

  // ----------------------------------------------------------
		return 0;
}