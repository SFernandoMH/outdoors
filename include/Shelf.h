#pragma once
#include <vector>
#include "Item.h"

class Shelf {
private:
    bool isStanding;
    int resistance;
    std::vector<Item*> itemsOnIt;
public:
    Shelf(int resistance);
    ~Shelf();

    std::vector<Item*> getItemsOnIt();
    void addItem(Item* item);
    void removeItem(const Item* item);
    void hit(int force);
    void fall();

};

