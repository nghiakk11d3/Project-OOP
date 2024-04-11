// Cau hinh giao dien Customer
#ifndef CUSTOMER_FUNCTION
#define CUSTOMER_FUNCTION

#include "TaoBang.h"
#include "customer.h"

int numProinCus[50];
int numProduct = 0;

char* inHoaChuoi(char* chuoi)
{
	for (int i = 0; chuoi[i] != '\0'; ++i)
	{
		chuoi[i] = toupper(chuoi[i]); // Chuyển ký tự thành chữ hoa
	}
	return chuoi;
}

int get_num_product(Customer list_customer[], int& num_customer, int i)
{

	int count = 0;
	for (int j = 0; j < 100; j++)
	{
		if ((list_customer[i].list_product[j].Quantity) > 0)
		{
			count++;
		}
	}

	return count;
}

void Customer::printSingleCustomer(Customer customer, int x, int y, int leny, int numProinCus)
{
	x++;
	gotoXY(x + 1, y + 1 + leny);
	cout << customer.phonenumber;
	gotoXY(x + 1 + lengCus[0], y + 1 + leny);
	cout << customer.name;
	gotoXY(x + 1 + lengCus[0] + lengCus[1], y + 1 + leny);
	cout << customer.gender;
	for (int j = 0; j < numProinCus; j++)
	{
		gotoXY(55 + 2, y + 1 + 2 * j + leny);
		cout << customer.list_product[j].ProductID;
		gotoXY(55 + 2 + lengCus1[0], y + 1 + 2 * j + leny);
		cout << customer.list_product[j].ProductName;
		gotoXY(55 + 2 + lengCus1[0] + lengCus1[1], y + 1 + 2 * j + leny);
		cout << customer.list_product[j].Size;
		gotoXY(55 + 2 + lengCus1[0] + lengCus1[1] + lengCus1[2], y + 1 + 2 * j + leny);
		cout << customer.list_product[j].Quantity;
		gotoXY(55 + 2 + lengCus1[0] + lengCus1[1] + lengCus1[2] + lengCus1[3], y + 1 + 2 * j + leny);
		cout <<"$"<<customer.list_product[j].priceProduct;
		gotoXY(55 + 2 + lengCus1[0] + lengCus1[1] + lengCus1[2] + lengCus1[3] + lengCus1[4], y + 1 + 2 * j + leny);
		cout <<"$"<< customer.list_product[j].finallyPrice;
		gotoXY(55 + 2 + lengCus1[0] + lengCus1[1] + lengCus1[2] + lengCus1[3] + lengCus1[4] + lengCus1[5], y + 1 + 2 * j + leny);
		cout << customer.purchasedate;
	}
}

void Customer::printlistCustomer(Customer list_customer[], int numberCustomer)
{
	TextColor(1);
	system("cls");
	TaoBangCustomer(numProduct, numberCustomer, numProinCus);
	SetColor(7);
	int leny = 0;
	for (int i = 0; i < numberCustomer; i++)
	{
		list_customer->printSingleCustomer(list_customer[i], 4, 4, leny, numProinCus[i]);
		leny += numProinCus[i] * 2;
	}
	statusReturn1line(numProduct - 2);

}

void Customer::enterCustomer()
{

	int x0 = x + 2;
	int x1 = 91;
	int high = 10;
	int width = 25;
	ShowCur(1);
	HopKTen(x, y, width, high, 11, 1);
	HopKTen(x + 26, y, width, high, 11, 1);
	y += 2;
	gotoXY(x0, y + 1);
	cout << "So Dien Thoai:";
	gotoXY(x1, y + 1);
	cin >> this->phonenumber;
	gotoXY(x0, y + 3);
	cout << "Ten Khach Hang:";
	gotoXY(x1, y + 3);
	cin.ignore();
	cin.getline(this->name, 30);
	gotoXY(x0, y + 5);
	cout << "Gioi Tinh:";
	gotoXY(x1, y + 5);
	cin >> (this->gender);
}

