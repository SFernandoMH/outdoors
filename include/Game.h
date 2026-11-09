#pragma once

#include "Player.h"
#include "Room.h"
#include "Door.h"


class Room;
class Player;

class Game {
    private:
        Player* player;
        Room* currentRoom;
        Door* lastDoor;
        std::vector<Room*> rooms;
        std::vector<Door*> doors;
    public:
        Game();
        ~Game();
        [[nodiscard]] int showMenuRoom() const; // Muestra lo que puedes hacer en la habitacion
        [[nodiscard]] int showInventory() const;
        [[nodiscard]] int checkShelves() const;
        void crossDoor();
        void buildMap();
        void run();
};
