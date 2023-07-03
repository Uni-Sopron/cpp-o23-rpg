#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <ostream>
#include <string>
#include <vector>
#include <iostream>
#include "Skill.hpp"

class Player;

class Enemy {
        std::string name;
        int level;
        int max_hp;
        int hp;
        int mp;
        int dmg;
        int armor;
        int resistance;
        int exp;
        std::vector<Skill> skills;

    public:
        Enemy(const std::string &name, int level, int max_hp, int hp, int mp, int dmg, int armor, int resistance, int exp, const std::vector<Skill> &skills);
        bool isDead() const;
        std::string getName() const;
        int getHP() const;
        int getMaxHP() const;
        int getArmor() const;
        int getResistance() const;
        int getEXP() const;
        void setHP(int value);
        void setMP(int value);
        void setArmor(int value);
        void setResistance(int value);
        void attack(Player& player) const;
    };

#endif