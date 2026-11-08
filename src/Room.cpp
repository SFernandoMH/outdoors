#include "Room.h"

Room::Room(const std::string& description) : description(description) {}

Room::~Room() {
    for (Shelf* shelf : shelves) {
        delete shelf;
    }


    for (Entity* entity : entities) {
        delete entity;
    }
}

void Room::applySlam(int force) {
    for (Shelf* shelf : shelves) {
        shelf->hit(force);
    }
}

void Room::addShelf(Shelf* shelf) {
    shelves.push_back(shelf);
}
void Room::addEntity(Entity* entity) {
    entities.push_back(entity);
}
void Room::addDoor(Door* door) {
    doors.push_back(door);
}

std::vector<Shelf*> Room::getShelves() const
{
    return shelves;
}

std::vector<Entity*> Room::getEntities() const  {
    return entities;
}

std::vector<Door*> Room::getDoors() const {
    return doors;
}


