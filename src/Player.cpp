#include "Player.h"
Player::Player() : Entity(100) {
    this->damageAmount = 10;
}

void Player::attack(Entity& objective) {
    objective.takeDamage(this->damageAmount);
}