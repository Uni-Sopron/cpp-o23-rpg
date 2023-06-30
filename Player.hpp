#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <ostream>

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

    public:

        Player(int level);
        bool isDead() const ;
        void heal(int points);
        void attack (Player& enemy) const;
        void levelup();
};

#endif