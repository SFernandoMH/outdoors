#pragma once
#include <vector>
#include "Item.h"

class Shelf {
private:
    bool isStanding;
    int resistance;
    int fallDamage;
    std::vector<Item*> itemsOnIt;

public:
    Shelf(int resistance);
    ~Shelf();

    [[nodiscard]] int getFallDamage() const ;
    [[nodiscard]] int getResistance() const;
    std::vector<Item*> getItemsOnIt();
    [[nodiscard]] bool getisStanding() const ;
    void addItem(Item* item);
    void removeItem(const Item* item);
    bool hit(int force);
    void fall();

};

