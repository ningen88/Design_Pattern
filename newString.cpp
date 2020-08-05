#include "newString.h"
#include <iostream>

newString::newString() = default;

newString::newString(const char* c) {                      // CONSTRUCTOR
	std::cout << "created!\n";
	size = strlen(c);
	data = new char[size];
	memcpy(data, c, size);
}

newString::newString(const newString& other) {            // COPY CONSTRUCTOR
	std::cout << "copied\n";
	size = other.size;
	data = new char[size];
	memcpy(data, other.data, size);
}

newString::newString(newString&& other) noexcept {                // MOVE CONSTRUCTOR
	std::cout << "moved!\n";
	size = other.size;
	data = other.data;

	other.size = 0;
	other.data = nullptr;
}



newString::~newString() {
	delete data;
}

void newString::print() {
	if (data == nullptr) {
		printf("La stringa non esiste!\n");
	}

	for (int i = 0; i < size; i++) {
		printf("%c", data[i]);
	}
	printf("\n");
}