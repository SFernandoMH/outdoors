#pragma once
#include <string>
#include "Entity.h"

class Item {
    protected:
        std::string name;
    public:
        Item(std::string name);
        virtual ~Item();
        virtual void use(Entity& target) = 0;
};


