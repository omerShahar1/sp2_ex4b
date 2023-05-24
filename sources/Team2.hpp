#pragma once
#include "Team.hpp"

namespace ariel
{
    class Team2 : public Team
    {
    public:
        Team2(Character*);
        ~Team2() = default;
        void attack(Team*) override;
    };
}
