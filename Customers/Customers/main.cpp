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
	Customers cus(5);
	cus.add(Customer("��������� �����", "�������������", 10));
	cus.add(Customer("��������� ������", "����������", 20));
	Customer Vasya1("������� �����������", "������", 30);
	Customer Vasya2("������� �����������", "������", 30);
	if (Vasya1 == Vasya2)
		cout << "���� ���������" << endl;
	else
		cout << "���� �� ���������" << endl;
	cus.addKey();
	cus.display();
	system("pause");
	return 0;
}