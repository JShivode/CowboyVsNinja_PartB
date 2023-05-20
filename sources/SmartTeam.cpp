#include "SmartTeam.hpp"
#include <cmath>
#include <iostream>

using namespace std;
using namespace ariel;

SmartTeam::SmartTeam(Character* leader):
Team(leader)
{}  

Character* SmartTeam::closestToLeader(Team* enemyTeam){

    Character* closest = nullptr;
    double min = std::numeric_limits<double>::max();
    for (Character* enemy : enemyTeam->getTeamMembers()) {
       double temp = getLeader()->distance(enemy);
       if(temp < min && enemy->isAlive())
       {
          min = temp;
          closest = enemy;
       }
   }//for
   return closest;
}

Character* SmartTeam::closestEnemy(Character* soldier, Team* enemyTeam){

    Character* closest = nullptr;
    double min = std::numeric_limits<double>::max();
    for (Character* enemy : enemyTeam->getTeamMembers()) {
       double temp = soldier->distance(enemy);
       if(temp < min && enemy->isAlive())
       {
          min = temp;
          closest = enemy;
       }
   }//for
   return closest;
}



void SmartTeam::attack(Team* enemyTeam) {
    for (Character* member : getTeamMembers()) {
        Character* closestEnemyToLeader = closestToLeader(enemyTeam);
        if(!closestEnemyToLeader)
          //throw std::runtime_error("Enemy team eliminted.");
          {
            cout<<"Enemy team eliminted."<<endl;
            break;
          }
        if (member->isAlive()) {
            
            Cowboy* is_cowboy = dynamic_cast<Cowboy*>(member);
            Ninja* is_ninja = dynamic_cast<Ninja*>(member);
            if (is_cowboy) {  // all cowboys will shoot closest enemy to leader              
                if (is_cowboy->hasboolets()) {
                            is_cowboy->shoot(closestEnemyToLeader);
                            if(!closestEnemyToLeader->isAlive()){
                        //already killed closest enemy to our leader.
                               
                                   if(closestEnemyToLeader == enemyTeam->getLeader())
                                            {
                                               enemyTeam->setLeader(enemyTeam->chooseNewLeader());
                                            }                            
                           }
                } else {
                    is_cowboy->reload();
                }
            } else if (is_ninja) { // each ninja will attack closest enemy to him.
                Character* enemy = closestEnemy(is_ninja, enemyTeam);
                if(!enemy)
                 // throw std::runtime_error("Enemy team eliminted__!");
                 {
                    cout<<"Enemy team eliminted__!"<<endl;
                    break;
                 }
                if (is_ninja->distance(enemy) < 1.0) {                    
                    is_ninja->slash(enemy);
                    if(!enemy->isAlive()){
                        //already killed closest enemy.
                            
                             if(enemy == enemyTeam->getLeader())
                                            {
                                               enemyTeam->setLeader(enemyTeam->chooseNewLeader());
                                            }                            
                           }
                } else {
                    is_ninja->move(enemy);
                }
            }
        }
    }
}

 
        
void SmartTeam::print() {
   cout<<"________________________________________________"<<endl; 
   cout<<"SmartTeam, Leader: #1"<<getLeader()->print()<<endl;
   int k=2;
   for (Character* member : getTeamMembers()) {
      if(member!=getLeader())
        cout<<"#"<<k<<": "<<member->print()<<endl;
      k++;
   }
   cout<<"________________________________________________"<<endl; 
}
