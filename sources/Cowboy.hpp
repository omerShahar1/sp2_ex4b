#pragma once
#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {
    private:
        int bullets;

    public:
        Cowboy(string, Point);
        int getBullets() const;
        void shoot(Character*);
        bool hasboolets() const;
        void reload();
        string print() const override;
        
    };
}
