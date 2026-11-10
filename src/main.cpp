#include "Game.h"
#include <iostream>
int main() {
    Game game;
    int option = -1;
    while (option != 0) {
        int useroption = game.showMenuRoom();
        if (useroption == 1) {
            game.showInventory();
        } else if (useroption == 2) {
            game.checkShelves();
        } else if (useroption == 3) {
            game.crossDoor();
        } else if (useroption == 4) {
            game.fight();
        } else if (useroption == 0) {break;}
        else {
            std::cout << "Opcion invalida!\n";
        }
    }



}