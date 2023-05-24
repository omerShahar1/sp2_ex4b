#include "Ninja.hpp"
using namespace std;
using namespace ariel;

Ninja::Ninja(string name, Point location, int hitPoints, int speed) : Character(name, location, hitPoints)
{
    this->speed = speed;
}

int Ninja::getSpeed() const
{
    return this->speed;
}

void Ninja::slash(Character* temp)
{
    if (this->isAlive() == false || temp->isAlive() == false)
    {
        throw runtime_error("cant attack dead");
    }
    if (this == temp)
    {
        throw runtime_error("cant attack yourself");
    }
    if((this->distance(temp) <= 1)) // check distance is less or equel to 1
    {
        temp->hit(40);
    }
}

void Ninja::move(Character* temp)
{
    this->location = Point::moveTowards(this->getLocation(), temp->getLocation(), this->speed);
}

string Ninja::print() const
{
    string str = "";
    str += "N(" + this->name + ")";
    if(this->isAlive() == true)
    {
        str += " hitPoints: " + to_string(hitPoints);
    }
    str += " Location: (" + to_string(this->location.getX()) + "," + to_string(this->location.getY()) + ")";
    return str;
}
