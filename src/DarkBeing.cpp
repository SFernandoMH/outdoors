#include "DarkBeing.h"

DarkBeing::DarkBeing() : Entity(100) {
    this->name = "DarkBeing";
    this->damagePerAttack = 5;
}

void DarkBeing::attack(Entity &objective) {
    objective.takeDamage(this->damagePerAttack);
}
