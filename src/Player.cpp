#include "Player.h"
Player::Player() : Entity(100) {
    this->damagePerAttack = 10;
}

Player::~Player() {
    for (Item* item : inventory) {
        delete item;
    }
}

std::vector<Item*> Player::getInventory() const {
    return inventory;
}

void Player::addItem(Item* item) {
    inventory.push_back(item);
}

void Player::useItem(int index) {
    if (index < 0 || index >= inventory.size()) {
        return;                              // índice inválido
    }
    Item* item = inventory[index];
    item->use(*this);

    if (item->isUsed()) {
        delete item;                         // libera el objeto
        inventory.erase(inventory.begin() + index);   // quita el puntero del vector
    }
}

void Player::attack(Entity& objective) {
    objective.takeDamage(this->damagePerAttack);
}

void Player::searchInShelf(Shelf *shelf) {
    std::vector<Item*> itemsOnIt = shelf->getItemsOnIt();
    for ( Item* item : itemsOnIt) {
        inventory.push_back(item);
        shelf->removeItem(item);
    }
}

void Player::hitShelf(int force, Shelf* shelf) {
    shelf->hit(force);

}


