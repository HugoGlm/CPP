#include <iostream>
#include "Menu/Menu.h"
#include "Reservation/Add/AddReservation.h"
#include "Reservation/View/ViewReservation.h"

int main()
{
    AddReservation resa = AddReservation();
    ViewReservation view = ViewReservation();
    Menu menu = Menu();
    resa.Execute();
    //menu.Execute();
    //view.Execute();
}

/* probleme je ne peux pas lancer une window sans commenter les autres
* parce que j'ai 3 windowProc et il en faut 1
*
* le register et le view sont fais mais je sais pas si ca marche parce mes boutons marche pas 
*/