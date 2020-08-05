#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

//testing observer

class Subject {

private:
	int _data;
	std::vector<class Observer*> _observerList;

public:

	int getData() {
		return _data;
	}

	void setData(int data) {
		_data = data;
		notify();
	}

	void notify();

	void attach(Observer *obs) {
		_observerList.push_back(obs);
	}

	void detach(Observer *obs) {
		_observerList.erase(std::remove(_observerList.begin(), _observerList.end(), obs), _observerList.end());
	}
};




////////////////////////////////////////////////////////////////////////////////////////////////

class Observer {

private:
	Subject* _sub;
	std::string message;
	bool state;

protected:
	Subject* getSub() {
		return _sub;
	}

public:
	Observer(Subject* sub, std::string msg, bool s) : _sub(sub), message(msg), state(s) {
		sub->attach(this);
	}

	std::string getMessage() {
		return message;
	}

	bool getState() {
		return state;
	}

	void setMessage(std::string msg) {
		message = msg;
	}

	void setState(bool s) {
		state = s;
	}

	virtual void update() = 0;
};

void Subject::notify() {
	for (int i = 0; i < _observerList.size(); i++) {
		_observerList[i]->update();
	}
}



class IObserver1 : public Observer {

public:
	IObserver1(Subject* sub, std::string msg, bool s) : Observer(sub, msg, s) {}

	void update() {
		int val = getSub()->getData();
		if (val == 0) {
			setMessage("Observer_1");
			setState(true);
			std::cout << getMessage() << "è attivo\n";
		}
	}
};

class IObserver2 : public Observer {

public:
	IObserver2(Subject* sub, std::string msg, bool s) : Observer(sub, msg, s) {}

	void update() {
		int val = getSub()->getData();
		if (val < 0) {
			setMessage("Observer_2");
			setState(true);
			std::cout << getMessage() << "è attivo\n";
		}
	}
};

class IObserver3 : public Observer {

public:
	IObserver3(Subject* sub, std::string msg, bool s) : Observer(sub, msg, s) {}

	void update() {
		int val = getSub()->getData();
		if (val > 0) {
			setMessage("Observer_3");
			setState(true);
			std::cout << getMessage() << "è attivo\n";
		}
	}
};    


