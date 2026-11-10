#include "Item.h"
#include <string>

Item::Item(const std::string& name) : name(name), used(false) {
}

Item::~Item() = default;

std::string Item::getName() const {
    return name;
}

bool Item::isUsed() const {
    return used;
}




