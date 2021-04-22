#pragma once
#include <functional>
#include <iostream>
#include "windows.h"
#include <conio.h>
#include <string>
using namespace std;
class Customer
{
public:
    // get set
    string getName() { return this->name; }
    void setName(string name) { this->name = name; }
    string getAdress() { return this->adress; }
    void setAdress(string adress) { this->adress = adress; }
    int getDiscount() { return this->discount; }
    void setDiscount(int discount) { this->discount = discount; }

    void Emp_show(void)
    {
        setlocale(LC_ALL, "rus");
        cout << "ФИО: " << name << endl;
        cout << "оплата в час: " << adress << endl;
        cout << "Часы: " << discount << endl;

    }

    void Emp_in(void)
    {
        setlocale(LC_ALL, "rus");
        cout << "Введите полное имя покупателя" << endl;
        cin >> name;
        setName(name);
        cout << "Введите адрес покупателя" << endl;
        cin >> adress;
        setAdress(adress);
        cout << "Введите скидку" << endl;
        cin >> discount;
        setDiscount(discount);
    }

    //конструктор без параметров
    Customer()
    {
    }

    //конструктор с параметрами
    Customer(string _name, string _adress, int _discount)
    {
        this->name = _name;
        this->adress = _adress;
        this->discount = _discount;
    }
    //деструктор
    ~Customer()
    {
    }

    //перегрузка
    friend bool operator==(Customer& one, Customer& two)
    {
        if (one.name == two.name && one.adress == two.adress && one.discount == two.discount)
            return 1;

        return 0;
    }
private:
    string name;
    string adress;
    int discount;
};


bool DiscountEq(Customer& cus1) { int value = cus1.getDiscount(); return value == 10; };

class Customers {
public:
    Customers(int countcustomers) {
        this->fullCustomers = countcustomers;
        customers = new Customer[countcustomers];
    }
    Customers() {}
    //ввод
    void add(string name, string adress, int discount) {
        if (currentIndex < fullCustomers) {
            customers[currentIndex] = Customer(name, adress, discount);
            currentIndex++;
            checkFullMass(currentIndex);
        }
        else
            cout << "Слишком много покупателей" << endl;
    }
    //добавление
    void add(Customer customer) {
        if (currentIndex < fullCustomers) {
            customers[currentIndex] = customer;
            currentIndex++;
            checkFullMass(currentIndex);
        }
        else
            cout << "Слишком много покупателей" << endl;
    }
    //добавление с клавиатуры
    void addKey()
    {
        if (currentIndex < fullCustomers)
        {
            customers[currentIndex].Emp_in();
            currentIndex++;
        }
        else
            cout << "Слишком много покупателей" << endl;
    }
    int counts() {
        return this->currentIndex;
    }

    void display() {
        for (int i = 0; i < currentIndex; i++) {
            customers[i].Emp_show();
        }
        cout << "--------------------------------" << endl;
    }
    Customer& operator [](int index) {
        return  customers[index];
    }

private:
    Customer* customers;
    int currentIndex = 0;
    int fullCustomers;
    void checkFullMass(int count) {
        if (currentIndex == fullCustomers) {
            cout << "Список покупателей заполнен!" << endl;

        }
    }
public:
    void remove(int atCustomer) {
        for (int i = atCustomer; i < currentIndex - 1; i++) {
            customers[i] = customers[i + 1];
        }
        currentIndex--;

    }

    Customer* find(const function<bool(Customer&)>& DiscountEq) {
        for (int i = 0; i < currentIndex; i++)
            if (DiscountEq(customers[i]))
                return &customers[i];
        return NULL;
    }
    Customers* findAll(const function<bool(Customer&)>& predicate) {
        static Customers findCustomers(currentIndex);
        for (int i = 0; i < currentIndex; i++)
            if (predicate(customers[i]))
                findCustomers.add(customers[i]);
        return findCustomers.counts() > 0 ? &findCustomers : NULL;
    }
};


