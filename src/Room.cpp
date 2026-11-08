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

void Room::addShelve(Shelf* shelf) {
    shelves.push_back(shelf);
}
void Room::addEntity(Entity* entity) {
    entities.push_back(entity);
}
void Room::addDoor(Door* door) {
    doors.push_back(door);
}

std::vector<Shelf*> Room::getShelves() {
    return shelves;
}

std::vector<Entity*> Room::getEntities() {
    return entities;
}

std::vector<Door*> Room::getDoors() {
    return doors;
}


