
#include "goods.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#pragma warning(disable : 4996)
FILE* fl;
char flName[20];
TGoods* goods;
int nst = 0;
int i;
int Menu()
{
	cout << "Choose an option:" << endl;
	cout << "1. Enter file name" << endl;
	cout << "2. Create a file" << endl;
	cout << "3. Goods input" << endl;
	cout << "4. Read file" << endl;
	cout << "5. Sort by price over million" << endl;
	cout << "6. Save result" << endl;
	cout << "7. EXIT" << endl;
	int userChoise;
	cout << endl;
	cout << "Press a key: ";
	cin >> userChoise;
	return userChoise;
}

void Nnf()
{
	cout << "Enter name of a file: " << endl;
	cin >> flName;
}

void Newf()
{
	if ((fl = fopen(flName, "wb")) == NULL)
	{
		cout << "Error by creating" << endl;
		system("pause");
		exit(1);
	}
	cout << endl;
	cout << "Succesful..." << endl;
	fclose(fl);
}

void Spisok()
{
	if ((fl = fopen(flName, "rb+")) == NULL)
	{
		cout << "Error by file reading" << endl;
		system("pause");
		exit(1);
	}
	cout << "Input amount of new positions ";
	cin >> nst;
	goods = new TGoods[nst];
	for (int i = 0; i < nst; i++)
	{
		cout << "Press any key";
		getline(cin, goods[i].name);
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Input position name: ";
		getline(cin, goods[i].name);
		cout << "Input amount of current goods: ";
		cin >> goods[i].amount;
		cout << "Input price: ";
		cin >> goods[i].price;
		fwrite(&goods[i], sizeof(TGoods), 1, fl);
	}
	cout << "Saving..." << endl;
	fclose(fl);
}

void Opf()
{
	if ((fl = fopen(flName, "rb")) == NULL)
	{
		cout << "Error by file opening" << endl;
		exit(1);
	}
	nst = 0;
	TGoods pos;
	while (true)
	{
		int nwrt = fread(&pos, sizeof(TGoods), 1, fl);
		if (nwrt != 1)
		{
			break;
		}
		goods[nst] = pos;
		cout << goods[nst].name << " "
			<< goods[nst].amount << " "
			<< goods[nst].price << endl;
		nst++;
	}
	fclose(fl);
}

void Resc()
{
	cout << "List of goods that are sorted by price over a million: ";
	for (int i = 0; i < nst; i++)
		if (goods[i].price >= 1000000);
			cout << goods[i].name << endl;
}

void Resf()
{
	char namet[30];
	FILE* ft;
	cout << "Enter file name:" << endl;
	cin >> namet;
	if ((ft = fopen(namet, "w")) == NULL)
	{
		cout << "Error by creating a file" << endl;
		exit(1);
	}
	char s[80];
	for (int i = 0; i < nst; i++)
		if (goods[i].price > 1000000);
		{
			strcpy(s, (goods[i].name + "\n").c_str());
			fputs(s, ft);
		}
	fclose(ft);
}