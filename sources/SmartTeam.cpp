#include "SmartTeam.hpp"
#include <limits>
using namespace std;
using namespace ariel;


SmartTeam::SmartTeam(Character *temp) : Team(temp)
{
}

void SmartTeam::attack(Team *defenders_list)
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

    Character* chosen_one = find_target(this, defenders_list)[1];
    if (!chosen_one)
    {
        return;
    }
    
    for (auto member : this->getList())
    {
        if (defenders_list->stillAlive() == 0 || this->stillAlive() == 0)
        {
            return;
        }
        if (member->isAlive() == false)
        {
            continue;
        }
        if (chosen_one->isAlive() == false)
        {
            chosen_one = find_target(this, defenders_list)[1];
        }

        if (dynamic_cast<Cowboy*>(member) != nullptr)
        {
            if(dynamic_cast<Cowboy*>(member)->hasboolets() == true)
            {
                dynamic_cast<Cowboy*>(member)->shoot(chosen_one); //attck with cowboy
            }
            else
            {
                dynamic_cast<Cowboy*>(member)->reload(); //cowboy reload
            } 
        }

        if (dynamic_cast<Ninja*>(member) != nullptr)
        {
            if(member->distance(chosen_one) <= 1)
            {
                dynamic_cast<Ninja*>(member)->slash(chosen_one); //attck with ninja 
            }
            else
            {
                dynamic_cast<Ninja*>(member)->move(chosen_one); //get closer with ninja
            }
        }
    }
}

vector<Character*> SmartTeam::find_target(Team* attackers, Team* defenders) 
{
    vector<Character*> answer{2};
    double best_distance = numeric_limits<double>::max();

    for (auto attack_member : attackers->getList()) 
    {
        for (auto defend_member : defenders->getList()) 
        {
            if (attack_member->distance(defend_member) < best_distance && attack_member->isAlive() && defend_member->isAlive()) 
            {
                best_distance = attack_member->distance(defend_member);
                answer.at(0) = attack_member;
                answer.at(1) = defend_member;
            }
        }
    }
    return answer;
}