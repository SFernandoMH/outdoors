#include "Room.h"
#include <algorithm>

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

void Room::removeitemFromShelf(int index, Item* item) const  {
    this->shelves[index]->removeItem(item);
}
void Room::addEntity(Entity* entity) {
    entities.push_back(entity);
}

bool Room::hasLivinEntities() const {
    return std::any_of(entities.begin(), entities.end(),
                       [](const Entity* e) { return e->isAlive(); });
}

void Room::removeDeadEntities() {
    for (int i = 0; i < entities.size(); ) {
        if (!entities[i]->isAlive()) {
            delete entities[i];
            entities.erase(entities.begin() + i);
        } else {i++;}
    }
}

void Room::addDoor(Door* door) {
    doors.push_back(door);
}

std::string Room::getDescription() const {
    return description;
}

std::vector<Shelf*> Room::getShelves() const
{
    return shelves;
}

std::vector<Entity*> Room::getEntities() const {
    return entities;
}

std::vector<Door*> Room::getDoors() const {
    return doors;
}


