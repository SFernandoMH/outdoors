#include "Game.h"

int main() {
    Game game;
    int option = -1;
    while (option != 0) {
        int useroption = game.showMenuRoom();
        if (useroption == 1) {
            game.showInventory(); // ARREGLAR!!
        } else if (useroption == 2) {
            game.checkShelves();
        } else if (useroption == 3) {
            game.crossDoor();
        }
    }



}