#include <iostream>
#include "Map.h"
#include "Environment.h"
#include "Player.h"
#include "Utils.h"
#include "Case.h"
#include "Vector2.h"
#include "MapLoader.h"


int main()
{
    Player* _player = new Player(Utils::UserChoice<std::string>("enter your username"));
    MapLoader _loader = MapLoader();
    _loader.Load();
    if (_loader.IsEmpty())
        return -5;
    _loader.DisplayMapNames();
    Map* map = _loader.GetMap(Utils::UserChoice<int>("choose map : "));
    if (!map->IsValid())
        return -4;
    map->SetPlayer(_player);
    while (!map->GetPlayer()->Position()->Equals(map->Exit()->Position()))
    {
        system("cls");
        map->Display();
        map->GetPlayer()->Move();
    }
    system("cls");
    Utils::Log(map->GetPlayer()->Name() + " find the exit !");
}