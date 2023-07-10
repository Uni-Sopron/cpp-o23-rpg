#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "Player.cpp"
#include "Enemy.cpp"
#include "Skill.cpp"


Enemy generateEnemylvl1() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

        std::string enemyType;
        double enemyRoll = dist(gen);

        if (enemyRoll < 0.25)
            enemyType = "Zombie";
        else if (enemyRoll < 0.5)
            enemyType = "Skeleton";
        else if (enemyRoll < 0.75)
            enemyType = "Imp";
        else if (enemyRoll < 1.0)
            enemyType = "Slime";

        if (enemyType == "Zombie")
        {
            Enemy enemy("Zombie", 1, 40, 40, 0, 10, 100, 100, 20, std::vector<Skill>());
            return enemy;
        }
        else if (enemyType == "Skeleton")
        {
            Enemy enemy("Skeleton", 1, 20, 20, 0, 20, 100, 100, 20, std::vector<Skill>());
            return enemy;
        }
        else if (enemyType == "Imp")
        {
            Skill firebolt("Firebolt", 30, 25, 0);
            Enemy enemy("Imp", 1, 30, 30, 50, 10, 100, 100, 34, std::vector<Skill>{firebolt});
            return enemy;
        }
        else if (enemyType == "Slime")
        {
            Skill corrosiveTouch("Corrosive Touch", 20, 0, 0);
            Enemy enemy("Slime", 1, 40, 40, 0, 15, 120, 50, 40, std::vector<Skill>{corrosiveTouch});
            return enemy;
        }
        Enemy Enemy("Error Cube", 1, 1, 1, 0, 1, 1, 1, 1000, std::vector<Skill>());
        return Enemy;
}

void combat(Player& player, Enemy& enemy) {

    bool isDefending = false;

    std::cout << enemy.getName() << " appears! Prepare for combat!\n";

    while (!player.isDead() && !enemy.isDead()) {
        // Player
        std::cout << "Player's turn\n";
        std::cout << "-----------------\n";
        std::cout << "Player HP: " << player.getHP() << "/" << player.getMaxHP() << "\n";
        std::cout << "Player MP: " << player.getMP() << "/" << player.getMaxMP() << "\n";
        std::cout << "Enemy HP: " << enemy.getHP() << "/" << enemy.getMaxHP() << "\n";
        std::cout << "-----------------\n";
        std::cout << "Options:\n";
        std::cout << "1. Attack\n";
        std::cout << "2. Skill (not implemented)\n";
        std::cout << "3. Defend\n";
        std::cout << "-----------------\n";

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                // attack
                player.attack(enemy);
                std::cout << "Player attacks enemy!\n";
                break;
            case 2:
                // skill
                std::cout << "Skill not yet implemented. Please try again.\n";
                continue;
            case 3:
                // defend
                isDefending = true;
                std::cout << "Player is defending.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                continue;
        }
        if (enemy.isDead()) {
            std::cout << "Player defeats the enemy!\n";
            std::cout << "You gain: " << enemy.getEXP() << " experience.\n";
            player.setEXP(player.getEXP() + enemy.getEXP() );
            if (player.getEXP() >= player.getMaxEXP()) {
                player.levelup();
                std::cout << "You are now level " << player.getLevel() << "!\n";
            }
            break;
        }
        if (isDefending) {
            player.setArmor(player.getArmor() * 3);
            player.setResistance(player.getResistance() * 3);
        }
        // Enemy
        std::cout << "Enemy's turn. Enemy attacks player!\n";
        enemy.attack(player);
        // Turn end
        if (player.isDead()) {
            std::cout << "Player is defeated. Game over!\n";
            std::exit(0);
            break;
        }
        if (isDefending) {
            player.setArmor(player.getArmor() / 3);
            player.setResistance(player.getResistance() / 3);
            isDefending = false;
        }
    }
}

std::string generateRoom() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

        std::string roomType;
        double roomRoll = dist(gen);

        if (roomRoll < 0.7)
            roomType = "Combat";
        else if (roomRoll < 0.9)
            roomType = "Heal";
        else if (roomRoll < 1.0)
            roomType = "Treasure";

        return roomType;
}

void lvl1(Player player) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    int roomcount;
    std::string next;
    roomcount = 0;
    Skill deathBolt("Death bolt", 40, 20, 0);
    Enemy boss("Boss enemy Wight Lord", 1, 150, 150, 0, 20, 110, 100, 500, std::vector<Skill>{deathBolt});

    std::cout << "You enter the dungeon. The heavy stone door shuts behind you with a thump. The only way is foward, slay the evil plaguing this land.\n";
    std::cout << "\nThe first room is empty. Ready to move on to the next?(y/n)\n";
    std::cin >> next;
    if (next != "y" && "Y") {
        std::cout << "Game over!\n";
        std::exit(0);
    }
    while (roomcount < 15) {
        std::string roomType;
        double roomRoll = dist(gen);

        if (roomRoll < 0.80)
            roomType = "Combat";
        else if (roomRoll < 0.95)
            roomType = "Heal";
        else if (roomRoll < 1.0)
            roomType = "Treasure";

        if (roomType == "Combat")
        {
            Enemy monster = generateEnemylvl1();
            std::cout << "An enemy waits for you in the room.\n";
            combat(player, monster);
        }
        else if (roomType == "Heal")
        {
            std::cout << "A healing fountain is in the room. Health and mana restored!\n";
            player.setHP(player.getMaxHP());
            player.setMP(player.getMaxMP());
        }
        else if (roomType == "Treasure")
        {
            std::cout << "You find a treasure chest! You obtain 100 EXP.\n";
            player.setEXP(player.getEXP() + 100 );
            if (player.getEXP() >= player.getMaxEXP()) {
                player.levelup();
                std::cout << "You are now level " << player.getLevel() << "!\n";
            }
        }
        std::cout << "Player's status\n";
        std::cout << "-----------------\n";
        std::cout << "Level: " << player.getLevel() << "\n";
        std::cout << "EXP: " << player.getEXP() << "/" << player.getMaxEXP() << "\n";
        std::cout << "HP: " << player.getHP() << "/" << player.getMaxHP() << "\n";
        std::cout << "MP: " << player.getMP() << "/" << player.getMaxMP() << "\n";
        std::cout << "Attack damage: " << player.getPdamage() << "\n";
        std::cout << "Armor: " << player.getArmor() << "%\n";
        std::cout << "-----------------\n";
        std::cout << "Ready to move on to the next room?(y/n)\n";
        std::cin >> next;
        if (next != "y" && "Y") {
            std::cout << "Game over!\n";
            std::exit(0);
        }
        roomcount++;
    }
    std::cout << "You have reached the final room...\n";
    std::cout << "There is a sacrophagus in front of you, eminating a dark miasma...\n";
    std::cout << "The lid breaks open, an undead with a wicked intelligent light shining in it's empty eye sockets rises out, holding a dark steel blade...\n";
    std::cout << "This is it.\n";
    combat(player, boss);
    std::cout << "Congratulations! You are victorious!\n";
    std::cout << "Thank you for playing!\n";
}

int main(){
    Player Hero(1);
    
    lvl1(Hero);

    return 0;
}