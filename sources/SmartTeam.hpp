/*The same for the Team. The transition of the characters will be
  according to your choice in whatever order you see fit. 
  It is allowed and desirable at this stage to "ask" the other team
  about the positions of their forces and their status as well as 
  take into account the situation of the attacking team in order to maximize damage.
***********
When this assignment will be tested in the laboratory, students with a smart, 
creative, efficient and effective algorithm will win bonus points 
(it is impossible to exceed the maximum 10 and you can still get a 10 
with a simple algorithm, but a good algorithm will force mistakes elsewhere)*/

#ifndef SMART_TEAM_HPP
#define SMART_TEAM_HPP

#include "Character.hpp"
#include "Point.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include"Team.hpp"
#include"Team2.hpp"
#include <iostream>
#include <vector>
#include <memory>


namespace ariel {
    class SmartTeam : public Team{

    public:
        
         SmartTeam(Character* leader);
        
        void attack(Team* enemyTeam) override;

        void print() override;

        Character* closestToLeader(Team* enemyTeam);

        Character* closestEnemy(Character* soldier, Team* enemyTeam);

       
    };
}

#endif
