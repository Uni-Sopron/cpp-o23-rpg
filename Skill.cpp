#include <ostream>
#include <string>
#include <vector>
#include <iostream>
#include "Skill.hpp"

Skill::Skill(const std::string &skillName, int damage, int manaCost, int healing)
    : name(skillName), dmg(damage), manacost(manaCost), heal(healing) {}

const std::string &Skill::getName() const
{
    return name;
}