#include <iostream>
#include "Window/Window.h"
#include "Window/Menu/MainMenu/MainMenu.h"
#include "Window/Menu/BookingMenu/BookingMenu.h"
#include "Window/Menu/BookingViewMenu/BookingViewMenu.h"
#include "Window/Menu/BookingViewDataMenu/BookingViewDataMenu.h"
#include "Utils/DataBase/DataBase.h"

int main()
{
    Window window = Window(L"Hotel O3D", 900, 800);
    window.RegisterMenu(new MainMenu(&window));
    window.RegisterMenu(new BookingMenu(&window));
    window.RegisterMenu(new BookingViewMenu(&window));
    window.RegisterMenu(new BookingViewDataMenu(&window));
    window.SetCurrentMenu(MAINMENU);
    window.Open();
}