#include "Door.h"

Door::Door(Room* roomA, Room* roomB) : open_(false) , roomA(roomA), roomB(roomB) {}

Room* Door::getOtherRoom(const Room* current) const {
    if (current == roomA) {
        return roomB;
    }
    return roomA;
}

bool Door::isOpen() const {
    return this->open_;
}

void Door::open() {
    this->open_ = true;
}

void Door::close(int force) {

    this->open_ = false;
}