#include "Entity.h"

Entity::Entity(int _hp) : name("Default") , hp(_hp),defense(0), damagePerAttack(10) {}

std::string Entity::getName() {
    return this->name;
}

int Entity::getHp() const{
    return this->hp;
}

int Entity::getDefense() const {
    return this->defense;
}

void Entity::setDefense(int amount) {
    this->defense = amount;
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
    int real = damageAmount - defense;
    if (real < 0) real = 0;
    hp -= real;
    if (hp < 0) hp = 0;
}

void Entity::heal(int amount) {
    this->hp += amount;
    if (this->hp > 100) {
        this->hp = 100;
    }
}
