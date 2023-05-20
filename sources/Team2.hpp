#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Character.hpp"
#include "Point.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include"Team.hpp"
#include <iostream>
#include <vector>
#include <memory>

/*The same as Team, but the transition to the characters will be
 according to the order of addition without distinguishing cowboys or ninjas*/

namespace ariel {
    class Team2 : public Team{

    public:
        
         Team2(Character* leader);

         //~Team2();
        
        void attack(Team* enemyTeam) override;
        void do_Attacking(Character* victim, Team* enemyTeam) override;
       
        void print() const override;

       
    };
}

#endif
