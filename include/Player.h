#pragma once
#include "Entity.h"
#include "Item.h"
#include <vector>

class Player : public Entity {
    private:
        int damagePerAttack;
        std::vector<Item> inventory;

    public:
        Player();
         
        void attack(Entity& objective) override;

};



