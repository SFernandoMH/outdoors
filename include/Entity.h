#pragma once

class Entity {
    protected:
        int hp;
    public:
        Entity(int _hp);
        virtual ~Entity() = default;

        int getHp() const;
        bool isAlive() const;
        virtual void attack(Entity& objective) = 0;
        void takeDamage(int damageAmount);

};
