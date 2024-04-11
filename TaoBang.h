#pragma once
#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <ctime>
#include <cstring>
#include <iomanip>
#include <thread>
#include <chrono>
#include <vector>
#include <map>
#include <io.h>
#include <fcntl.h>
#include <fstream>
#include <sstream>

#define KEY_NONE -1
using namespace std;
int x = 61;
int y = 10;
int width = 50;
int high = 2;
int t_color = 11;
int b_color = 1;
int b_color_sang = 60;
int lengPro[] = { 15, 25, 14, 12, 20, 20, 14, 10, 23, 12 };
char Header[][40] = { "Ma", "Ten San Pham", "Gioi Tinh", "Kich Co", "Loai", "Ngay Nhap", "Chat Lieu", "Gia", "Mo Ta", "Kho" };
char HeaderCus1[][40] = { "Ma SP", "Ten San Pham", "Kich Co", "So Luong", "Gia San Pham", "Tong Gia", "Ngay Mua" };
char HeaderCus[][40] = { "SDT", "Ten Khach Hang", "Gioi Tinh" };
int lengCus1[] = { 15, 30, 10, 12, 16, 16, 15 };
int lengCus[] = { 12, 25, 14 };
char HeaderEmp[][40] = { "Ma Nhan Vien","Ten Nhan Vien","So Dien Thoai","Mail","Ca Lam","Ngay Lam" };
int lengEmp[] = { 17,25,17,25,10,15 };
void Tao1Hop(int x, int y, int width, int high, int t_color, int b_color, string nd);
void TaoBangHeader(int number, int xp, int y, string nd, int lengPro[], char Header[][40], int sl);
void thanh_sang(int x, int y, int width, int high, int b_color, string nd);
void vemenu(string nameOBJ, char ele[][40], int x, int y, int width, int sl);
void NhieuHop(int x, int y, int width, int h, int t_color, int b_color, char nd[][40], int n);
void taomenuYeuCau(char nameHead[][40], char searchName[40]);
void HopKTen(int x, int y, int width, int high, int t_color, int b_color); // HopkTen
void gotoXY(int x, int y);
void SetColor(WORD color);
void ShowCur(bool CursorVisibility);
void statusreturnMenu(char status[][40], int vitri);
char* getTime(char a[11]);
void NhieuHopKTen(int x, int y, int width, int high, int t_color, int b_color, int n);
int tranfer_string(char string[]);
void swap(int& a, int& b);
void TaoBangCus(int number, int xp, int y, string nd, int lengPro[], char Header[][40], int sl, int a[], int numProduct);
void TaoBangCustomer(int numProduct, int numberCustomer, int numProinCus[]);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
void TextColor(int x) // X là mã màu
{
	// Các hàm này là hàm thao tác API với widthindowidths bạn cứ coppy thôi không cần phải hiểu quá sâu
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, x);
}
void HopKTen(int x, int y, int width, int high, int t_color, int b_color)
{
	TextColor(b_color);
	for (int iy = y + 1; iy <= y + high - 1; iy++)
	{
		for (int ix = x + 1; ix <= x + width - 1; ix++)
		{
			gotoXY(ix, iy);
			cout << " ";
		}
	}
	SetColor(t_color);
	if (high <= 1 || width <= 1)
		return;
	for (int ix = x; ix <= x + width; ix++)
	{
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + high);
		cout << char(196);
	}
	for (int iy = y; iy <= y + high; iy++)
	{
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + width, iy);
		cout << char(179);
	}
	gotoXY(x, y);
	cout << char(218);
	gotoXY(x + width, y);
	cout << char(191);
	gotoXY(x, y + high);
	cout << char(192);
	gotoXY(x + width, y + high);
	cout << char(217);
	SetColor(7);
}
void NhieuHopKTen(int x, int y, int width, int high, int t_color, int b_color, int n)
{
	for (int i = 0; i < n; i++)
	{
		HopKTen(x, y + (2 * i), width, high, t_color, b_color);
		if (i != 0)
		{
			SetColor(11);
			gotoXY(x, y + (2 * i));
			cout << char(195);
			gotoXY(x + width, y + (2 * i));
			cout << char(180);
		}
	}
}
void NhieuHop(int x, int y, int width, int high, int t_color, int b_color, char nd[][40], int n)
{ // nbox

	for (int i = 0; i < n; i++)
	{
		Tao1Hop(x, y + (2 * i), width, high, t_color, b_color, nd[i]);
		if (i != 0)
		{
			gotoXY(x, y + (2 * i));
			cout << char(195);
			gotoXY(x + width, y + (2 * i));
			cout << char(180);
		}
	}
	SetColor(7);
}
void vemenu(string nameOBJ, char ele[][40], int x, int y, int width, int sl)
{
	Tao1Hop(x, 3, width, 2, 11, 1, nameOBJ);
	ShowCur(0);
	int high = 2;
	int t_color = 11;
	int b_color = 1;
	int b_color_sang = 60;
	NhieuHop(x, y, width, high, t_color, b_color, ele, sl);
	thanh_sang(x, y, width, high, b_color_sang, ele[0]);
}
void TaoBangHeader(int number, int xp, int y, string nd, int lengPro[], char Header[][40], int sl)
{
	ShowCur(0);
	int len = 0;

	for (int i = 0; i < sl; i++)
	{
		NhieuHopKTen(xp + len, y + 2, lengPro[i], 2, 11, 1, number + 1);
		len += lengPro[i];
	}
	Tao1Hop(xp, y, len, 2, 11, 1, nd);
	int x;
	int l = 0;
	for (int i = 0; i < sl; i++)
	{
		int m = (lengPro[i] - strlen(Header[i])) / 2;
		x = xp + m + 1 + l;
		gotoXY(x, y + 3);
		l += lengPro[i];
		cout << Header[i];
	}
	gotoXY(xp, y + 2);
	cout << char(195);
	gotoXY(xp + len, y + 2);
	cout << char(180);
	len = 0;

	for (int i = 0; i < number + 2; i++)
	{
		int len1 = 0;
		for (int j = 0; j < sl - 1; j++)
		{
			if (i != 0)
			{
				len1 += lengPro[j];
				gotoXY(xp + len1, y + 2 + (i) * 2);
				cout << char(197);
			}
			if (i == number + 1)
			{
				gotoXY(xp + len1, y + 2 + 2 * i);
				cout << char(193);
			}
			if (i == 0)
			{
				len += lengPro[j];
				gotoXY(xp + len, y + 2);
				cout << char(194);
			}
		}
	}
}
void Tao1Hop(int x, int y, int width, int high, int t_color, int b_color, string nd)
{
	TextColor(b_color);
	for (int iy = y + 1; iy <= y + high - 1; iy++)
	{
		for (int ix = x + 1; ix <= x + width - 1; ix++)
		{
			gotoXY(ix, iy);
			cout << " ";
		}
	}
	int m = (width - nd.length()) / 2;
	SetColor(7);
	gotoXY(x + 1 + m, y + 1);
	cout << nd;
	TextColor(1);
	SetColor(t_color);
	if (high <= 1 || width <= 1)
		return;
	for (int ix = x; ix <= x + width; ix++)
	{
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + high);
		cout << char(196);
	}
	for (int iy = y; iy <= y + high; iy++)
	{
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + width, iy);
		cout << char(179);
	}
	gotoXY(x, y);
	cout << char(218);
	gotoXY(x + width, y);
	cout << char(191);
	gotoXY(x, y + high);
	cout << char(192);
	gotoXY(x + width, y + high);
	cout << char(217);
}

