#include <iostream>
#include "LauncherItem.h"
#include "MorpionGame.h"
#include "FlappyBird.h"
#include "DynoGame.h"
#include "Launcher.h"
#include <Windows.h>

int main()
{
    SetConsoleTitle(L"Launcher");
    Launcher _launcher = Launcher({
        new LauncherItem(new MorpionGame()),
        new LauncherItem(new FlappyBird()),
        new LauncherItem(new DynoGame()),
        });
    _launcher.Open();
}