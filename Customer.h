#ifndef CUSTOMER
#define CUSTOMER

#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include "product.h"
#include "tranfer_string.h"

// class Customer
class Customer : public Product
{
private:
    char phonenumber[11];
    char namecustomer[30];
    char gender[10];
    char purchasedate[11];

public:
    Product list_product[100];

    void set_phonenumber(char* field_customer)
    {
        strcpy(this->phonenumber, field_customer);
    }
    void set_customername(char* field_customer)
    {
        strcpy(this->namecustomer, field_customer);
    }
    void set_gender(char* field_customer)
    {
        strcpy(this->gender, field_customer);
    }
    void set_purchaseddate(char* field_customer)
    {
        strcpy(this->purchasedate, field_customer);
    }
    void set_productid(Customer list_customer[], char* field_customer, int& num_customer, int& num_product)
    {
        strcpy(list_customer[num_customer].list_product[num_product].ProductID, field_customer);
    }
    void set_productname(Customer list_customer[], char* field_customer, int& num_customer, int& num_product)
    {
        strcpy(list_customer[num_customer].list_product[num_product].ProductName, field_customer);
    }
    void set_size(Customer list_customer[], char* field_customer, int& num_customer, int& num_product)
    {
        strcpy(list_customer[num_customer].list_product[num_product].Size, field_customer);
    }
    void set_price(Customer list_customer[], char* field_customer, int& num_customer, int& num_product)
    {
        int price = tranfer_string_customer(field_customer);
        list_customer[num_customer].list_product[num_product].Price.priceProduct = price;
    }
    void set_quantity(Customer list_customer[], char* field_customer, int& num_customer, int& num_product)
    {
        int quantity = tranfer_string_customer(field_customer);
        list_customer[num_customer].list_product[num_product].Quantity = quantity;
    }
    void set_discount(Customer list_customer[], char* field_customer, int& num_customer, int& num_product) //
    {
        strcpy(list_customer[num_customer].list_product[num_product].Price.Discount, field_customer);
    }
    void set_finallycost(Customer list_customer[], char* field_customer, int& num_customer, int& num_product)
    {
        int total_price = tranfer_string_customer(field_customer);
        list_customer[num_customer].list_product[num_product].Price.finallyPrice = total_price;
    }
    int get_finallycost(int Quantity, int priceProduct, float discount)
    {
        int finallyPrice = Quantity * priceProduct - (Quantity * priceProduct * (discount / 100));
        return finallyPrice;
    }

    char* get_name()
    {
        return this->namecustomer;
    }

    char* get_phone()
    {
        return this->phonenumber;
    }

    char* get_gender()
    {
        return this->gender;
    }

    char* get_purchased_date()
    {
        return this->purchasedate;
    }

    void enterCustomer();
    void editCustomer(Customer list_customer[], int& numberCustomer);
    void printlistCustomer(Customer list_customer[], int numberCustomer);
    void printSingleCustomer(Customer customer, int x, int y, int leny, int numProinCus);
    void menuStore(Product list_product[], int& number, Customer list_customer[], int& numberCustomer);
    void menuCustomer(Product list_product[], int& number, Customer list_customer[], int& numberCustomer);
    void addCustomer(Product list_product[], int& number, Customer list_customer[], int& numberCustomer);
    void getnumProinCus(int numProinCus[], int& numProduct, Customer list_customer[], int numberCustomer);
    void printBill(Product list_product[], int& number, Customer list_customer[], int& numberCustomer);
};

#endif