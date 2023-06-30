#include "Player.hpp"

Player::Player(int level) : max_hp(100), hp(100),  phy_dmg(100), max_mp(100), mp(100), ma_dmg(100), armor(100), resistance(100), max_exp(100), exp(0){}

bool Player::isDead() const {
    return hp == 0;
}

void Player::heal(int points) {
    hp += points;
    if (hp>max_hp) hp=max_hp;
}

void Player::attack (Player& enemy) const {
    if ( !isDead()   ){
        enemy.hp -= phy_dmg;
        if (enemy.hp < 0) enemy.hp = 0;
    }
}
void Player::levelup() {
    level ++;
    max_hp += 20;
    hp = max_hp;
    max_mp += 20;
    mp = max_mp;
    phy_dmg += 10;
    ma_dmg += 10;
    armor += 10;
    resistance += 10;
    max_exp += 50;
    exp = 0;
}