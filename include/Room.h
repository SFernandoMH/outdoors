
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
    void applySlam(int force);
    void addShelf(Shelf* shelf);
    void removeitemFromShelf(int index, Item* item) const;
    void addEntity(Entity* entity);
    [[nodiscard]] bool hasLivinEntities() const;
    void addDoor(Door* door);
    [[nodiscard]] std::string getDescription() const;
    [[nodiscard]] std::vector<Shelf*> getShelves() const;
    [[nodiscard]] std::vector<Entity*> getEntities() const;
    [[nodiscard]] std::vector<Door*> getDoors() const;

};

