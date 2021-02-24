#include <conio.h>
#include <windows.h>
#include "Goods.h"
#pragma warning(disable : 4996)
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true)
	{
		switch (Menu())
		{
		case 1: Nnf(); break;
		case 2: Newf(); break;
		case 3: Spisok(); break;
		case 4: Opf(); break;
		case 5: Resc(); break;
		case 6: Resf(); break;
		case 7: return 0;
		default: puts("Wrong input!");

		}
		puts("Press any key to continue...");
		getch();
		system("cls");
	}
}