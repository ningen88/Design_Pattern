#pragma once
#include <string>

class Prova {

private:
	int x;
	int y;
	std::string title;
	int length;
	

public:
	Prova();
	Prova(int m_x, int m_y, std::string m_title);
	~Prova();

	int getX();
	int getY();
    std::string getTitle();

	void setX(int m_x);
	void setY(int m_y);
	void setTitle(std::string m_title);

	void print();
	std::string toString();


};
