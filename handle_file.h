#ifndef __FILE_HANDLE__
#define __FILE_HANDLE__

#include <iostream>
#include "customer.h"
#include "product.h"
#include <fstream>

using namespace std;
/*------------------------------ HÀM XÓA DỮ LIỆU TRONG FILE--------------------------------*/
void clearFile(const char* filePath)
{
    FILE* f = fopen(filePath, "w");
    if (f == NULL)
    {
        cout << ("Can not open file %s to erase data.\n", filePath);
        return;
    }
    fclose(f);
}
/*----------------------------------- HÀM ĐỌC DỮ LIỆU TỪ FILE ---------------------------*/
/*1.--------------------------- -----HÀM ĐỌC DỮ LIỆU TỪ FILE CUSTOMER--------------------*/
int read_data_customer(Customer list_customer[], FILE* file_customer)
{
    if (file_customer == NULL)
    {
        cout << "Input file error" << endl;
    }

    // declare indexs of list_customer
    int num_customer = -1;
    int num_product = -1;
    // read one line
    char line[160];

    // define field
    char* field_customer[11] = { 0 };
    int file_count;

    char* string_customer;

    fgets(line, 160, file_customer);

    while (fgets(line, 160, file_customer) != NULL)
    {
        file_count = 0;

        string_customer = strtok(line, ",");
        while (string_customer != NULL)
        {
            field_customer[file_count] = string_customer;
            string_customer = strtok(NULL, ",");
            file_count++;
        }

        if (file_count == 8)
        {
            /*Thong tin san pham*/
            num_product++;
            list_customer[num_customer].set_productid(list_customer, field_customer[0], num_customer, num_product);
            list_customer[num_customer].set_productname(list_customer, field_customer[1], num_customer, num_product);
            list_customer[num_customer].set_size(list_customer, field_customer[2], num_customer, num_product);
            list_customer[num_customer].set_quantity(list_customer, field_customer[3], num_customer, num_product);
            list_customer[num_customer].set_price(list_customer, field_customer[4], num_customer, num_product);
            list_customer[num_customer].set_discount(list_customer, field_customer[5], num_customer, num_product);
            list_customer[num_customer].set_finallycost(list_customer, field_customer[6], num_customer, num_product);
            list_customer[num_customer].set_purchaseddate(field_customer[7]);
        }
        else if (file_count == 11)
        {
            num_customer++;
            num_product = 0;
            /*Thong tin khach hang*/
            list_customer[num_customer].Person::setphoneNumber(field_customer[0]);
            list_customer[num_customer].Person::setName(field_customer[1]);
            list_customer[num_customer].set_gender(field_customer[2]);

            /*Thong tin san pham*/
            list_customer[num_customer].set_productid(list_customer, field_customer[3], num_customer, num_product);
            list_customer[num_customer].set_productname(list_customer, field_customer[4], num_customer, num_product);
            list_customer[num_customer].set_size(list_customer, field_customer[5], num_customer, num_product);
            list_customer[num_customer].set_quantity(list_customer, field_customer[6], num_customer, num_product);
            list_customer[num_customer].set_price(list_customer, field_customer[7], num_customer, num_product);
            list_customer[num_customer].set_discount(list_customer, field_customer[8], num_customer, num_product);
            list_customer[num_customer].set_finallycost(list_customer, field_customer[9], num_customer, num_product);
            list_customer[num_customer].set_purchaseddate(field_customer[10]);
        }
    }
    num_customer++;
    return num_customer;

    fclose(file_customer); // close the file pointer
}

/*2.-------------------------------- HÀM ĐỌC DỮ LIỆU TỪ FILE PRODUCT----------------------*/
int read_data_product(Product list_product[], FILE* file_pointer)
{
    if (file_pointer == NULL)
    {
        cout << "Input file error" << endl;
    }

    // declare indexs of list_product
    int num_product = 0;
    // read one line
    char line[125];

    // define field
    char* field[11] = { 0 };
    int field_count;

    char char_Price[10] = { 0 };
    char char_Quantity[10] = { 0 };

    char* string_token;

    fgets(line, 125, file_pointer);

    while (fgets(line, 125, file_pointer) != NULL)
    {
        field_count = 0;

        string_token = strtok(line, ",");
        while (string_token != NULL)
        {
            field[field_count] = string_token;
            string_token = strtok(NULL, ",");
            field_count++;
        }

        if (field_count == 10)
        {
            strcpy(list_product[num_product].Gender, field[0]);
            strcpy(list_product[num_product].Type, field[1]);
            strcpy(list_product[num_product].ProductID, field[2]);
            strcpy(list_product[num_product].ProductName, field[3]);
            strcpy(list_product[num_product].Size, field[4]);
            strcpy(list_product[num_product].Material, field[5]);
            strcpy(char_Price, field[6]);
            list_product[num_product].setpriceProduct(tranfer_string(char_Price));
            strcpy(char_Quantity, field[7]);
            list_product[num_product].Quantity = tranfer_string(char_Quantity);
            strcpy(list_product[num_product].Description, field[8]);
            strcpy(list_product[num_product].Addeddate, field[9]);

            num_product = num_product + 1;
        }
    }
    return num_product;
    fclose(file_pointer);
}

