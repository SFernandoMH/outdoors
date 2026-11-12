#pragma once
#include "Item.h"

class Armor :public Item {
    private:
        int defenseAmount;
    public:
        Armor(const std::string& name ,int defenseAmount);
        void use(Entity &target) override;
};