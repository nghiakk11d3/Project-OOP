
#ifndef PRODUCT_FUNCTION
#define PRODUCT_FUNCTION
#include "TaoBang.h"
#include "product.h"

void Product::enterProduct(Product list_product[], int& number, int choice){
	int x0 = x + 2;
	int x1 = 90;
	int high = 22;
	int width = 25;
	ShowCur(1);
	HopKTen(x, y, width, high, 11, 1);
	HopKTen(x + 26, y, width, high, 11, 1);
	y += 2;
	gotoXY(x0, y + 1);
	cout << "Ma San Pham:";
	gotoXY(x1, y + 1);
	cin >> this->ProductID;
	if (choice == 0)
	{
		for (int i = 0; i < number; i++)
		{
			if (strcmp(this->ProductID, list_product[i].ProductID) == 0)
			{
				gotoXY(x0, y + 3);
				cout << "So Luong:";
				gotoXY(x1, y + 3);
				cin >> (this->Quantity);
				list_product[i].Quantity += this->Quantity;
				number--;
				goto end1;
			}
		}
	}
	gotoXY(x0, y + 3);
	cout << "Ten San Pham:";
	gotoXY(x1, y + 3);
	cin.ignore();
	cin.getline(this->ProductName, 20);
	gotoXY(x0, y + 5);
	cout << "Gia:";
	gotoXY(x1, y + 5);
	cin >> (this->Price.priceProduct);
	gotoXY(x0, y + 7);
	cout << "Kich Co:";
	gotoXY(x1, y + 7);
	cin >> (this->Size);
	gotoXY(x0, y + 9);
	cout << "So Luong:";
	gotoXY(x1, y + 9);
	cin >> (this->Quantity);
	gotoXY(x0, y + 11);
	cin.ignore();
	cout << "Chat Lieu: ";
	gotoXY(x1, y + 11);
	cin >> (this->Material);
	gotoXY(x0, y + 13);
	cin.ignore();
	cout << "Gioi Tinh:";
	gotoXY(x1, y + 13);
	cin >> (this->Gender);
	gotoXY(x0, y + 15);
	cin.ignore();
	cout << "Loai:";
	gotoXY(x1, y + 15);
	cin >> (this->Type);
	gotoXY(x0, y + 17);
	cout << "Mo Ta:";
	gotoXY(x1, y + 17);
	cin >> (this->Description);
	cin.ignore();
	ShowCur(0);
end1:
	getTime(this->Addeddate);
};

void Product::addProduct(Product list_product[], int& number)
{
	thanh_sang(-1, -1, 172, 12 + number * 2, 1, "");
	char nameHead[][40] = { "THEM SAN PHAM ", "Nhap So Luong San Pham Can Them:" };
	NhieuHop(4, 0, 165, 2, t_color, b_color, nameHead, 2);
	ShowCur(1);
	int SoluongThem = 0;
	gotoXY(6 + (165 - strlen(nameHead[1])) / 2 + strlen(nameHead[1]), 3);
	cin >> SoluongThem;
	for (int i = 0; i < SoluongThem; i++)
	{
		list_product[number].enterProduct(list_product, number, 0);
		number++;
	}
	char status[][40] = { "Da Them Thanh Cong", "Nhan [ENTER] De Quay Lai" };
	statusreturnMenu(status, number - 1);
	_getch();
	menuProduct(list_product, number);
}

