#pragma once
#include "Entity.h"
class Player : public Entity {
    private:
        int damageAmount;
    public:
        Player();
        void attack(Entity& objective) override;

};



