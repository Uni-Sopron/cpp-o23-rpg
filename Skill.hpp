#ifndef SKILL_HPP
#define SKILL_HPP

class Skill {
        std::string name;
        int dmg;
        int manacost;
        int heal;

    public:
        Skill(const std::string& skillName, int damage, int manaCost, int healing);

    const std::string& getName() const;
};

#endif