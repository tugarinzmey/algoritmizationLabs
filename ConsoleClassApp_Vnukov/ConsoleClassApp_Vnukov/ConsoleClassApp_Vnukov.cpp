#include <string>
#include <iostream>
using namespace std;
#include "Customer.h"

int main()
{
	Customer mark("Bataysk", "Vnukov", 30);
	mark.cus_show();

	Customer roma("Cherkessk", "Kalabekov", 20);
	roma.cus_show();

	Customer buyer;
	buyer.cus_in();
	buyer.cus_show();
	system("pause");
	return 0;
}