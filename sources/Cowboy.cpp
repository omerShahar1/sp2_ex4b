#include "Cowboy.hpp"
using namespace std;
using namespace ariel;

Cowboy::Cowboy(string name, Point location) : Character(name, location, 110)
{
    this->bullets = 6;
}

int Cowboy::getBullets() const
{
    return this->bullets;
}

void Cowboy::shoot(Character *temp)
{
    if (this->isAlive() == false || temp->isAlive() == false)
    {
        throw runtime_error("cant attack dead");
    }
    if (this == temp)
    {
        throw runtime_error("cant attack yourself");
    }
    if (this->hasboolets() == true)
    {
        temp->hit(10);
        this->bullets -= 1;
    }
}

bool Cowboy::hasboolets() const
{
    if(this->bullets > 0)
    {
        return true;
    }
    return false;
}

void Cowboy::reload()
{
    if (this->isAlive() == false)
    {
        throw runtime_error("dead cant reload");
    }
    this->bullets = 6;
}

string Cowboy::print() const
{
    string str = "";
    str += "C(" + this->name + ")";
    if (this->isAlive() == true)
    {
        str += " hitPoints: " + to_string(this->hitPoints);
    }
    str += " Location: (" + to_string(this->location.getX()) + "," + to_string(this->location.getY()) + ")";
    return str;
}