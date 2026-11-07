#pragma once
#include "Entity.h"
#include "Item.h"
#include "Shelf.h"
#include <vector>

class Player : public Entity {
    private:
        std::vector<Item*> inventory;

    public:
        Player();
        ~Player() override;

        void attack(Entity& objective) override;
        void searchInShelf(Shelf* shelf);
        void hitShelf(int force, Shelf* shelf);
};



