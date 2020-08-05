#pragma once

class newString {
private:
	char* data;
	int size;

public:
	newString();
	newString(const char* c);                        // CONSTRUCTOR

	newString(const newString& other);               // COPY CONSTRUCTOR
	newString(newString&& other) noexcept;           // MOVE CONSTRUCTOR
	~newString(); 
	
	void print();

};
