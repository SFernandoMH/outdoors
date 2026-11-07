#pragma once
#include "Entity.h"

class DarkBeing : public Entity {
    public:
    DarkBeing();
    void attack(Entity &objective) override;



};