#pragma once
#include "Character.hpp"

namespace ariel
{
    class Ninja : public Character
    {
    protected:
        int speed;

    public:
        Ninja(string, Point, int, int); // constructor
        int getSpeed() const;
        void move(Character*); // same as the point moveTowards but the number is the ninja speed
        void slash(Character*);
        string print() const override;
    };
}
