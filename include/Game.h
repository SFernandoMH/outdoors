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
        [[nodiscard]] std::vector<Entity*> getEntitiesCurrentRoom()  const;
        [[nodiscard]] int showMenuRoom() const; // Muestra lo que puedes hacer en la habitacion
        void showInventory() ;
        void checkShelves();
        void crossDoor();
        void fight();
        void buildMap();
        void run();
};
