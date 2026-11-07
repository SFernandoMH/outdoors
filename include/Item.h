#pragma once
#include <string>
#include "Entity.h"

class Item {
    protected:
        std::string name;
        bool used;
    public:
        Item(const std::string& name);
        virtual ~Item();
        [[nodiscard]]virtual bool isUsed() const;
        virtual void use(Entity& target) = 0;
};


