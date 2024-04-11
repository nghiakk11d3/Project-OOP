
#ifndef EMPLOYEE
#define EMPLOYEE

#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include "UserName.h"
#include <iostream>
#include <ctime>

using namespace std;
class Employee :public UserName {
public:
	float wage;
	double Salary(time_t t_batdau, time_t t_ketthuc);

	int returnEmployee(Employee list_employee[], int numberEmployee, char searchAcc[]);
	void InputEmp();
	void addEmployee(Employee list_employee[], int& numberEmployee);
	void print1Emp(Employee employee, int x, int y, int i);
	void printListEmp(Employee list_employee[], int number);
};
double Employee::Salary(time_t t_batdau, time_t t_ketthuc) {
	// Tính toán số giờ làm việc
	double gio_lamviec = difftime(t_ketthuc, t_batdau) / 3600.0;

	// Tính toán lương tổng
	double luong_tong = gio_lamviec * 35000;

	return luong_tong;
}
int Employee::returnEmployee(Employee list_employee[], int numberEmployee, char searchID[])
{

	for (int i = 0; i < numberEmployee; i++)
	{
		if (strcmp(list_employee[i].getID(), searchID) == 0)
		{
			return i;
		}
	}
}

void Employee::InputEmp() {
	int x0 = x + 2;
	int x1 = 90;
	int high = 16;
	int width = 25;
	char name[20];  
	char phone[11]; 
	char mail[15]; 
	char id[10]; 
	char shift[2]; 
	char day[10];
	ShowCur(1);
	HopKTen(x, y, width, high, 11, 1);
	HopKTen(x + 26, y, width, high, 11, 1);
	y += 2;
	gotoXY(x0, y + 1);
	cout << "Ma Nhan Vien:";
	gotoXY(x1, y + 1);
	cin >>id;
	UserName::setID(id);
	gotoXY(x0, y + 3);
	cout << "Ten Nhan Vien:";
	gotoXY(x1, y + 3);
	cin.ignore();
	cin.getline(name, 20);
UserName::setName(name);
	gotoXY(x0, y + 5);
	cout << "So Dien Thoai:";
	gotoXY(x1, y + 5);
	cin >> (phone);
UserName::setPhone(phone);
	gotoXY(x0, y + 7);
	cout << "Mail:";
	gotoXY(x1, y + 7);
	cin >> (mail);
UserName::setMail(mail);
	gotoXY(x0, y + 9);
	cout << "Ca Lam:";
	gotoXY(x1, y + 9);
	cin >> (shift);
UserName::setShift(shift);
	gotoXY(x0, y + 11);
	cout << "Ngay Lam: ";
	gotoXY(x1, y + 11);
	cin >> (day);
UserName::setDay(day);
	

}
void Employee::addEmployee(Employee list_employee[], int& numberEmployee)
{
	TextColor(1);
	system("cls");
	char nameHead[][40] = { "THEM NHAN VIEN ", "Nhap So Luong Nhan Vien Can Them:" };
	NhieuHop(4, 0, 165, 2, t_color, b_color, nameHead, 2);
	ShowCur(1);
	int SoluongThem = 0;
	gotoXY(6 + (165 - strlen(nameHead[1])) / 2 + strlen(nameHead[1]), 3);
	cin >> SoluongThem;
	for (int i = 0; i < SoluongThem; i++)
	{
		list_employee[numberEmployee].InputEmp();
		numberEmployee++;
	}
	char status[][40] = { "Da Them Thanh Cong", "Nhan [ENTER] De Quay Lai" };
	statusreturnMenu(status, 45);
	_getch();
	return;
	/*menuProduct(list_product, number);*/
}
void Employee::print1Emp(Employee employee, int x, int y, int i) {
	int x_width = 1;
	gotoXY(x + x_width, y + 2 * i + 1);
	cout << employee.getID();
	x_width += lengEmp[0];
	gotoXY(x + x_width, y + 2 * i + 1);
	cout << employee.getNameUser();
	x_width += lengEmp[1];
	gotoXY(x + x_width, y + 2 * i + 1);
	cout << employee.getPhoneUser();
	x_width += lengEmp[2];
	gotoXY(x + x_width, y + 2 * i + 1);
	cout << employee.getMailUser();
	x_width += lengEmp[3];
	gotoXY(x + x_width, y + 2 * i + 1);
	cout << employee.getShift();
	x_width += lengEmp[4];
	gotoXY(x + x_width, y + 2 * i + 1);
	cout << employee.getID();
}
void Employee::printListEmp(Employee list_employee[], int number)
{
	TextColor(1);
	system("cls");
	TaoBangHeader(number, 1, 1, "DANH SACH SAN PHAM", lengEmp, HeaderEmp, 6);
	SetColor(7);
	y += 4;
	for (int i = 0; i < number; i++)
	{
		print1Emp(list_employee[i],1, 5, i);
	}
	/*statusReturn1line(number - 2);
	menuProduct(list_product, number);*/
}
#endif