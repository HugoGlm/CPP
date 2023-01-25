#include <iostream>
#include "Item/Wifi/Wifi.h"
#include "Item/Time/Time.h"
#include "Menu/Menu.h"

int main()
{
	Menu::Display();
	Wifi::Display();
	Time::Display();
	system("pause");
}