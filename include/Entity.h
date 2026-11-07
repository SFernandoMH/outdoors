#pragma once

class Entity {
    protected:
        int hp;
        int damagePerAttack;
    public:
        Entity(int _hp);
        virtual ~Entity() = default;

        [[nodiscard]] int getHp() const;
        [[nodiscard]] bool isAlive() const;
        void setDamagePA(int damage);
        [[nodiscard]] int getDamagePA() const;
        virtual void attack(Entity& objective) = 0;
        void takeDamage(int damageAmount);
        void heal(int amount);

};
