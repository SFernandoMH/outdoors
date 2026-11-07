#pragma once
#include "Entity.h"

class InvisibleCreature : public Entity {
    public:
    InvisibleCreature();
    void attack(Entity &objective) override;

};