void Product::print1Product(Product product, int x, int y, int i)
{
	gotoXY(x + 1, y + 2 * i + 1);
	cout << product.ProductID;
	gotoXY(x + 1 + lengPro[0], y + 2 * i + 1);
	cout << product.ProductName;
	gotoXY(x + 1 + lengPro[1] + lengPro[0], y + 2 * i + 1);
	cout << product.Gender;
	gotoXY(x + 1 + lengPro[0] + lengPro[1] + lengPro[2], y + 2 * i + 1);
	cout << product.Size;
	gotoXY(x + 1 + lengPro[0] + lengPro[1] + lengPro[2] + lengPro[3], y + 2 * i + 1);
	cout << product.Type;
	gotoXY(x + 1 + lengPro[0] + lengPro[1] + lengPro[2] + lengPro[3] + lengPro[4], y + 2 * i + 1);
	cout << product.Addeddate;
	gotoXY(x + 1 + lengPro[0] + lengPro[1] + lengPro[2] + lengPro[3] + lengPro[4] + lengPro[5], y + 2 * i + 1);
	cout << product.Material;
	gotoXY(x + 1 + lengPro[0] + lengPro[1] + lengPro[2] + lengPro[3] + lengPro[4] + lengPro[5] + lengPro[6], y + 2 * i + 1);
	cout << product.Price.priceProduct;
	gotoXY(x + 1 + lengPro[0] + lengPro[1] + lengPro[2] + lengPro[3] + lengPro[4] + lengPro[5] + lengPro[6] + lengPro[7], y + 2 * i + 1);
	cout << product.Description;
	gotoXY(x + 1 + lengPro[0] + lengPro[1] + lengPro[2] + lengPro[3] + lengPro[4] + lengPro[5] + lengPro[6] + lengPro[7] + lengPro[8], y + 2 * i + 1);
	cout << product.Quantity;
}

void Product::printListProduct(Product list_product[], int number, int x, int y)
{
	thanh_sang(-1, -1, 120, 30, 1, "");
	TaoBangHeader(number, x, y, "DANH SACH SAN PHAM", lengPro, Header, 10);
	SetColor(7);
	y += 4;
	for (int i = 0; i < number; i++)
	{
		print1Product(list_product[i], x, y, i);
	}
	statusReturn1line(number - 2);
	menuProduct(list_product, number);
}

void Product::editProduct(Product list_product[], int number)
{
	char nameHead[][40] = { "Sua Thong Tin San Pham ", "Nhap Ma San Pham: " };
	char searchID[10];
	bool KT = false;
	thanh_sang(-1, -1, 172, 12 + number * 2, 1, "");
	taomenuYeuCau(nameHead, searchID);
	for (int i = 0; i < number; i++)
	{
		if (strcmp(searchID, list_product[i].ProductID) == 0)
		{
			list_product[i].enterProduct(list_product, number, 1);
			KT = true;
		}
	}
	if (KT == true)
	{
		char status[][40] = { "Da Sua Thanh Cong", "Nhan [ENTER] De Quay Lai" };
		statusreturnMenu(status, number);
		_getch();
		menuProduct(list_product, number);
	}
	else
	{
		char status[][40] = { "Khong Tim Thay Ma", "Nhan [ENTER] De Quay Lai" };
		statusreturnMenu(status, number);
		_getch();
		menuProduct(list_product, number);
	}
}

void Product::findProduct(Product list_product[], int number)
{
	int tmp = number;
	int arrIndex[50];
	for (int i = 0; i < number; i++)
	{
		arrIndex[i] = i;
	}
loop:
	thanh_sang(0, 0, 172, number * 2 + 16, 1, "");
	char nameHead[][40] = { "Tim Kiem San Pham", "Nhap Tu Khoa Can Tim: " };
	char searchKey[20];
	taomenuYeuCau(nameHead, searchKey);
	int Soluong = 0;
	for (int i = 0; i < number; i++)
	{
		if (strstr(list_product[arrIndex[i]].ProductName, searchKey) != nullptr || strstr(list_product[arrIndex[i]].ProductID, searchKey) != nullptr || strstr(list_product[arrIndex[i]].Addeddate, searchKey) != nullptr || strstr(list_product[arrIndex[i]].Description, searchKey) != nullptr || strstr(list_product[arrIndex[i]].Gender, searchKey) != nullptr || strstr(list_product[arrIndex[i]].Material, searchKey) != nullptr || strstr(list_product[arrIndex[i]].Size, searchKey) != nullptr || strstr(list_product[arrIndex[i]].Type, searchKey) != nullptr || atoi(searchKey) == list_product[arrIndex[i]].Price.priceProduct)
		{
			arrIndex[Soluong] = i;
			Soluong++;
		}
	}
	number = Soluong;
	if (Soluong > 0)
	{
		TaoBangHeader(Soluong, 4, 6, "San Pham Tim Duoc", lengPro, Header, 10);
		SetColor(7);
		for (int i = 0; i < Soluong; i++)
		{
			print1Product(list_product[arrIndex[i]], 4, 10 + 2 * i, 0);
		}
		char status[][40] = { "Nhan [SPACE] De Tiep Tuc", "Nhan [ENTER] De Quay Lai" };
		statusreturnMenu(status, number + 3);
		while (1)
		{
			if (_kbhit())
			{
				char c = _getch();
				if (c == 32)
					goto loop;
				else
					number = tmp;
				menuProduct(list_product, number);
			}
		}
	}
	else
	{
		char status[][40] = { "Khong Tim Thay", "Nhan [ENTER] De Quay Lai" };
		statusreturnMenu(status, number);
		number = tmp;
		_getch();
		menuProduct(list_product, number);
	}
}

