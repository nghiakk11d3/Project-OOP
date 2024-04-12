
#ifndef EMPLOYEE
#define EMPLOYEE

#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include "Person.h"
#include "Customer.h"
#include <iostream>
#include <ctime>

using namespace std;
class Employee :public Person {	
private:
	char Mail[30];
	char ID[15];
	char Shift[15];
	char Day[15];
public:
	
	char* getMail() {
		return this->Mail;
	}
	char* getID() {
		return this->ID;
	}
	char* getShift() {
		return this->Shift;
	}
	char* getDay() {
		return this->Day;
	}
	void setMail(const char* mail) {
		strcpy(this->Mail, mail);
	}
	void setID(const char* id) {
		strcpy(this->ID, id);
	}
	void setShift(const char* shift) {
		strcpy(this->Shift, shift);
	}
	void setDay(const char* day) {
		strcpy(this->Day, day);
	}

	int returnEmployee(Employee list_employee[], int numberEmployee, char searchAcc[]);
	void InputEmp();
	void addEmployee(Employee list_employee[], int& numberEmployee);
	void print1Emp(Employee employee, int x, int y, int i);
	void printListEmp(Employee list_employee[], int number);
	void menuEmployee(Employee list_employee[], int& numberEmployee);
	void editEmployee(Employee list_employee[], int& numberEmployee);
	void deleteEmployee(Employee list_employee[], int& numberEmployee);
	
	void statusReturn1line1(int numProduct)
	{
		char Return[] = { "Nhan [ENTER] De Quay Quay Lai" };
		int lengthRe = strlen(Return);
		gotoXY((172 - lengthRe) / 2 + 1, 9 + numProduct * 2);
		cout << Return;
		_getch();
	}
};


int Employee::returnEmployee(Employee list_employee[], int numberEmployee, char searchID[])
{

	for (int i = 0; i < numberEmployee; i++)
	{
		if (strcmp(list_employee[i].ID, searchID) == 0)
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
	char name[25];
	char phone[11];
	y = 10;
	ShowCur(1);
	HopKTen(x, y, width, high, 11, 1);
	HopKTen(x + 26, y, width, high, 11, 1);
	y += 2;
	gotoXY(x0, y + 1);
	cout << "Ma Nhan Vien:";
	gotoXY(x1, y + 1);
	cin >> this->ID;
	gotoXY(x0, y + 3);
	cout << "Ten Nhan Vien:";
	gotoXY(x1, y + 3);
	cin.ignore();
	cin.getline(name, 20);
	Person::setName(name);
	gotoXY(x0, y + 5);
	cout << "So Dien Thoai:";
	gotoXY(x1, y + 5);
	cin >> (phone);
	setphoneNumber(phone);
	gotoXY(x0, y + 7);
	cout << "Mail:";
	gotoXY(x1, y + 7);
	cin >> (this->Mail);
	gotoXY(x0, y + 9);
	cout << "Ca Lam:";
	gotoXY(x1, y + 9);
	cin >> (this->Shift);

	gotoXY(x0, y + 11);
	cout << "Ngay Lam: ";
	gotoXY(x1, y + 11);
	cin >> (this->Day);
	cin.ignore();


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

	menuEmployee(list_employee, numberEmployee);
}
void Employee::print1Emp(Employee employee, int x, int y, int i) {
	int x_width = 2;
	gotoXY(x + x_width, y + 2 * i + 1);
	cout << employee.ID;
	x_width += lengEmp[0];
	gotoXY(x + x_width, y + 2 * i + 1);
	cout << employee.getName();
	x_width += lengEmp[1];
	gotoXY(x + x_width, y + 2 * i + 1);
	cout << employee.getphoneNumber();
	x_width += lengEmp[2];
	gotoXY(x + x_width, y + 2 * i + 1);
	cout << employee.Mail;
	x_width += lengEmp[3];
	gotoXY(x + x_width, y + 2 * i + 1);
	cout << employee.Shift;
	x_width += lengEmp[4];
	gotoXY(x + x_width, y + 2 * i + 1);
	cout << employee.Day;
}
void Employee::printListEmp(Employee list_employee[], int number)
{
	TextColor(1);
	system("cls");
	TaoBangHeader(number, 37, 0, "DANH SACH NHAN VIEN", lengEmp, HeaderEmp, 6);
	SetColor(7);
	y += 4;
	for (int i = 0; i < number; i++)
	{
		print1Emp(list_employee[i], 37, 4, i);
	}
	statusReturn1line1(number - 1);
	menuEmployee(list_employee, number);

}
void Employee::editEmployee(Employee list_employee[], int& numberEmployee) {

	TextColor(1);
	system("cls");
	char nameHead[][40] = { "Sua Thong Tin Nhan Vien ", "Nhap Ma Nhan Vien: " };
	char searchID[10];
	bool KT = false;
	int Index = -1;
	taomenuYeuCau(nameHead, searchID);
	for (int i = 0; i < numberEmployee; i++)
	{
		if (strcmp(searchID, list_employee[i].ID) == 0)
		{
			list_employee[i].InputEmp();
			KT = true;
		}
	}
	if (KT == true)
	{
		char status[][40] = { "Da Sua Thanh Cong", "Nhan [ENTER] De Quay Lai" };
		statusreturnMenu(status, 45);
		_getch();
		menuEmployee(list_employee, numberEmployee);
	}
	else
	{
		char status[][40] = { "Khong Tim Thay Ma", "Nhan [ENTER] De Quay Lai" };
		statusreturnMenu(status,20);
		_getch();
		menuEmployee(list_employee, numberEmployee);
	}
}
void Employee::deleteEmployee(Employee list_employee[], int& numberEmployee) {
	TextColor(1);
	system("cls");
	char nameHead[][40] = { "Xoa Thong Tin Nhan Vien ", "Nhap Ma Nhan Vien: " };
	char searchID[10];
	bool KT = false;
	int Index = -1;
	taomenuYeuCau(nameHead, searchID);
	for (int i = 0; i < numberEmployee; i++)
	{
		if (strcmp(searchID, list_employee[i].ID) == 0)
		{
			for (int j = i; j < numberEmployee - 1; j++) {
				list_employee[j] = list_employee[j + 1];
			}
			numberEmployee--;
			KT = true;
			i--;

		}

	}
	if (KT == true)
	{
		char status[][40] = { "Da Xoa Thanh Cong", "Nhan [ENTER] De Quay Lai" };
		statusreturnMenu(status, 20);
		_getch();
		menuEmployee(list_employee, numberEmployee);
	}
	else
	{
		char status[][40] = { "Khong Tim Thay Ma", "Nhan [ENTER] De Quay Lai" };
		statusreturnMenu(status, 20);
		_getch();
		menuEmployee(list_employee, numberEmployee);
	}
}



#endif