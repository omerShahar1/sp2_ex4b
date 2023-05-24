#pragma once
#include "Point.hpp"
#include "Ninja.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <vector>
#include <cmath>
namespace ariel
{
    class Team
    {
    private:
        Character* leader;
        vector<Character*> list;

    public:
        Team(Character*);
        virtual ~Team();
        vector<Character*> &getList();
        Character *getLeader();
        void setLeader(Character*);
        void add(Character*);
        virtual void attack(Team*);
        virtual int stillAlive();
        virtual void print();
        Character *find_closest_to_lead(Team*, Character*); // find closest character to leader
    };
}
