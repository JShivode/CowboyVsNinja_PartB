#include "Team2.hpp"
#include <cmath>
#include <iostream>
#include <limits>
using namespace std;
using namespace ariel;

Team2::Team2(Character* leader):
Team(leader)
{}  


void Team2::do_Attacking(Character* victim, Team* enemyTeam) {
    for (Character* member : team_members) {
        if (member->isAlive() && victim->isAlive()) {
            // I use the 'dynamic_cast' determine the actual type of each Character object in the vector.
            Cowboy* is_cowboy = dynamic_cast<Cowboy*>(member);
            Ninja* is_ninja = dynamic_cast<Ninja*>(member);
            if (is_cowboy) {                
                if (is_cowboy->hasboolets()) {
                            is_cowboy->shoot(victim);
                            if(!victim->isAlive()){
                        //already killed enemy soldier.
                               cout<<"Target is toast.."<<endl;
                                   if(victim == enemyTeam->getLeader())
                                            {
                                               enemyTeam->setLeader(enemyTeam->chooseNewLeader());
                                            }
                            choosingTheVictim(enemyTeam);
                           }
                } else {
                    is_cowboy->reload();
                }
            } else if (is_ninja) {
                if (is_ninja->distance(victim) < 1.0) {
                    //cout<<" T2 Ninja attacking.."<<endl;
                    is_ninja->slash(victim);
                    if(!victim->isAlive()){
                        //already killed enemy soldier.
                            cout<<"Target is toast.."<<endl;
                             if(victim == enemyTeam->getLeader())
                                            {
                                               enemyTeam->setLeader(enemyTeam->chooseNewLeader());
                                            }
                            choosingTheVictim(enemyTeam);
                           }
                } else {
                    is_ninja->move(victim);
                }
            }
        }
    }
    if(victim->isAlive())
      cout <<"Target still lives.."<<endl;
}

void Team2::attack(Team* enemyTeam){
    if(!enemyTeam)
       throw std::invalid_argument("Ghosts can't be hunted!(nullptr)"); 
    if(enemyTeam->stillAlive() <= 0)  
       throw std::runtime_error("Enemy team is dead==!");     
    if (!leader->isAlive()) { //if leader of attacking team is dead, replace with closest to the dead leader.
        leader = chooseNewLeader();
        if(!leader || !leader->isAlive())
        {   //if no new leader chosen, war is done.        
           print();
           throw std::runtime_error("Our team2 is dead!");
        }
    }        
     // Choosing the closest enemy to be the victim (corbn):
    Character* corbn = choosingTheVictim(enemyTeam);
    if (!corbn || !corbn->isAlive()) {       
       //throw std::runtime_error("Everybody in enemy team is dead!");
       cout<<"We got them all."<<endl;
       return; // No living members in the enemy team
    }

    // Perform actions on the team_members in the attacking Team:
    do_Attacking(corbn, enemyTeam);

    // Check if the previous victim is dead:
    if (!corbn->isAlive()) {
        // Find a new victim
        corbn = choosingTheVictim(enemyTeam);
        if (!corbn) {
            cout<<"enemy team:"<<endl;    
        enemyTeam->print();
        //throw std::runtime_error("Everybody in enemy team is dead!");    
        cout<<"We have prevailed!"<<endl;
        return;
            //return; // No living members in the enemy team
        }
    }
}
 
    
void Team2::print() const{
    int k=1;
    
    cout<<"Team2, leader: #1("<<leader->print()<<") "<<endl;
     
    k++;
    for (Character* member : team_members) {
            if(member != leader){
            std::cout <<k<<" : " << member->print() << std::endl;
            k++;
            }
        }
   
}
















/*
void Team2::attack(Team* enemyTeam){
     if(!enemyTeam)
       throw std::invalid_argument("Ghosts can't be hunted!");
  if (!leader->isAlive()) {//check if the leader of the attacking team is dead.
       //choose a new leader closest to the dead leader:
        double closest_dist = std::numeric_limits<double>::max(); //max dist can be
        Character* closest_member = nullptr;
        for (Character* member : team_members) {
                double distance = member->distance(leader);
                if (member->isAlive() && distance < closest_dist) {
                    closest_dist = distance;
                    closest_member = member;
                }
                if (!leader) {
                   return; // No living members in the team
                }
            
        }
        leader = closest_member;
    }

    // Choosing the closest enemy to be the victim (corbn):
    Character* corbn = choosingTheVictim(enemyTeam);
    if (!corbn || !corbn->isAlive()) {
        return; // No living members in the enemy team
    }

    // Perform actions on the team_members in the attacking Team:
    do_Attacking(corbn);

    // Check if the previous victim is dead:
    if (!corbn->isAlive()) {
        // Find a new victim
        corbn = choosingTheVictim(enemyTeam);
        if (!corbn) {
            return; // No living members in the enemy team
        }
    }

    // Recursively continue the attack
    //attack(enemyTeam);
        
}
*/