void Customer::editCustomer(Customer list_customer[], int& numberCustomer)
{
	TextColor(1);
	system("cls");
	char nameHead[][40] = { "CAP NHAT THONG TIN KHACH HANG", "Nhap So Dien Thoai Khach Hang: " };
	bool Check = false;
	char searchPhoneCustomer[11];
	ShowCur(1);
	NhieuHop(4, 1, 165, 2, t_color, b_color, nameHead, 2);
	gotoXY(6 + (165 - strlen(nameHead[1])) / 2 + strlen(nameHead[1]), 4);
	cin >> searchPhoneCustomer;
	bool kt = false;
	int Soluong = 0;
	int Index[20];
	for (int i = 0; i < numberCustomer; i++)
	{
		if (strcmp(searchPhoneCustomer, list_customer[i].phonenumber) == 0)
		{
			Index[Soluong] = i;
			Soluong++;
			kt = true;
		}
	}
	list_customer[Index[0]].enterCustomer();
	for (int i = 1; i < Soluong; i++) {
		list_customer[Index[i]] = list_customer[Index[0]];
	}
	if (kt == true) {
		char status[][40] = { "Da Cap Nhat Thanh Cong", "Nhan [ENTER] De Quay Lai" };
		statusreturnMenu(status, 45);
		ShowCur(0);
		_getch();
		return;
	}
	else {
		char status[][40] = { "Khong Tim Thay Khach Hang", "Nhan[ENTER] De Quay Lai" };
		statusreturnMenu(status, 45);
		ShowCur(0);
		_getch();
		return;
	}
}

void Customer::enterProinCus(Product list_product[], int& number, Customer list_customer[], int& numberCustomer, int SoluongThem) {
	for (int i = 0; i < SoluongThem; i++)
	{
		int x0 = x + 2;
		int x1 = 90;
		int high = 12;
		int width = 25;
		int y = 10;
		HopKTen(x, y, width, high, 11, 1);
		HopKTen(x + 26, y, width, high, 11, 1);
		y += 2;
		numProinCus[numberCustomer] += 1;
		numProduct += 1;
		gotoXY(x0, y + 1);
		cout << "Ma San Pham:";
		gotoXY(x1, y + 1);
		cin >> list_customer[numberCustomer].list_product[i].ProductID;
		int indexi = returnProduct(list_product, number, list_customer[numberCustomer].list_product[i].ProductID);
		gotoXY(x0, y + 3);
		cout << "Kich Co:";
		gotoXY(x1, y + 3);
		cin >> list_customer[numberCustomer].list_product[i].Size;
		gotoXY(x0, y + 5);
		cout << "So Luong:";
		gotoXY(x1, y + 5);
		cin >> list_customer[numberCustomer].list_product[i].Quantity;
		while (list_customer[numberCustomer].list_product[i].Quantity > list_product[indexi].Quantity)
		{
			gotoXY(63, 14 + 12 * 2);
			cout << "So Luong Vuot Qua So Luong Trong Kho. Nhap Lai";
			gotoXY(x1, y + 5); cout << "      ";
			gotoXY(x1, y + 5);
			cin >> list_customer[numberCustomer].list_product[i].Quantity;
		}
		gotoXY(63, 14 + 12 * 2);
		cout << "                                                  ";
		list_product[indexi].Quantity -= list_customer[numberCustomer].list_product[i].Quantity;
		gotoXY(x0, y + 7);
		cout << "Giam Gia(%) : ";
		gotoXY(x1, y + 7);
		cin >> list_customer[numberCustomer].list_product[i].Discount;
		list_customer[numberCustomer].list_product[i].setProductName(list_product[indexi].ProductName);
		list_customer[numberCustomer].list_product[i].setpriceProduct(list_product[indexi].priceProduct);
		list_customer[numberCustomer].list_product[i].setfinallyPrice(list_customer->get_finallycost(list_customer[numberCustomer].list_product[i].Quantity, list_customer[numberCustomer].list_product[i].priceProduct, stoi(list_customer[numberCustomer].list_product[i].Discount)));
		if (list_product[indexi].Quantity <= 0)
		{
			for (int i = indexi; i < number; i++)
			{
				list_product[i] = list_product[i + 1];
			}
			number--;
		}
		getTime(list_customer[numberCustomer].purchasedate);
	}
}

void Customer::addCustomer(Product list_product[], int& number, Customer list_customer[], int& numberCustomer)
{
	TextColor(1);
	system("cls");
	char nameHead[][40] = { "THEM THONG TIN KHACH HANG " };
	NhieuHop(4, 1, 165, 2, t_color, b_color, nameHead, 1);
	list_customer[numberCustomer].enterCustomer();
	numProinCus[numberCustomer] = 0;
	system("cls");
	char nameHead1[][40] = { "THEM SAN PHAM MUA ", "Nhap So Loai San Pham Can Mua:" };
	NhieuHop(4, 1, 165, 2, t_color, b_color, nameHead1, 2);
	int SoluongThem = 0;
	gotoXY(6 + (165 - strlen(nameHead1[1])) / 2 + strlen(nameHead1[1]), 4);
	cin >> SoluongThem;
	enterProinCus(list_product, number, list_customer, numberCustomer, SoluongThem);
}

