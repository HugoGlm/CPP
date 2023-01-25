#include <iostream> 
#include "App.h"
#include "Button.h"
#include "EventSystem.h"
#include "Rect.h"

int main()
{
    App app;
    Rect rect = Rect(100, 100, 10, 10);
    Button button = Button("ok", &rect);
    EventSystem::Instance()->Register(&button);
    app.Open();
}