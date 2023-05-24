#include "Team2.hpp"
using namespace std;
using namespace ariel;

Team2::Team2(Character *temp) : Team(temp)
{
}

void Team2::attack(Team *defenders_list)
{
    if (this->stillAlive() == 0)
    {
        throw invalid_argument("your team is dead");
    }
    if (defenders_list == nullptr)
    {
        throw invalid_argument("the other team is empty");
    }
    if(defenders_list->stillAlive() == 0)
    {
        throw runtime_error("the other team is empty");
    }
    if (defenders_list == this)
    {
        throw invalid_argument("team cant attack itself");
    }

    
    if (this->getLeader()->isAlive() == false)
    {
        this->getLeader()->setTeamFlag(false);
        this->setLeader(find_closest_to_lead(this, this->getLeader())); // find your new team leader
    }
    if (defenders_list->getLeader()->isAlive() == false)
    {
        defenders_list->getLeader()->setTeamFlag(false);
        defenders_list->setLeader(find_closest_to_lead(defenders_list, defenders_list->getLeader())); // find new other team leader
    }
    if (this->getLeader() == nullptr || defenders_list->getLeader() == nullptr)
    {
        return;
    }

    Character *chosen_one = find_closest_to_lead(defenders_list, this->getLeader());
    if (!chosen_one)
    {
        return;
    }
    
    for (auto attack_member : this->getList())
    {
        if (defenders_list->stillAlive() == 0 || this->stillAlive() == 0)
        {
            return;
        }
        if (attack_member->isAlive() == false)
        {
            continue;
        }
        if (chosen_one->isAlive() == false)
        {
            chosen_one = find_closest_to_lead(defenders_list, chosen_one);
        }

        if (dynamic_cast<Cowboy*>(attack_member) != nullptr)
        {
            if(dynamic_cast<Cowboy*>(attack_member)->hasboolets() == true)
            {
                dynamic_cast<Cowboy*>(attack_member)->shoot(chosen_one); //attck with cowboy
            }
            else
            {
                dynamic_cast<Cowboy*>(attack_member)->reload(); //cowboy reload
            } 
        }

        if (dynamic_cast<Ninja*>(attack_member) != nullptr)
        {
            if(attack_member->distance(chosen_one) <= 1)
            {
                dynamic_cast<Ninja*>(attack_member)->slash(chosen_one); //attck with ninja 
            }
            else
            {
                dynamic_cast<Ninja*>(attack_member)->move(chosen_one); //get closer with ninja
            }
        }
    }
}