#include "Player.h"
Player::Player() : Entity(100) {
    this->damagePerAttack = 10;
}

Player::~Player() {
    for (Item* item : inventory) {
        delete item;
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


