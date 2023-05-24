#include "Team.hpp"
using namespace std;
using namespace ariel;

Team::Team(Character *temp)
{
    if (temp->getTeamFlag() == true)
    {
        throw runtime_error("given character is in another team");
    }
    this->leader = temp;
    this->list.clear();
    this->list.push_back(this->leader);
    this->leader->setTeamFlag(true);
}

Team::~Team()
{
    for (size_t i = 0; i < this->list.size(); i++)
    {
        delete list.at(i);
    }
}

vector<Character*> &Team::getList()
{
    return this->list;
}

Character *Team::getLeader()
{
    return this->leader;
}

void Team::setLeader(Character *temp)
{
    this->leader = temp;
}

void Team::add(Character *temp)
{
    if (temp->getTeamFlag())
    {
        throw runtime_error("given character is in another team");
    }
    if (this->list.size() >= 10)
    {
        throw runtime_error("team is full");
    }

    temp->setTeamFlag(true);
    this->list.push_back(temp);
}

void Team::attack(Team *defenders_list)
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

    if (leader->isAlive() == false)
    {
        leader->setTeamFlag(false);
        this->setLeader(find_closest_to_lead(this, leader)); // find your new team leader
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
    
    Character *chosen_one = find_closest_to_lead(defenders_list, this->leader); // choose who to attack
    if (chosen_one == nullptr)
    {
        return;
    }
    for (auto attack_member : this->list)
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
    }

    for (auto attack_member : this->list)
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

int Team::stillAlive()
{
    int counter = 0;
    for (auto member = this->list.rbegin(); member != this->list.rend(); ++member)
    {
        if (*member && ((*member)->getHitPoints() > 0))
        {
            if(dynamic_cast<Cowboy*>(*member) || dynamic_cast<Ninja*>(*member))
            {
                counter++;
            }
        }
    }
    return counter;
}

void Team::print()
{
    for (auto member = this->list.rbegin(); member != this->list.rend(); ++member)
    {
        cout << (*member)->print() << endl;
    }
}

Character *Team::find_closest_to_lead(Team *characters_list, Character *temp)
{
    double distance_from_leader = INFINITY;
    Character *answer = nullptr;

    for (auto member : characters_list->getList())
    {
        if ((member->isAlive()) == true && (member != temp))
        {
            if (temp->distance(member) < distance_from_leader)
            {
                answer = member;
                distance_from_leader = temp->distance(member);
            }
        }
    }
    return answer;
}
