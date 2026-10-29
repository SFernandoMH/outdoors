#include "Entity.h"

Entity::Entity(int _hp) : hp(_hp) {}

int Entity::getHp() const{
    return this->hp;
}

bool Entity::isAlive() const {
    if (this->hp > 0) {
        return true;
    }
    return false;
}

void Entity::takeDamage(int damageAmount) {
    this->hp -= damageAmount;
    if (this->hp <= 0) {
        this->hp = 0;
    }
}
