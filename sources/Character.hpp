#pragma once
#include <iostream>
#include "Point.hpp"
using namespace std;

namespace ariel
{
    class Character
    {
    protected:
        Point location; // location of the character (x,y)
        int hitPoints; // remaining life
        string name; // character name
        bool team_flag; // "yes" if the character is part of a team. "no" otherwise

    public:
        Character(string, Point&, int); // costructor
        virtual ~Character() = default;
        virtual string getName();
        virtual Point getLocation() const;
        virtual int getHitPoints();
        virtual bool getTeamFlag();
        virtual void setTeamFlag(bool);
        virtual string print() const = 0;
        virtual bool isAlive() const;
        virtual double distance(Character*);
        virtual void hit(int);
        
    };
}
