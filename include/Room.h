
#pragma once
#include <string>
#include <vector>

#include "Shelf.h"
#include "Entity.h"

class Door;

class Room {
private:
    std::string description;
    std::vector<Shelf*> shelves;
    std::vector<Entity*> entities;
    std::vector<Door*> doors;

public:
    static constexpr int MAX_DOORS = 4;
    static constexpr int MAX_SHELVES = 4;

    Room(const std::string& description);
    ~Room();
    void addShelve(Shelf* shelf);
    void addEntity(Entity* entity);
    void addDoor(Door* door);
    std::vector<Shelf*> getShelves();
    std::vector<Entity*> getEntities();
    std::vector<Door*> getDoors();

};

