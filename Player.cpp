#include "Player.hpp"
#include "Enemy.hpp"
#include <iostream>
#include <string>
#include <vector>

Skill Fireblast("Fireblast", 25, 20, 0);
Player::Player(int level)
    : level(level), max_hp(100), hp(100), phy_dmg(10), max_mp(100), mp(100),
      ma_dmg(10), armor(100), resistance(100), max_exp(100),
      exp(0), skills()
{
    skills.push_back(Fireblast);
}
bool Player::isDead() const {
    return hp == 0;
}

void Player::heal(int points) {
    hp += points;
    if (hp>max_hp) hp=max_hp;
}

void Player::attack(Enemy& enemy) const {
    if (!isDead()) {
        enemy.setHP(enemy.getHP() - phy_dmg * (enemy.getArmor() / 100));
    }
}
void Player::levelup() {
    do {
    std::cout << "You gained a level!\n";
    level ++;
    max_hp += 20;
    hp = max_hp;
    max_mp += 20;
    mp = max_mp;
    phy_dmg += 10;
    ma_dmg += 10;
    armor += 10;
    resistance += 10;
    exp = exp - max_exp;
    max_exp += 50; } while (exp >= max_exp);
}
int Player::getLevel() const
{
    return level;
}
int Player::getHP() const
{
    return hp;
}
int Player::getMP() const
{
    return mp;
}
int Player::getMaxHP() const
{
    return max_hp;
}
int Player::getMaxMP() const
{
    return max_mp;
}
int Player::getArmor() const
{
    return armor;
}
int Player::getResistance() const
{
    return resistance;
}
int Player::getMaxEXP() const
{
    return max_exp;
}
int Player::getEXP() const
{
    return exp;
}
void Player::setHP(int value)
{
    hp = (value >= 0) ? value : 0;
}
void Player::setMP(int value)
{
    mp = (value >= 0) ? value : 0;
}
void Player::setArmor(int value)
{
    armor = value;
}
void Player::setResistance(int value)
{
    resistance = value;
}
void Player::setEXP(int value)
{
    exp = (value >= 0) ? value : 0;
}