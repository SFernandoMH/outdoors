#pragma once
#include <string>

class Entity {
    protected:
        std::string name;
        int hp;
        int defense;
        int damagePerAttack;
    public:
        Entity(int _hp);
        virtual ~Entity() = default;

        [[nodiscard]] int getHp() const;
        [[nodiscard]] int getDefense() const;
        void setDefense(int amount);
        std::string getName();
        [[nodiscard]] bool isAlive() const;
        void setDamagePA(int damage);
        [[nodiscard]] int getDamagePA() const;
        virtual void attack(Entity& objective) = 0;
        void takeDamage(int damageAmount);
        void heal(int amount);

};
