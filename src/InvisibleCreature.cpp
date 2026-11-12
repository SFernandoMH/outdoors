#include "InvisibleCreature.h"

InvisibleCreature::InvisibleCreature() : Entity(300) {
    this->damagePerAttack = 50;
    this->name = "InvisibleCreature";
    this->turn = 0;
}

void InvisibleCreature::attack(Entity &objective) {
    turn++;                                  // atributo contador
    if (turn % 3 == 0) {
        // poder especial: roba vida
        objective.takeDamage(damagePerAttack * 2);
        this->heal(damagePerAttack);
    } else {
        objective.takeDamage(damagePerAttack);
    }
}
