#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include "TaoBang.h"
#include "price.h"
#include "product.h"
#include "customer.h"
#include "ProductFunc.h"
#include "CustomerFunc.h"
#include "tranfer_string.h"

using namespace std;
#define KEY_NONE -1
// đọc dữ liệu từ file customer
int read_data_customer(Customer list_customer[], FILE* file_customer)
{
	if (file_customer == NULL)
	{
		printf("%s\n", "Input file error");
	}

	// declare indexs of list_customer
	int num_customer = -1;
	int num_product = -1;
	// read one line
	char line[150];

	// define field
	char* field_customer[11] = { 0 };
	int file_count;

	char* string_customer;

	fgets(line, 150, file_customer);

	while (fgets(line, 150, file_customer) != NULL)
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
			list_customer[num_customer].set_phonenumber(field_customer[0]);
			list_customer[num_customer].set_customername(field_customer[1]);
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

// đọc dữ liệu từ file product
int read_data_product(Product list_product[], FILE* file_pointer)
{
	if (file_pointer == NULL)
	{
		printf("%s\n", "Input file error");
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

	fgets(line, 150, file_pointer);

	while (fgets(line, 150, file_pointer) != NULL)
	{
		field_count = 0;

		string_token = strtok(line, ",");
		while (string_token != NULL)
		{
			field[field_count] = string_token;
			string_token = strtok(NULL, ",");
			field_count++;
		}

		if (field_count == 11)
		{
			strcpy(list_product[num_product].Gender, field[0]);
			strcpy(list_product[num_product].Type, field[1]);
			strcpy(list_product[num_product].ProductID, field[2]);
			strcpy(list_product[num_product].ProductName, field[3]);
			strcpy(list_product[num_product].Size, field[4]);
			strcpy(list_product[num_product].Material, field[5]);
			strcpy(char_Price, field[6]);
			list_product[num_product].Price.priceProduct = tranfer_string(char_Price);
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

// ghi lại file customer
void write_data_customer(Customer list_customer[], int& number_customer,int numProinCus[])
{
	fstream write_file_customer;
	write_file_customer.open("C:/Users/nghia/OneDrive - VNU-HCMUS/OOP/ProjectMain/ProjectMain/customer.csv");

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
		

		write_file_customer << list_customer[i].get_phone() << ","
			<< list_customer[i].get_name() << ","
			<< list_customer[i].get_gender() << ","
			<< list_customer[i].list_product[0].ProductID << ","
			<< list_customer[i].list_product[0].ProductName << ","
			<< list_customer[i].list_product[0].Size << ","
			<< list_customer[i].list_product[0].Quantity << ","
			<< list_customer[i].list_product[0].Price.priceProduct << ","
			<< list_customer[i].list_product[0].Price.Discount << ","
			<< list_customer[i].list_product[0].Price.finallyPrice << ","
			<< list_customer[i].get_purchased_date() << "\n";

		// in ra danh sách sản phẩm
		for (int j = 1; j < numProinCus[i]; j++)
		{
			write_file_customer	<< ",,," << list_customer[i].list_product[j].ProductID << ","
				<< list_customer[i].list_product[j].ProductName << ","
				<< list_customer[i].list_product[j].Size << ","
				<< list_customer[i].list_product[j].Quantity << ","
				<< list_customer[i].list_product[j].Price.priceProduct << ","
				<< list_customer[i].list_product[j].Price.Discount << ","
				<< list_customer[i].list_product[j].Price.finallyPrice << ","
				<< list_customer[i].get_purchased_date() << "\n";
		}
	}
	write_file_customer.close();
}

// ghi lại file product
void write_data_product(Product list_product[], int& num_list_product)
{
	fstream write_file;
	write_file.open("C:/Users/nghia/OneDrive - VNU-HCMUS/OOP/ProjectMain/ProjectMain/product.csv");

	// kiem tra file
	if (write_file.is_open())
	{
		cout << "Mo file thanh cong";
	}
	else
	{
		cout << "Khong tim thay file!!!";
	}

	write_file << "Gender,"
		<< "Type,"
		<< "ProductID,"
		<< "ProductName"
		<< "Size,"
		<< "Material,"
		<< "Price,"
		<< "Quanlity,"
		<< "Description,"
		<< "Addeddate,"
		<< "Instock,"
		<< "\n";

	for (int i = 0; i < num_list_product; i++)
	{
		write_file << list_product[i].Gender << ",";
		write_file << list_product[i].Type << ",";
		write_file << list_product[i].ProductID << ",";
		write_file << list_product[i].ProductName << ",";
		write_file << list_product[i].Size << ",";
		write_file << list_product[i].Material << ",";
		write_file << list_product[i].Price.priceProduct << ",";
		write_file << list_product[i].Quantity << ",";
		write_file << list_product[i].Description << ",";
		write_file << list_product[i].Addeddate << ",";
		write_file << list_product[i].Instock << "\n";
	}

	write_file.close();
}

void Product::menuProduct(Product list_product[], int& number){
	write_data_product(list_product, number);
	ShowCur(0);	
	thanh_sang(0, -1, 172, 16 + number * 2, 1, " ");
	string nameOBJ = "QUAN LY SAN PHAM";
	char nameHead[][40] = { "Danh Sach San Pham", "Them San Pham Vao Kho", "Sua Thong Tin San Pham", "Tim San Pham", "Xoa San Pham", "Sap Xep San Pham", "Quay Lai" };
	int Soluong  = sizeof(nameHead) / sizeof(nameHead[0]);
	int Choice = MenuDong(nameOBJ, nameHead, Soluong);
	switch (Choice) {
	case 1:{	
		addProduct(list_product, number);
		break;
	}
	case 0:{		
		printListProduct(list_product, number, 3, 0);		
		break;
	}
	case 2:	{
		editProduct(list_product, number);		
		break;
	}
	case 3:	{
		findProduct(list_product, number);		
		break;
	}
	case 4: {
		deleteProduct(list_product, number);	
		break;
	}
	case 5:	{
		sortProduct(list_product, number);		
		break;
	}
	case 6:
		return;
	}
}

void Customer::menuStore(Product list_product[], int& number, Customer list_customer[], int& numberCustomer)
{

	ShowCur(0);
	thanh_sang(-1, -1, 172, 16 + number * 2, 1, "");
	int width = 50;
	int x = 61;
	int y = 10;
	string nameStore = "PIE IN THE SKY";
	char nameHead[][40] = { "Quan Ly San Pham", "Quan Ly Khach Hang", "THOAT" };
	int Soluong = 3;
	vemenu(nameStore, nameHead, x, y, width, Soluong);
	int xp = x;
	int yp = y; // tọa độ ánh sang
	int xcu = xp;
	int ycu = yp;
	bool kt = false;
	while (1)
	{
		int Choice = (ycu - y) / 2;
		int Choice1 = (yp - y) / 2;
		if (kt == true)
		{
			gotoXY(xcu, ycu);
			thanh_sang(xcu, ycu, width, high, b_color, nameHead[Choice]);
			xcu = xp;
			ycu = yp;
			thanh_sang(xp, yp, width, high, b_color_sang, nameHead[Choice1]);
			kt = false;
		}
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				kt = true;
				c = _getch();
				if (c == 72)
				{
					if (yp != y)
						yp -= 2;
					else
					{
						yp = y + high * (Soluong - 1);
					}
				}
				else if (c == 80)
				{
					if (yp != y + high * (Soluong - 1))
						yp += 2;
					else
					{
						yp = y;
					}
				}
			}
			if (c == 13)
			{
				switch (Choice1)
				{
				case 0:
					menuProduct(list_product, number);
					menuStore(list_product, number, list_customer, numberCustomer);
					break;
				case 1:
					menuCustomer(list_product, number, list_customer, numberCustomer);
					break;
				case 2:
					return;
				}
			}
		}
	}
}

void Customer::menuCustomer(Product list_product[], int& number, Customer list_customer[], int& numberCustomer)
{
	ShowCur(0);
	getnumProinCus(numProinCus, numProduct, list_customer, numberCustomer);
	write_data_customer(list_customer, numberCustomer,numProinCus);
	thanh_sang(0, -1, 172, 16 + numProduct * 2, 1, "");
	string nameOBJ = "QUAN LY KHACH HANG";
	char nameHead[][40] = { "Danh Sach Khach Hang", "Cap Nhat Thong Tin Khach Hang", "Ban Hang", "Quay Lai" };
	int Soluong = 4;
	vemenu(nameOBJ, nameHead, x, y, width, Soluong);
	int xp = x;
	int yp = y;
	int xcu = xp;
	int ycu = yp;
	bool kt = false;
	while (1)
	{
		int Choice = (ycu - y) / 2;
		int Choice1 = (yp - y) / 2;
		if (kt == true)
		{
			gotoXY(xcu, ycu);
			thanh_sang(xcu, ycu, width, high, b_color, nameHead[Choice]);
			xcu = xp;
			ycu = yp;
			thanh_sang(xp, yp, width, high, b_color_sang, nameHead[Choice1]);
			kt = false;
		}
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				kt = true;
				c = _getch();
				if (c == 72)
				{
					if (yp != y)
						yp -= 2;
					else
					{
						yp = y + high * (Soluong - 1);
					}
				}
				else if (c == 80)
				{
					if (yp != y + high * (Soluong - 1))
						yp += 2;
					else
					{
						yp = y;
					}
				}
			}
			if (c == 13)
			{
				switch (Choice1)
				{
				case 2:
				{
					thanh_sang(-1, -1, 120, 30, 1, "");
					list_customer->printBill(list_product, number, list_customer, numberCustomer);
					statusReturn1line(numProduct - 1);
					numberCustomer++;
					menuCustomer(list_product, number, list_customer, numberCustomer);
					break;
				}
				case 0:
				{
					thanh_sang(-1, -1, 120, 30, 1, "");
					list_customer->printlistCustomer(list_customer, numberCustomer);
					statusReturn1line(numProduct - 2);
					menuCustomer(list_product, number, list_customer, numberCustomer);
					break;
				}
				case 1:
				{
					thanh_sang(-1, -1, 120, 30, 1, "");
					list_customer->editCustomer(list_customer, numberCustomer);
					_getch();
					menuCustomer(list_product, number, list_customer, numberCustomer);
				}
				case 3:
					menuStore(list_product, number, list_customer, numberCustomer);
					break;
				}
			}
		}
	}
}

int main()
{
	Product list_product[60];
	Customer list_customer[60];
	FILE* file_pointer;
	file_pointer = fopen("C:/Users/nghia/OneDrive - VNU-HCMUS/OOP/ProjectMian/ProjectMain/product.csv", "r");
	int number = read_data_product(list_product, file_pointer);
	FILE* file_pointer_customer;
	file_pointer_customer = fopen("C:/Users/nghia/OneDrive - VNU-HCMUS/OOP/ProjectMain/ProjectMain/customer.csv", "r");
	int numberCustomer = read_data_customer(list_customer, file_pointer_customer);
	list_customer->getnumProinCus(numProinCus, numProduct, list_customer, numberCustomer);
	ShowCur(0);
	list_customer->menuStore(list_product, number, list_customer, numberCustomer);
	/*thanh_sang(0, 0, 172, 50, 1, " ");
	char status[] = { "DA THOAT! NHAN PHIM BAT KI DE DONG CUA SO CONSOLE" };
	gotoXY((172 - strlen(status)) / 2, 10);
	cout << status;*/
	_getch();
}