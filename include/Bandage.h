#pragma once
#include "Item.h"
class Bandage : public Item{
    private:
        int healAmount;
    public:
        Bandage();
        void use(Entity& target) override;
};

