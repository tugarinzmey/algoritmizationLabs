#pragma once
#include <string>
#pragma warning(disable : 4996)
using namespace std;

struct TGoods
{
	string name;
	unsigned int amount;
	unsigned int price;
};

int Menu();
void Nnf();
void Newf();
void Spisok();
void Opf();
void Resc();
void Resf();
