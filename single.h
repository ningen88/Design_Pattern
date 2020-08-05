#pragma once

//testing di un SINGLETON

class Single {

private:
	int data = 2;

	Single(){}               // il costrutture è privato, quindi non accessibile dall'esterno

	int i_funzione() {      // i_funzione contiene l'implementazione della funzione, anch'essa privata

		return data*rand()%10 + 2;
	}

public:
	Single(const Single&) = delete;                 // copia non concessa!
	Single& operator=(const Single& s) = delete;   //? assegnamento non concesso

	static Single& get() {                     //la funzione get ritorna la singola instanza
		static Single instance;
		return instance;
	}

	static int funzione() {                   // attraverso get() richiama l'instanza, attraverso i_funzione richiama la funzione richiesta
		return get().i_funzione();
	}

};