void Product::deleteProduct(Product list_product[], int& number){

	int sl = 3;
	thanh_sang(0, -1, 172, 14 + number * 2, 1, "");
	string nameOBJ = "XOA SAN PHAM";
	gotoXY(77, 10);
	cout << "Ban Muon Xoa Theo ?";
	char nameHead[][40] = { "1. Ma San Pham", "2. Ten San Pham", "Quay Lai" };
	int Choice = MenuDong(nameOBJ, nameHead, 3);
				switch (Choice)
				{
				case 0:
				{
					char searchID[10];
					char nameHead[][40] = { "Xoa San Pham Theo ID ", "Nhap ID: " };
					thanh_sang(0, 0, 172, 12 + number * 2, 1, "");
					taomenuYeuCau(nameHead, searchID);
					bool KT = false;
					for (int i = 0; i < number; i++)
					{
						if (strcmp(searchID, list_product[i].ProductID) == 0)
						{
							TaoBangHeader(1, 4, 6, "San Phan Can Xoa", lengPro, Header, 10);
							SetColor(7);
							print1Product(list_product[i], 4, 10, 0); // nhớ cộng 4 vô
							char status[][40] = { "Xac Nhan Xoa Nhan [ENTER]", "De Huy Nhan [SPACE]" };
							statusreturnMenu(status, 4);
							KT = true;
							while (1)
							{
								if (_kbhit())
								{
									char cd = _getch();
									if (cd == 13)
									{
										for (int j = i; j < number - 1; j++)
										{
											list_product[j] = list_product[j + 1];
										}
										number--;
										thanh_sang(30, 12, 80, 35, 1, "");
										char status[][40] = { "DA XOA THANH CONG!!!", "Nhan [ENTER] De Quay Lai" };
										statusreturnMenu(status, 4);
										_getch();
										deleteProduct(list_product, number);
									}
									if (cd == 32)
									{
										thanh_sang(30, 12, 80, 35, 1, "");
										char status[][40] = { "DA HUY THANH CONG!!!", "Nhan [ENTER] De Quay Lai" };
										statusreturnMenu(status, 4);
										_getch();
										deleteProduct(list_product, number);
									}
								}
							}
						}
					}
					if (KT == false)
					{
						char status[][40] = { "KHONG CO MA CAN XOA", "Nhan [ENTER] De Quay Lai" };
						statusreturnMenu(status, 0);
						_getch();
						deleteProduct(list_product, number);
					}
				}
				break;
				case 1: {
					char searchName[20];
					thanh_sang(0, 0, 172, 16 + number * 2, 1, "");
					char nameHead[][40] = { "Xoa San Pham Theo Ten ", "Nhap Ten San Pham: " };
					taomenuYeuCau(nameHead, searchName);
					int Soluong = 0;
					int arrIndex[50]; // Mảng chứa thứ tự các phần tử sản phẩm cần xóa
					for (int i = 0; i < number; i++)
					{
						if (strcmp(list_product[i].ProductName, searchName) == 0)
						{
							arrIndex[Soluong] = i;
							Soluong++;
						}
					}
					if (Soluong > 0)
					{
						TaoBangHeader(Soluong, 4, 6, "San Phan Can Xoa", lengPro, Header, 10);
						SetColor(7);
						for (int i = 0; i < Soluong; i++)
						{
							print1Product(list_product[arrIndex[i]], 4, 10 + 2 * i, 0);
						}
						char status[][40] = { "Xac Nhan Xoa Nhan [ENTER]", "De Huy Nhan [SPACE]" };
						statusreturnMenu(status, Soluong + 3);
						while (1) {
							if (_kbhit()) {
								char cd = _getch();
								if (cd == 13) {
									for (int i = 0; i < number; i++){									
										if (strcmp(list_product[i].ProductName, searchName) == 0){										
											for (int j = i; j < number - 1; j++){											
												list_product[j] = list_product[j + 1];
											}
											number--;
											i--;
										}
									}
									thanh_sang(1, 10 + 2 * Soluong, 118, 6, 1, "");
									char status[][40] = { "DA XOA THANH CONG!!!", "Nhan [ENTER] De Quay Lai" };
									statusreturnMenu(status, Soluong + 3);
									_getch();
									deleteProduct(list_product, number);
									break;
								}
								if (cd == 32)
								{
									thanh_sang(1, 10 + 2 * Soluong, 118, 6, 1, "");
									char status[][40] = { "DA HUY THANH CONG!!!", "Nhan [ENTER] De Quay Lai" };
									statusreturnMenu(status, Soluong + 3);
									_getch();
									deleteProduct(list_product, number);
									break; 
								}
							}
						}
					}
					else {
						thanh_sang(1, 10, 118, 6, 1, "");
						char status[][40] = { "KHONG CO TEN CAN XOA", "Nhan [ENTER] De Quay Lai" };
						statusreturnMenu(status, 0);
						_getch();
						deleteProduct(list_product, number);
					}
					break;
				}

				case 2: {
					menuProduct(list_product, number);
					break;
				}
				}
			}			


