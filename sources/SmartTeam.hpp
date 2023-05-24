#pragma once
#include "Team.hpp"

namespace ariel
{
    class SmartTeam : public Team
    {
    public:
        SmartTeam(Character*);
        ~SmartTeam() = default;
        void attack(Team*) override;
        vector<Character*> find_target(Team*, Team*); // locate the closest characters to attack.
    };
}
