#include "Team.hpp"
#include <cmath>
#include <iostream>
#include <limits>

using namespace std;
using namespace ariel;

//Team::Team(){}

Team::Team(Character* leader):
leader(leader){
    this->add(leader);
}

Team::~Team(){
    /*
    for (Character* member : team_members){
        delete member;
    }
    */
   team_members.clear();
          leader = nullptr;
}
          
//static bool chosenLeader(Character* leader){}

bool Team::memberAlreadyAdded(Character* _member) const {
    for (Character* member : team_members) {
        if (member == _member) {
            return true;
        }
    }
    return false;
}
        
void Team::add(Character* new_member){
     if (team_members.size() >= 10) {
        throw std::runtime_error("Group cannot have more than 10 teammates.");
    }
    if(!new_member->added_character()){ //(memberAlreadyAdded(new_member)) {
        throw std::runtime_error("Adding the same character to different teams.");
    }
    team_members.push_back(new_member);
    new_member->wasAdded();             
}


void Team::do_Attacking(Character* victim, Team* enemyTeam) {
     // Process cowboys first :
     //cout<< " pong .."<<endl;
     int k=0;
    for (Character* member : team_members) {
         // I use the 'dynamic_cast' determine the actual type of each Character object in the vector.
        Cowboy* is_cowboy = dynamic_cast<Cowboy*>(member);
        if (is_cowboy && is_cowboy->isAlive() && victim->isAlive()) {
            if (is_cowboy->hasboolets()) {
                is_cowboy->shoot(victim);
                //cout<<"Cowboy #"<<k<<" took a shot."<<endl;
                k++;
                if(!victim->isAlive()){
                                        //enemy soldier already dead.
                                        if(victim == enemyTeam->leader)
                                            {
                                               enemyTeam->setLeader(enemyTeam->chooseNewLeader());
                                            }
                                        choosingTheVictim(enemyTeam);
                                       }
               // cout<< is_cowboy->print() << " shot .."<<victim->print()<<endl;
                                
            } else {
                is_cowboy->reload();
                //cout<<"Cowboy #"<<k<<" reloaded."<<endl;
                k++;
            }
        }
    }
    k=0;
    // then, process ninjas:
    for (Character* member : team_members) {
        Ninja* is_ninja = dynamic_cast<Ninja*>(member);
        if (is_ninja && is_ninja->isAlive() && victim->isAlive()) {
            if (is_ninja->distance(victim) < 1.0) {
                is_ninja->slash(victim);
                //cout<<"Ninja #"<<k<<" slashed."<<endl;
                k++;
            } else {
                is_ninja->move(victim);
                //cout<<"Ninja #"<<k<<" moved."<<endl;
                k++;
            }
        }
    }
}
        
void Team::attack(Team* enemyTeam){
    //cout<<" ping .."<<endl;
    if(!enemyTeam)
       throw std::invalid_argument("Ghosts can't be hunted!(nullptr)");  
    if(enemyTeam->stillAlive()<=0)  
       throw std::runtime_error("Enemy team is dead!"); 
    if(stillAlive()<=0) {
        cout<<"Our team is dead!" <<endl;
       print();
       //throw std::runtime_error("Our team is dead!"); 
       }
    if (!leader->isAlive()) {    
        //check if the leader of the attacking team is dead.
       //choose a new leader closest to the dead leader:
        leader = chooseNewLeader();
        if(!leader || !leader->isAlive())
        {   //if no new leader chosen, war is done.   
           print();     
           //throw std::runtime_error("Our team is dead!");
           cout<<"Our team is dead!" <<endl;
        }
    }
        
     // Choosing the closest enemy to be the victim (corbn):
    Character* corbn = choosingTheVictim(enemyTeam);
    if (!corbn || !corbn->isAlive()) {       
      // throw std::runtime_error("Everybody in enemy team is dead_!");
       // return; // No living members in the enemy team
       cout<<"We won.."<<endl;
       return;
    }

    // Perform actions on the team_members in the attacking Team:
    do_Attacking(corbn, enemyTeam);

    // Check if the previous victim is dead:
    if (!corbn->isAlive()) {
        // Find a new victim
        if(corbn == enemyTeam->leader)
           enemyTeam->setLeader(enemyTeam->chooseNewLeader());
        corbn = choosingTheVictim(enemyTeam);
        if (!corbn) {
        {
        if(enemyTeam->stillAlive()==0 && enemyTeam->leader->getLocation().getX()==-8.0 && enemyTeam->leader->getLocation().getY()==-8.0)
            throw std::runtime_error("Everybody in enemy team is dead!"); 
        cout<<"got them all--"<<endl;
        return;
        }  
            //return; // No living members in the enemy team
        }
    }

    // Recursively continue the attack
   // attack(enemyTeam);
        
    }

Character* Team::chooseNewLeader() const{
    if(!leader->isAlive()){
     Character* newLeader = nullptr; 
     double closest_dist = std::numeric_limits<double>::max();
     for (Character* soldier : team_members) {
            double distance = leader->distance(soldier);
            if (soldier->isAlive() && distance < closest_dist) {
                closest_dist = distance;
                newLeader = soldier;
            }
        }//for
        if(newLeader)
          {
             cout<< " chose a new leader "<<newLeader->print()<<endl;
             return newLeader; 
          }
          else 
            return leader;
    }
    else{
        cout<<"Leader remains the same.."<<endl;  
        return leader;
    }
}

Character* Team::choosingTheVictim(Team* enemyTeam) const{
    //victim will be the living enemy character closest to the leader of the attacking Team//
    
    Character* corbn = nullptr; //still no victim
     double closest_dist = std::numeric_limits<double>::max();
     for (Character* enemy : enemyTeam->team_members) {
            double distance = leader->distance(enemy);
            if (enemy->isAlive() && distance < closest_dist) {
                closest_dist = distance;
                corbn = enemy;                
            }
    }
    cout<< " chose a new victim"<<endl;
    return corbn;   
}
        
int Team::stillAlive() const{
    int count = 0;
    /*
    for (int i = 0; i < team_members.size(); i++){
         if (team_members[i]->isAlive()) {
                count++;
            }
    }
    */
     for (Character* member : team_members) {
        if(member->isAlive()){
            count++;
        }

     }
    return count;
}

        
void Team::print(){
    int k=1;
    cout<<"team leader: #1("<<leader->print()<<") "<<endl;
    k++;
    for (Character* member : team_members) {
            if(member != leader){
            std::cout <<k<<" :"<< member->print() <<" idstance to leader:"<< member->distance(leader) << std::endl;
            k++;
            }
        }
        
}

