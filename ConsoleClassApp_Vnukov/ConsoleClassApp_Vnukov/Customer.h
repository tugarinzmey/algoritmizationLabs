#pragma once
#include <iostream>
#include <string>

class Customer
{
public:
	void cus_show(void);
	void cus_in(void);
	string cusAdress;
	string name;
	int discount;
	Customer();
	Customer(string, string, int);
	~Customer(); 

private:
};
Customer::Customer()
{
}
Customer::Customer(string _cusAdress, string _name, int _discount)
{
	this->cusAdress = _cusAdress;
	this->name = _name;
	this->discount = _discount;
}
Customer::~Customer()
{
};
void Customer::cus_show(void)
{
	cout << "Adress: " << cusAdress << endl;
	cout << "Name: " << name << endl;
	cout << "Discount: " << discount << endl;

}
void Customer::cus_in(void)
{
	cout << "Enter adress" << endl;
	cin >> cusAdress;
	cout << "Enter full name" << endl;
	cin >> name;
	cout << "Enter discount " << endl;
	cin >> discount;
}