/*3.---------------------------------HÀM ĐỌC DỮ LIỆU TỪ FILE EMPLOYEE--------------------*/
int read_data_employee(Employee list_employee[], FILE* file)
{
    // Kiểm tra lỗi mở file
    if (file == NULL)
    {
        cout << "Loi mo file " << endl;
    }

    // khởi tạo biến đếm số lượng nhân viên
    char line[100];
    int field_count;
    int num_employee = 0;
    char* field[6] = { 0 };
    char* string_token;

    fgets(line, 100, file);
    while (fgets(line, 100, file) != NULL)
    {
        field_count = 0;

        string_token = strtok(line, ",");
        while (string_token != NULL)
        {
            field[field_count] = string_token;
            string_token = strtok(NULL, ",");
            field_count++;
        }

        if (field_count == 6)
        {
            (list_employee[num_employee].setID(field[0]));
            (list_employee[num_employee].setName(field[1]));
            (list_employee[num_employee].setphoneNumber(field[2]));
            list_employee[num_employee].setMail(field[3]);
            list_employee[num_employee].setShift(field[4]);
            list_employee[num_employee].setDay(field[5]);
            num_employee++;
        }
    }

    // Trả về nội dung file
    return num_employee;

    // Đóng file
    fclose(file);
}

/*-------------------------------- HÀM GHI DỮ LIỆU RA FILE---------------------------------*/
/*1. ----------------------------- HÀM GHI DỮ LIỆU RA FILE CUSTOMER------------------------*/
void write_data_customer(Customer list_customer[], int& number_customer, int numProinCus[])
{
    fstream write_file_customer;
    write_file_customer.open("C:/Users/nghia/OneDrive - VNU-HCMUS/OOP/ProjectMain1/ProjectMain1/customercopy.csv", ios::app);

    // kiem tra file
    if (write_file_customer.is_open())
    {
        cout << "Mo file thanh cong";
    }
    else
    {
        cout << "Khong tim thay file!!!";
    }

    write_file_customer << "Customer Phone Number1,"
        << "Customer Name,"
        << "Gender,"
        << "Purchased Product ID,"
        << "Purchased Product Name,"
        << "Size,"
        << "Quantity,"
        << "Price 1 Product,"
        << "Discount,"
        << "Finally Price,"
        << "Purchased Date1\n";

    for (int i = 0; i < number_customer; i++) //
    {

        write_file_customer << list_customer[i].Person::getphoneNumber() << ","
            << list_customer[i].Person::getName() << ","
            << list_customer[i].get_gender() << ","
            << list_customer[i].list_product[0].ProductID << ","
            << list_customer[i].list_product[0].ProductName << ","
            << list_customer[i].list_product[0].Size << ","
            << list_customer[i].list_product[0].Quantity << ","
            << list_customer[i].list_product[0].priceProduct << ","
            << list_customer[i].list_product[0].Discount << ","
            << list_customer[i].list_product[0].finallyPrice << ","
            << list_customer[i].get_purchased_date() << "\n";

        // in ra danh sách sản phẩm
        for (int j = 1; j < numProinCus[i]; j++)
        {
            write_file_customer << ",,," << list_customer[i].list_product[j].ProductID << ","
                << list_customer[i].list_product[j].ProductName << ","
                << list_customer[i].list_product[j].Size << ","
                << list_customer[i].list_product[j].Quantity << ","
                << list_customer[i].list_product[j].priceProduct << ","
                << list_customer[i].list_product[j].Discount << ","
                << list_customer[i].list_product[j].finallyPrice << ","
                << list_customer[i].get_purchased_date() << "\n";
        }
    }
    write_file_customer.close();
}

/*2. ----------------------------- HÀM GHI DỮ LIỆU RA FILE PRODUCT------------------------*/
void write_data_product(Product list_product[], int& num_list_product)
{
    ofstream write_file;
    clearFile("C:/Users/nghia/OneDrive - VNU-HCMUS/OOP/ProjectMain1/ProjectMain1/product.csv");

    write_file.open("C:/Users/nghia/OneDrive - VNU-HCMUS/OOP/ProjectMain1/ProjectMain1/product.csv");

    write_file << "Gender1," << "Type," << "ProductID," << "ProductName," << "Size,"
        << "Material," << "Price," << "Quanlity," << "Description," << "Addeddate" << "\n";

    for (int i = 0; i < num_list_product; i++)
    {
        write_file << list_product[i].Gender << ",";
        write_file << list_product[i].Type << ",";
        write_file << list_product[i].ProductID << ",";
        write_file << list_product[i].ProductName << ",";
        write_file << list_product[i].Size << ",";
        write_file << list_product[i].Material << ",";
        write_file << list_product[i].priceProduct << ",";
        write_file << list_product[i].Quantity << ",";
        write_file << list_product[i].Description << ",";
        write_file << list_product[i].Addeddate << "\n";
    }
    write_file.close();
}

/*3. ---------------------------- - HÀM GHI DỮ LIỆU RA FILE EMPLOYEE---------------------- */
void write_data_employee(Employee list_employee[], int num_list_employee)
{
    ofstream write_file;

    clearFile("C:/Users/nghia/OneDrive - VNU-HCMUS/OOP/ProjectMain1/ProjectMain1/employee.csv");

    write_file.open("C:/Users/nghia/OneDrive - VNU-HCMUS/OOP/ProjectMain1/ProjectMain1/employee.csv");

    write_file << "IdUser1," << "NameUser," << "PhoneUser," << "MailUser," << "Shift," << "Day\n";

    // Ghi dữ liệu của từng nhân viên vào file
    for (int i = 0; i < num_list_employee; i++)
    {
        write_file << list_employee[i].getID() << ","
            << list_employee[i].getName() << ","
            << list_employee[i].getphoneNumber() << ","
            << list_employee[i].getMail() << ","
            << list_employee[i].getShift() << ","
            << list_employee[i].getDay() << endl;
    }

    // Đóng file
    write_file.close();
}

#endif