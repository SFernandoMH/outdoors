#pragma once
#include "Item.h"
#include <string>
class Bandage : public Item{
    private:
        int healAmount;
    public:
        Bandage(const std::string& name);
        [[nodiscard]] bool isUsed() const override;
        void use(Entity& target) override; //Duplica el daño de la entidad
};

