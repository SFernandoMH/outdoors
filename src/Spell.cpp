#include "Spell.h"

Spell::Spell(const std::string& name, int _spellDamage) : Item(name) , spellDamage(_spellDamage) {}

void Spell::use(Entity& target) {
    target.setDamagePA(target.getDamagePA()*this->spellDamage);
    used = true;
}