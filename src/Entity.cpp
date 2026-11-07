#include "Entity.h"

Entity::Entity(int _hp) : hp(_hp), damagePerAttack(10) {}

int Entity::getHp() const{
    return this->hp;
}


bool Entity::isAlive() const {
    if (this->hp > 0) {
        return true;
    }
    return false;
}

void Entity::setDamagePA(int damage) {
    this->damagePerAttack = damage;
}

int Entity::getDamagePA() const {
    return this->damagePerAttack;
}

void Entity::takeDamage(int damageAmount) {
    this->hp -= damageAmount;
    if (this->hp <= 0) {
        this->hp = 0;
    }
}

void Entity::heal(int amount) {
    this->hp += amount;
    if (this->hp > 100) {
        this->hp = 100;
    }
}
