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
            Enemy enemy("Zombie", 1, 100, 100, 0, 10, 100, 100, 20, std::vector<Skill>());
            return enemy;
        }
        else if (enemyType == "Skeleton")
        {
            Enemy enemy("Skeleton", 1, 50, 50, 0, 20, 100, 100, 20, std::vector<Skill>());
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
            Enemy enemy("Slime", 1, 70, 70, 0, 15, 120, 50, 40, std::vector<Skill>{corrosiveTouch});
            return enemy;
        }
        Enemy Enemy("Error Cube", 1, 1, 1, 0, 1, 1, 1, 1000, std::vector<Skill>());
        return Enemy;
}

void combat(Player& player, Enemy& enemy) {

    bool isDefending = false;

    std::cout << "Combat begins: Player vs " << enemy.getName() << "!\n";

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
            break;
        }
        if (isDefending) {
            player.setArmor(player.getArmor() / 3);
            player.setResistance(player.getResistance() / 3);
            isDefending = false;
        }
    }
}

int main(){
    Player Hero(1);
    Enemy enemy = generateEnemylvl1();
    combat(Hero, enemy);
    return 0;
}