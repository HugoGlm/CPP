#include <iostream>
#include "Menu/Home/HomeMenu.h"
#include "LinkedList/List.h"
#include "File/ShowFile/ShowFile.h"
#include "File/Manager/Manager.h"
#include "Utils/Utils.h"
#include "DateTime/DateTime.h"
#include "Window/Window.h"

int main()
{
	Window w = Window();
	w.Execute();

	/*DateTime time = DateTime();
	time.ShowDateTime();*/

	/*Manager manager = Manager();
	Utils::Log(manager.GetMesssage("Path", "Test"));
	Utils::Log(manager.GetMesssage("Path", "Hello, ca va ?"));*/

	/*List<int> list = List<int>();
	list.AddFirst(10);
	list.AddFirst(15);
	list.Display();
	list.Remove(15);
	list.Display();*/

	/*HomeMenu home = HomeMenu();
	home.Open();
	home.Update();*/
}