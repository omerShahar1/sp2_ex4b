#include "Character.hpp"
#include <iostream>

using namespace std;
using namespace ariel;

Character::Character(string name, Point &location, int hitPoints)
{
    this->name = name;
    this->location = location;
    this->hitPoints = hitPoints;
    this->team_flag = false;
}

string Character::getName()
{
    return this->name;
}

Point Character::getLocation() const
{
    return this->location;
}

int Character::getHitPoints()
{
    return this->hitPoints;
}

bool Character::getTeamFlag()
{
    return this->team_flag;
}

void Character::setTeamFlag(bool flag)
{
    this->team_flag = flag;
}

bool Character::isAlive() const
{
    if(this->hitPoints > 0)
    {
        return true;
    }
    return false;
}

double Character::distance(Character* temp)
{
    return this->location.distance(temp->getLocation());
}

void Character::hit(int num)
{
    if(num < 0)
    {
        throw invalid_argument("cant use hit function with negative number");
    }
    this->hitPoints -= num;
}


