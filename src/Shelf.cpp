#include "Shelf.h"
#include <algorithm>
Shelf::Shelf(int resistance) : isStanding(true) , resistance(resistance)  {}
Shelf::~Shelf() = default;

std::vector<Item*> Shelf::getItemsOnIt() {
    return this->itemsOnIt;
}

void Shelf::addItem(Item* item) {
    this->itemsOnIt.push_back(item);
}

void Shelf::removeItem(const Item* item) {
    auto it = std::find(this->itemsOnIt.begin(), this->itemsOnIt.end(), item);
    if (it != this->itemsOnIt.end()) {
        this->itemsOnIt.erase(it);// Por que solo recibe la posicion ??
    }

}
void Shelf::hit(int force) {
    if (force >= resistance) {
        isStanding = false;
    }
}

void Shelf::fall() {
    isStanding = false;
    for (Item* item : this->itemsOnIt) {
        delete item;
    }
    this->itemsOnIt.clear();
}