void Customer::getnumProinCus(int numProinCus[], int& numProduct, Customer list_customer[], int numberCustomer)
{
	for (int i = 0; i < numberCustomer; i++)
	{
		numProinCus[i] = get_num_product(list_customer, numberCustomer, i);
	}
	numProduct = 0;
	for (int i = 0; i < numberCustomer; i++)
	{
		numProduct += numProinCus[i];
	}
}

void Customer::printBill(Product list_product[], int& number, Customer list_customer[], int& numberCustomer)
{
	addCustomer(list_product, number, list_customer, numberCustomer);
	ShowCur(0);

	// Hiển thị thông báo tạo hóa đơn và chờ người dùng nhấn Enter
	gotoXY(72, 14 + 12 * 2);
	cout << "Nhan [ENTER] De Tao Hoa Don";
	_getch();
	TextColor(1);
	system("cls");
	Tao1Hop(58, 5, 55, 29 + numProinCus[numberCustomer] * 2, 11, 1, "");

	// Hiển thị tiêu đề hóa đơn
	HopKTen(60, 21, 51, 10 + numProinCus[numberCustomer] * 2, 11, 1);
	char nameHead[][30] = { "INVOICE", "PIE IN THE SKY" };
	for (int i = 0; i < 2; i++)
	{
		gotoXY((58 - strlen(nameHead[i])) / 2 + 58, 7 + 2 * i);
		cout << nameHead[i];
	}

	// Hiển thị thông tin hóa đơn
	gotoXY(84, 12);
	cout << char(003) << char(003) << char(003) << char(003);
	char date[20] = "DATE: ";
	char current_time[11];
	getTime(current_time);
	strcat(date, current_time);
	gotoXY(62, 15);
	cout << "Number: 1234";
	gotoXY(62, 17);
	cout << date;
	char customer_name[30] = { "BILLED TO " };
	strcat(customer_name, inHoaChuoi(list_customer[numberCustomer].name));
	gotoXY(111 - strlen(customer_name), 15);
	cout << customer_name;
	char address[30] = { "DONG HOA, DI AN, BINH DUONG" };
	gotoXY(111 - strlen(address), 17);
	cout << address;

	// Hiển thị tiêu đề cho các cột trong hóa đơn
	char nameHead2[][30] = { "DESCRIPTION", "PRICE", "QTY", "AMOUNT" };
	int lengnameHead2[4] = { 23, 9, 6, 13 };
	int lenx = 0;
	for (int i = 0; i < 4; i++)
	{
		gotoXY(62 + lenx, 22);
		cout << nameHead2[i];
		lenx += lengnameHead2[i];
	}

	// Hiển thị danh sách sản phẩm trong hóa đơn và tính tổng tiền
	int subtotal = 0;
	for (int i = 0; i < numProinCus[numberCustomer]; i++)
	{
		gotoXY(62, 24 + 2 * i);
		cout << list_customer[numberCustomer].list_product[i].ProductName;
		gotoXY(62 + 23, 24 + 2 * i);
		cout << list_customer[numberCustomer].list_product[i].priceProduct<<" $";
		gotoXY(62 + 33, 24 + 2 * i);
		cout << list_customer[numberCustomer].list_product[i].Quantity;
		gotoXY(62 + 39, 24 + 2 * i);
		cout << list_customer[numberCustomer].list_product[i].finallyPrice << " $";
		subtotal += list_customer[numberCustomer].list_product[i].finallyPrice;
	}

	// Hiển thị tổng tiền và thông tin khác của hóa đơn
	gotoXY(61, numProinCus[numberCustomer] * 2 + 23);
	for (int i = 0; i < 50; i++)
		cout << "-";
	char nameHead3[][30] = { "SUBTOTAL", "VAT", "TOTAL" };
	for (int i = 0; i < 3; i++)
	{
		gotoXY(62, 25 + 2 * i + numProinCus[numberCustomer] * 2);
		cout << nameHead3[i];
	}
	gotoXY(95, 25 + numProinCus[numberCustomer] * 2);
	cout << subtotal << " $";
	gotoXY(95, 27 + numProinCus[numberCustomer] * 2);
	cout << "5%";
	gotoXY(95, 29 + numProinCus[numberCustomer] * 2);
	cout << int(subtotal + subtotal * 0.05) << " $";
	gotoXY(73, 33 + numProinCus[numberCustomer] * 2);
	cout << "THANKS FOR YOUR PURCHARSING";

	ShowCur(0);
	gotoXY(72, 45);
	cout << "Nhan [ENTER] De Quay Quay Lai";
	_getch();
	numberCustomer++;
	menuCustomer(list_product, number, list_customer, numberCustomer);
}

#endif