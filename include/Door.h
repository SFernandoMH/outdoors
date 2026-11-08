#pragma once
#include "Room.h"

class Room;

class Door {
    private:
        bool open_;
        Room* roomA;
        Room* roomB;
    public:
        Door(Room* roomA, Room* roomB);
        ~Door() = default;
        [[nodiscard]] bool isOpen() const;
        void open();
        void close(int force);

};

