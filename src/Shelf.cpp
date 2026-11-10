#include "Shelf.h"
#include <algorithm>
Shelf::Shelf(int resistance) : isStanding(true) , resistance(resistance), fallDamage(60)  {}
Shelf::~Shelf() = default;

int Shelf::getFallDamage() const {
    return this->fallDamage;
}

int Shelf::getResistance() const {
    return this->resistance;
}

std::vector<Item*> Shelf::getItemsOnIt() {
    return this->itemsOnIt;
}

bool Shelf::getisStanding() const  {
    return this->isStanding;
}

// Shelf.h
Item* takeItem(int index);

// Shelf.cpp
Item* Shelf::takeItem(int index) {
    if (index < 0 || index >= itemsOnIt.size()) {
        return nullptr;
    }
    Item* item = itemsOnIt[index];
    itemsOnIt.erase(itemsOnIt.begin() + index);   // solo lo quita, no lo borra
    return item;
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
bool Shelf::hit(int force) {
    if (force >= resistance) {
        isStanding = false;
        return true;
    }
    return false;
}

void Shelf::fall() {
    isStanding = false;
    for (Item* item : this->itemsOnIt) {
        delete item;
    }
    this->itemsOnIt.clear();
}