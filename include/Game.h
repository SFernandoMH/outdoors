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
        void buildMap();
        void run();
};
