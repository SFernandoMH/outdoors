#include "Armor.h"

Armor::Armor(const std::string& name,int defenseAmount): Item(name)  {
    this->defenseAmount = defenseAmount;
}

void Armor::use(Entity& target) {
    target.setDefense(defenseAmount);   // asigna, no suma: no se acumula
    this->used = true;                  // se equipa y sale del inventario
}