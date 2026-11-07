#pragma once
#include "Item.h"
class Spell  : public Item{
    private:
        int spellDamage;
    public:
        Spell();
        void use(Entity& target) override;

};

