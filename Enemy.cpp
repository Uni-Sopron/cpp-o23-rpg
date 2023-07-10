#include <ostream>
#include <string>
#include <vector>
#include <iostream>
#include "Enemy.hpp"

        Enemy::Enemy(const std::string &name, int level, int max_hp, int hp, int mp, int dmg, int armor, int resistance, int exp, const std::vector<Skill> &skills)
            : name(name), level(level), max_hp(max_hp), hp(hp), mp(mp), dmg(dmg), armor(armor), resistance(resistance), exp(exp), skills(skills) {}

        bool Enemy::isDead() const
        {
            return hp == 0;
        }
        std::string Enemy::getName() const
        {
            return name;
        }
        int Enemy::getHP() const
        {
            return hp;
        }
        int Enemy::getMaxHP() const
        {
            return max_hp;
        }
        int Enemy::getArmor() const
        {
            return armor;
        }
        int Enemy::getResistance() const
        {
            return resistance;
        }
        int Enemy::getEXP() const
        {
            return exp;
        }
        void Enemy::setHP(int value)
        {
            hp = (value >= 0) ? value : 0;
        }
        void Enemy::setMP(int value)
        {
            mp = (value >= 0) ? value : 0;
        }
        void Enemy::setArmor(int value)
        {
            armor = value;
        }
        void Enemy::setResistance(int value)
        {
            resistance = value;
        }
        void Enemy::attack(Player& player) const {
            int damage;
            damage = (player.getHP() - dmg * (player.getArmor() / 100));
        if (!isDead()) {
            player.setHP(damage);
            std::cout << "You take " << (dmg * (player.getArmor() / 100)) << " damage!\n";
        }
};