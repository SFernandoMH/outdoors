#include "InvisibleCreature.h"

InvisibleCreature::InvisibleCreature() : Entity(40) {
    this->damagePerAttack = 50;
    this->name = "InvisibleCreature";
}

void InvisibleCreature::attack(Entity &objective) {
    objective.takeDamage(this->damagePerAttack);
}