void Product::sortProduct(Product list_product[], int number)
{
Start:
	int sl = 4;
	thanh_sang(0, 0, 172, 16 + number * 2, 1, "");
	string nameOBJ = "SAP XEP DANH SACH";
	char nameHead[][40] = { "Sap Xep Theo Ma San Pham", "Sap Xep Theo Ten San Pham", "Sap Xep Theo So Luong", "Quay Lai" };
	vemenu(nameOBJ, nameHead, x, y, width, sl);
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
						yp = y + high * (sl - 1);
					}
				}
				else if (c == 80)
				{
					if (yp != y + high * (sl - 1))
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
					sortProductByID(list_product, number);
					goto Start;
					break;
				case 1:
					sortProductByName(list_product, number);
					goto Start;
					break;
				case 2:
					sortProductByInstock(list_product, number);
					goto Start;
					break;
				case 3:
					return;
					break;
				}
			}
		}
	}
}

void Product::sortProductByID(Product list_product[], int number)
{
Start:
	int sl = 3;
	thanh_sang(0, 0, 172, 16 + number * 2, 1, "");
	string nameOBJ = "SAP XEP THEO MA SAN PHAM";
	char nameHead[][40] = { "Giam Dan", "Tang Dan", "Quay Lai" };
	vemenu(nameOBJ, nameHead, x, y, width, sl);
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
						yp = y + high * (sl - 1);
					}
				}
				else if (c == 80)
				{
					if (yp != y + high * (sl - 1))
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
				{
					for (int i = 0; i < number - 1; ++i)
					{
						for (int j = 0; j < number - i - 1; ++j)
						{
							if (strcmp(list_product[j].ProductID, list_product[j + 1].ProductID) < 0)
							{

								swap(list_product[j], list_product[j + 1]);
							}
						}
					}
					printListProduct(list_product, number, 3, 0);
					char status[][40] = { "DA SAP XEP GIAM DAM", "Nhan [ENTER] De Quay Lai" };
					statusreturnMenu(status, number);
					_getch();
					goto Start;
					break;
				}
				case 1:
				{
					for (int i = 0; i < number - 1; ++i)
					{
						for (int j = 0; j < number - i - 1; ++j)
						{
							if (strcmp(list_product[j].ProductID, list_product[j + 1].ProductID) > 0)
							{
								swap(list_product[j], list_product[j + 1]);
							}
						}
					}
					printListProduct(list_product, number, 3, 0);
					char status[][40] = { "DA SAP XEP TANG DAN", "Nhan [ENTER] De Quay Lai" };
					statusreturnMenu(status, number);
					_getch();
					goto Start;
					break;
				}
				case 2:
					return;
					break;
				}
			}
		}
	}
}

