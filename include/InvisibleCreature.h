#pragma once
#include "Entity.h"

class InvisibleCreature : public Entity {
    private:
        int turn;
    public:
        InvisibleCreature();
        void attack(Entity &objective) override;

};