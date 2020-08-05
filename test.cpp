#include "test.h"
#include <iostream>

Prova::Prova(): x(0), y(0), title("no title"){}


Prova::~Prova(){}

Prova::Prova(int m_x, int m_y, std::string m_title): x(m_x), y(m_y), title(m_title){}

int Prova::getX(){
	return x;
}
int Prova::getY(){
	return y;
}
std::string Prova::getTitle(){
	return title;
}

void Prova::setX(int m_x){
	x = m_x;
}

void Prova::setY(int m_y){
	y = m_y;
}

void Prova::setTitle(std::string m_title) {
	title = m_title;
}

void Prova::print() {
	std::cout << x << ", " << y << ", " << title << "\n";
}

std::string Prova::toString() {
	
	return std::to_string(x) + ", " + std::to_string(y) + ", " + title + "\n";
}