void Product::sortProductByName(Product list_product[], int number)
{
Start:
	int sl = 3;
	thanh_sang(0, 0, 172, 16 + number * 2, 1, "");
	string nameOBJ = "SAP XEP THEO TEN SAN PHAM";
	char nameHead[][40] = { "Giam Dan", "Tang Dan", "Quay Lai" };
	vemenu(nameOBJ, nameHead, x, y, width, sl);
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
						yp = y + high * (sl - 1);
					}
				}
				else if (c == 80)
				{
					if (yp != y + high * (sl - 1))
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
				{
					for (int i = 0; i < number - 1; ++i)
					{
						for (int j = 0; j < number - i - 1; ++j)
						{
							if (strcmp(list_product[j].ProductName, list_product[j + 1].ProductName) < 0)
							{

								swap(list_product[j], list_product[j + 1]);
							}
						}
					}
					printListProduct(list_product, number, 3, 0);
					char status[][40] = { "DA SAP XEP GIAM DAM", "Nhan [ENTER] De Quay Lai" };
					statusreturnMenu(status, number);
					_getch();
					goto Start;
					break;
				}
				case 1:
				{
					for (int i = 0; i < number - 1; ++i)
					{
						for (int j = 0; j < number - i - 1; ++j)
						{
							if (strcmp(list_product[j].ProductName, list_product[j + 1].ProductName) > 0)
							{

								swap(list_product[j], list_product[j + 1]);
							}
						}
					}
					printListProduct(list_product, number, 3, 0);
					char status[][40] = { "DA SAP XEP TANG DAN", "Nhan [ENTER] De Quay Lai" };
					statusreturnMenu(status, number);
					_getch();
					goto Start;
					break;
				}
				case 2:
					return;
					break;
				}
			}
		}
	}
}

void Product::sortProductByInstock(Product list_product[], int number)
{
Start:
	int sl = 3;
	thanh_sang(0, 0, 172, 16 + number * 2, 1, "");
	string nameOBJ = "SAP XEP THEO SO LUONG SAN PHAM";
	char nameHead[][40] = { "Giam Dan", "Tang Dan", "Quay Lai" };
	vemenu(nameOBJ, nameHead, x, y, width, sl);
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
						yp = y + high * (sl - 1);
					}
				}
				else if (c == 80)
				{
					if (yp != y + high * (sl - 1))
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
				{
					for (int i = 0; i < number - 1; ++i)
					{
						for (int j = 0; j < number - i - 1; ++j)
						{
							if ((list_product[j].Quantity < list_product[j + 1].Quantity))
							{
								swap(list_product[j], list_product[j + 1]);
							}
						}
					}
					printListProduct(list_product, number, 3, 0);
					char status[][40] = { "DA SAP XEP GIAM DAM", "Nhan [ENTER] De Quay Lai" };
					statusreturnMenu(status, number);
					_getch();
					goto Start;
					break;
				}
				case 1:
				{
					for (int i = 0; i < number - 1; ++i)
					{
						for (int j = 0; j < number - i - 1; ++j)
						{
							if ((list_product[j].Quantity > list_product[j + 1].Quantity))
							{

								swap(list_product[j], list_product[j + 1]);
							}
						}
					}
					printListProduct(list_product, number, 3, 0);
					char status[][40] = { "DA SAP XEP TANG DAN", "Nhan [ENTER] De Quay Lai" };
					statusreturnMenu(status, number);
					_getch();
					goto Start;
					break;
				}
				case 2:
					return;
					break;
				}
			}
		}
	}
}

void Product::statusReturn1line(int numProduct)
{
	char Return[] = { "Nhan [ENTER] De Quay Quay Lai" };
	int lengthRe = strlen(Return);
	gotoXY((172 - lengthRe) / 2 + 1, 9 + numProduct * 2);
	cout << Return;
	_getch();
}

int Product::returnProduct(Product list_product[], int& number, char searchID[])
{

	for (int i = 0; i < number; i++)
	{
		if (strcmp(list_product[i].ProductID, searchID) == 0)
		{
			return i;
		}
	}
}

#endif