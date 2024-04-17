#include "price.h"
#include "product.h"
#include "customer.h"
#include "Employee.h"
#include "ProductFunc.h"
#include "CustomerFunc.h"
#include "tranfer_string.h"
#include "handle_file.h"
using namespace std;

void Customer::menuStore(Product list_product[], int& number, Customer list_customer[], int& numberCustomer, Employee list_employee[], int& numberEmployee)
{
    ShowCur(0);
    TextColor(1);
    system("cls");
    string nameStore = "PIE IN THE SKY";
    char nameHead[][40] = { "Quan Ly San Pham", "Quan Ly Khach Hang", "Quan Ly Nhan Vien", "THOAT" };
    int Choice = MenuDong(nameStore, nameHead, 4);

    switch (Choice)
    {
    case 0:
        list_product->menuProduct(list_product, number);
        menuStore(list_product, number, list_customer, numberCustomer, list_employee, numberEmployee);
        break;
    case 1:
        list_customer->menuCustomer(list_product, number, list_customer, numberCustomer);
        menuStore(list_product, number, list_customer, numberCustomer, list_employee, numberEmployee);
        break;
    case 2:
        list_employee->menuEmployee(list_employee, numberEmployee);
        menuStore(list_product, number, list_customer, numberCustomer, list_employee, numberEmployee);
        break;

    case 3:
        return;
        break;
    }
}

void Product::menuProduct(Product list_product[], int& number)
{
    ShowCur(0);
    TextColor(1);
    system("cls");
    string nameOBJ = "QUAN LY SAN PHAM";
    char nameHead[][40] = { "Danh Sach San Pham", "Them San Pham Vao Kho",
                           "Sua Thong Tin San Pham", "Tim San Pham",
                           "Xoa San Pham", "Sap Xep San Pham", "Quay Lai" };
    int Soluong = sizeof(nameHead) / sizeof(nameHead[0]);
    int Choice = MenuDong(nameOBJ, nameHead, Soluong);

    switch (Choice)
    {
    case 1:
    {
        addProduct(list_product, number);
        menuProduct(list_product, number);
        break;
    }
    case 0:
    {
        printListProduct(list_product, number, 3, 0);
        break;
    }
    case 2:
    {
        editProduct(list_product, number);
        break;
    }
    case 3:
    {
        findProduct(list_product, number);
        break;
    }
    case 4:
    {
        deleteProduct(list_product, number);
        break;
    }
    case 5:
    {
        sortProduct(list_product, number);
        break;
    }
    case 6:
        return;
    }
    // ghi lại file product
    write_data_product(list_product, number);
}

void Employee::menuEmployee(Employee list_employee[], int& numberEmployee)
{
    TextColor(1);
    system("cls");
    ShowCur(0);
    string nameOBJ = "QUAN LY NHAN VIEN";
    char nameHead[][40] = { "Danh Sach Nhan Vien", "Cap Nhat Thong Tin Nhan Vien", "Them Nhan Vien", "Xoa Nhan Vien", "Quay Lai" };
    int Choice = MenuDong(nameOBJ, nameHead, 5);

    switch (Choice)
    {
    case 0:
        printListEmp(list_employee, numberEmployee);
        break;
    case 1:
        editEmployee(list_employee, numberEmployee);

        break;
    case 2:
        addEmployee(list_employee, numberEmployee);
        break;
    case 3:
        deleteEmployee(list_employee, numberEmployee);
        break;
    case 4:
        return;
        break;
    }
    // ghi lại file employee
    write_data_employee(list_employee, numberEmployee);
}

void Customer::menuCustomer(Product list_product[], int& number, Customer list_customer[], int& numberCustomer)
{
    TextColor(1);
    system("cls");
    ShowCur(0);
    getnumProinCus(numProinCus, numProduct, list_customer, numberCustomer);
    string nameOBJ = "QUAN LY KHACH HANG";
    char nameHead[][40] = { "Danh Sach Khach Hang", "Cap Nhat Thong Tin Khach Hang", "Ban Hang", "Quay Lai" };
    int Choice = MenuDong(nameOBJ, nameHead, 4);
    switch (Choice)
    {
    case 2:
    {
        printBill(list_product, number, list_customer, numberCustomer);
        break;
    }
    case 0:
    {
        printlistCustomer(list_customer, numberCustomer);
        menuCustomer(list_product, number, list_customer, numberCustomer);
        break;
    }
    case 1:
    {
        editCustomer(list_customer, numberCustomer);
        menuCustomer(list_product, number, list_customer, numberCustomer);
    }
    case 3:
        return;
        break;
    }
    // ghi lại file customer
    write_data_customer(list_customer, numberCustomer, numProinCus);
}

int main()
{
    Product list_product[100];
    Customer list_customer[100];
    Employee list_employee[100];

    /*Hàm đọc file employee.csv*/
    FILE* file_employee = fopen("C:/Users/nghia/OneDrive - VNU-HCMUS/OOP/ProjectMain1/ProjectMain1/employee.csv", "r");
    int numberEmployee = read_data_employee(list_employee, file_employee);

    /* Hàm đọc file product.csv*/
    FILE* file_pointer;
    file_pointer = fopen("C:/Users/nghia/OneDrive - VNU-HCMUS/OOP/ProjectMain1/ProjectMain1/product.csv", "r");
    int number = read_data_product(list_product, file_pointer);

    /*Hàm đọc file customer.csv*/
    FILE* file_pointer_customer;
    file_pointer_customer = fopen("C:/Users/nghia/OneDrive - VNU-HCMUS/OOP/ProjectMain1/ProjectMain1/customer.csv", "r");
    int numberCustomer = read_data_customer(list_customer, file_pointer_customer);

    list_customer->getnumProinCus(numProinCus, numProduct, list_customer, numberCustomer);
    ShowCur(0);
    list_customer->menuStore(list_product, number, list_customer, numberCustomer, list_employee, numberEmployee);
    TextColor(1);
    system("cls");
    char status[] = { "DA THOAT! NHAN PHIM BAT KI DE DONG CUA SO CONSOLE" };
    gotoXY((172 - strlen(status)) / 2, 10);
    cout << status;
    _getch();
}