#include "Item.h"
#include <string>

Item::Item(const std::string& name) : name(name), used(false) {
}

Item::~Item() = default;

bool Item::isUsed() const {
    return false;
}




