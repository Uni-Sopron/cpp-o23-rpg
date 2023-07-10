#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Skill.hpp"
#include <ostream>
#include <iostream>
#include <string>
#include <vector>

class Enemy;

class Player {
        int level;
        int max_hp;
        int hp;
        int phy_dmg;
        int max_mp;
        int mp;
        int ma_dmg;
        int armor;
        int resistance;
        int max_exp;
        int exp;
        std::vector<Skill> skills;

    public:
        Player(int level);
        bool isDead() const;
        void heal(int points);
        void attack(Enemy &enemy) const;
        void levelup();
        int getLevel() const;
        int getHP() const;
        int getPdamage() const;
        int getMP() const;
        int getMaxHP() const;
        int getMaxMP() const;
        int getArmor() const;
        int getResistance() const;
        int getMaxEXP() const;
        int getEXP() const;
        void setHP(int value);
        void setMP(int value);
        void setArmor(int value);
        void setResistance(int value);
        void setEXP(int value);
};

#endif