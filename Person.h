#ifndef PERSON
#define PERSON
#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "product.h";
class Person :public Product {
private:
	char Name[25];
	char phoneNumber[11];
public:
	Product* list_product = new Product[100];
	char* getName() {
		return Name;
	}
	char* getphoneNumber() {
		return phoneNumber;
	}
	void setName(const char* name) {
		strcpy(this->Name, name);
	}
	void setphoneNumber(const char* phone) {
		strcpy(this->phoneNumber, phone);
	}

};
#endif