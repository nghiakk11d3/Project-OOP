#ifndef PRODUCT
#define PRODUCT

#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include "price.h"
#include <cstring>
// class Product
class Product
{
public:
    char Gender[10];
    char Type[15];
    char ProductID[10];
    char ProductName[20];
    char Size[3];
    char Material[10];
    int Quantity;
    char Description[4];
    char Addeddate[11];
    int Instock;
    Price Price; // class lồng class
    // friend class Customer;

    void setProductName(const char* des)
    {
        strncpy(this->ProductName, des, sizeof(this->ProductName) - 1);
        this->ProductName[sizeof(this->ProductName) - 1] = '\0';
    }
    void setAddeddate(const char* date)
    {
        strncpy(this->Addeddate, date, sizeof(this->Addeddate) - 1);
        this->Addeddate[sizeof(this->Addeddate) - 1] = '\0';
    }
    void setSize(const char* size)
    {
        strncpy(this->Size, size, sizeof(this->Size) - 1);
        this->Size[sizeof(this->Size) - 1] = '\0';
    }
    void setMaterial(const char* mat)
    {
        strncpy(this->Material, mat, sizeof(this->Material) - 1);
        this->Material[sizeof(this->Material) - 1] = '\0';
    }

    void addProduct(Product list_product[], int& number);

    void editProduct(Product list_product[], int number);

    void findProduct(Product list_product[], int number);

    void deleteProduct(Product list_product[], int& number);

    // cac ham sap xep san pham
    void sortProduct(Product list_product[], int number);
    void sortProductByID(Product list_product[], int number);
    void sortProductByName(Product list_product[], int number);
    void sortProductByInstock(Product list_product[], int number);

    void menuProduct(Product list_product[], int& number);
    void statusReturn1line(int numProduct);

    void enterProduct(Product list_product[], int& number, int choice);
    int returnProduct(Product list_product[], int& number, char searchID[]);

    // cac ham in san pham
    void printListProduct(Product list_product[], int number, int x, int y);
    void print1Product(Product product, int x, int y, int i);
};

#endif