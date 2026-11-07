#include "Spell.h"

Spell::Spell(const std::string& name, int _spellDamage) : Item(name) , spellDamage(_spellDamage) {}

void Spell::use(Entity& target) {
    this->used = true;
    target.setDamagePA(target.getDamagePA()*this->spellDamage);
}