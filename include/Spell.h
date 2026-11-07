#pragma once
#include "Item.h"
class Spell  : public Item{
    private:
        int spellDamage;
    public:
        Spell(const std::string& name, int _spellDamage);
        void use(Entity& target) override;

};