void thanh_sang(int x, int y, int width, int high, int b_color, string nd)
{

	TextColor(b_color);
	for (int iy = y + 1; iy <= y + high - 1; iy++)
	{
		for (int ix = x + 1; ix <= x + width - 1; ix++)
		{
			gotoXY(ix, iy);
			cout << " ";
		}
	}
	int m = (width - nd.length()) / 2;
	// vẽ viền đè
	SetColor(7);
	gotoXY(x + 1 + m, y + 1);
	cout << nd;
}
char* getTime(char a[11])
{
	time_t baygio = time(0);
	tm* ltm = localtime(&baygio);
	int Ngay = ltm->tm_mday;
	int Thang = 1 + ltm->tm_mon;
	int Nam = 1900 + ltm->tm_year;
	sprintf(a, "%02d/%02d/%04d", Ngay, Thang, Nam);
	return a;
}
void taomenuYeuCau(char nameHead[][40], char searchName[40])
{

	NhieuHop(4, 0, 165, 2, 11, 1, nameHead, 2);
	SetColor(7);
	ShowCur(1);
	gotoXY(4 + 1 + (165 - strlen(nameHead[1])) / 2 + strlen(nameHead[1]), 3);

	cin.getline(searchName, 20);
	ShowCur(0);
}
void statusreturnMenu(char status[][40], int vitri)
{
	gotoXY(4 + 1 + (165 - strlen(status[0])) / 2, vitri);
	cout << status[0];
	gotoXY(4 + 1 + (165 - strlen(status[1])) / 2, vitri + 2);
	cout << status[1];

}

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}
void TaoNHopNgang(int x, int y, int width, int high, int t_color, int b_color, int n)
{
	int len = 0;
	for (int i = 0; i < n; i++)
	{
		HopKTen(len, 4, strlen(HeaderCus[i]), 4, t_color, b_color);
		len += strlen(HeaderCus[i]);
	}
}
void TaoBangCus(int number, int xp, int y, string nd, int lengPro[], char Header[][40], int sl, int a[], int numProduct)
{
	ShowCur(0);
	int lenx = 0;
	int leny = 2;
	number++;
	for (int i = number; i > 0; i--)
	{
		a[i] = a[i - 1];
	}

	// Thêm phần tử vào vị trí index
	a[0] = 1;

	for (int i = 0; i < sl; i++)
	{
		for (int j = 0; j < number; j++)
		{

			HopKTen(xp + lenx, y + leny, lengPro[i], a[j] * 2, 11, 1);
			leny += a[j] * 2;
		}
		lenx += lengPro[i];
		leny = 2;
	}
	Tao1Hop(xp, 0, 51, 2, 11, 1, nd);
	int x;
	int l = 0;
	for (int i = 0; i < sl; i++)
	{
		int m = (lengPro[i] - strlen(Header[i])) / 2;
		x = xp + m + 1 + l;
		gotoXY(x, y + 3);
		l += lengPro[i];
		cout << Header[i];
	}
	// gotoXY(xp, y + 2); cout << char(195);
	// gotoXY(xp + lenx, y + 2); cout << char(180);
	// lenx = 0;
	leny = 2;
	for (int i = 0; i < number; i++)
	{
		int len1 = 0;

		for (int j = 0; j < sl; j++)
		{
			len1 += lengPro[j];
			if (i != 0)
			{

				gotoXY(xp + len1, y + leny);
				cout << char(197);
			}

			if (i == number)
			{
				gotoXY(xp + len1, y + leny);
				cout << char(193);
			}
			if (j == 0)
			{
				gotoXY(xp, y + leny);
				cout << char(195);
			}
			if (j == sl - 1)
			{
			}
		}
		leny += a[i] * 2;
	}
	leny = 2;
	for (int i = 0; i < numProduct + 1; i++)
	{
		gotoXY(55, y + 2 + 2 * i);
		cout << char(195);
	}
	for (int i = 0; i < number; i++)
	{

		gotoXY(55, y + leny);
		cout << char(197);
		leny += a[i] * 2;
	}
	int len1 = 0;
	for (int i = 0; i < 2; i++)
	{
		len1 += lengPro[i];
		gotoXY(xp + len1, 2);
		cout << char(194);
	}
	len1 = 0;
	for (int i = 0; i < 3; i++)
	{
		len1 += lengPro[i];
		gotoXY(xp + len1, leny);
		cout << char(193);
	}
	gotoXY(55, 0);
	cout << char(194);
	for (int i = 0; i < number; i++)
	{
		a[i] = a[i + 1];
	}
	number--;
}
void TaoBangCustomer(int numProduct, int numberCustomer, int numProinCus[])
{

	TaoBangHeader(numProduct, 55, 0, "Danh San Pham", lengCus1, HeaderCus1, 7);
	TaoBangCus(numberCustomer, 4, 0, "Khach Hang", lengCus, HeaderCus, 3, numProinCus, numProduct);
}
int MenuDong(string NameOBJ, char  nameHead[][40], int  Soluong) {
	TextColor(1);
	system("cls");
	vemenu(NameOBJ, nameHead, x, y, width, Soluong);
	int xp = x;
	int yp = y;
	int xcu = xp;
	int ycu = yp;
	bool kt = false;
	int Choice1;
	while (1)
	{
		int Choice = (ycu - y) / 2;
		Choice1 = (yp - y) / 2;
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
				Choice1 = (yp - y) / 2;
				goto End;
			}
		}
	}
End:
	return Choice1;
}