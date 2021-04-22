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
	cus.add(Customer("Калабеков Роман", "Комсомольская", 10));
	cus.add(Customer("Кузьменко Максим", "Пушкинская", 20));
	Customer Vasya1("Василий Васильченко", "Ленина", 30);
	Customer Vasya2("Василий Васильченко", "Ленина", 30);
	if (Vasya1 == Vasya2)
		cout << "Васи одинаковы" << endl;
	else
		cout << "Васи не одинаковы" << endl;
	cus.addKey();
	cus.display();
	system("pause");
	return 0;
}