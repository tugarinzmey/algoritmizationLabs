#include <iostream>
#include <string>
#include "windows.h"
#include <conio.h>
using namespace std;
#include "Customer.h"
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	Customer Vasya1("������� �����������", "������", 30);
	Customer Vasya2("������� �����������", "������", 30);
	if (Vasya1 == Vasya2)
		cout << "���� ���������" << endl;
	else
		cout << "���� �� ���������" << endl;
	Customers cus(5);
	cus.add(Customer("��������� �����", "�������������", 10));
	cus.add(Customer("��������� ������", "����������", 20));
	cus.addKey();
	cus.display();
	bool(*filter)(Customers& cus1) = DiscountEq;
	system("pause");
	return 0;
}