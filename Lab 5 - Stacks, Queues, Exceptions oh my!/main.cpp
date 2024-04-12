#include <iostream>
#include "OutOfPancakeException.h"
#include <Windows.h>

#include "PancakeShop.h"

int main()
{
	PancakeShop shop(30);
	while (shop.GetCustomerCount() > 0) {
		shop.ClearScreen();
		shop.DisplayStats();
		shop.TakeOrder();
		Sleep(1000);
	}

	shop.Close();
}