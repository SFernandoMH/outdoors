#include "Door.h"

Door::Door(Room* roomA, Room* roomB) : open_(false) , roomA(roomA), roomB(roomB) {}

bool Door::isOpen() const {
    return this->open_;
}

void Door::open() {
    this->open_ = true;
}

void Door::close(int force) {

    this->open_ = false;
}