#include "InvisibleCreature.h"

InvisibleCreature::InvisibleCreature() : Entity(40) {
    this->damagePerAttack = 50;
}

void InvisibleCreature::attack(Entity &objective) {
    objective.takeDamage(this->damagePerAttack);
}
