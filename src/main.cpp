#include "Game.h"
#include <iostream>
int main() {
    Game game;
    int useroption = -1;
    while (useroption != 0) {
        useroption = game.showMenuRoom();
        if (useroption == 1) {
            game.showInventory();
        } else if (useroption == 2) {
            game.checkShelves();
        } else if (useroption == 3) {
            game.crossDoor();
        } else if (useroption == 4) {


            if (!std::empty(game.getEntitiesCurrentRoom())) {
                game.crossDoor();
            }
        } else if (useroption == 0) {break;}
        else {
            std::cout << "Opcion invalida!\n";
        }

    }



}