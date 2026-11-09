#pragma once
#include "Entity.h"
#include "Item.h"
#include "Shelf.h"
#include <vector>

class Player : public Entity {
    private:
        std::vector<Item*> inventory;
    public:
        size_t MAX_ITEMS = 5;
        Player();
        ~Player() override;

        [[nodiscard]] std::vector<Item*> getInventory() const;
        void addItem(Item* item);
        void useItem(int index);
        void attack(Entity& objective) override;
        void searchInShelf(Shelf* shelf);
        void hitShelf(int force, Shelf* shelf);
};



