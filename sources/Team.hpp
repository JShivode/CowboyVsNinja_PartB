#ifndef TEAM_HPP
#define TEAM_HPP

#include "Character.hpp"
#include "Point.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include <iostream>
#include <vector>
#include <memory>

namespace ariel {
    class Team{

      
      protected:
        // Vector containing pointers to all characters in the Team
         std::vector<Character*> team_members;
         //int size;
        
        // Pointer to the leader of the Team
         Character* leader;         

    public:

     /*
        // Getter for fighters
        const std::vector<Character*>& getTeam_members() const {
        return team_members;
        }

       // Setter for fighters
       void setTeam_members(const std::vector<Character*>& newTeam_members) {
        team_members = newTeam_members;
       }

       // Getter for leader
       Character* getLeader() const {
        return leader;
       }

       // Setter for leader
       void setLeader(Character* newLeader) {
        leader = newLeader;
       }
         */
        

        Team(Character* leader);

        Team(const Team& other);
        Team& operator=(const Team& other);
        Team(Team&& other) noexcept;
        Team& operator=(Team&& other) noexcept;
        virtual ~Team();
  
        
        //takes a pointer to a cowboy or ninja, and adds it to the team.
        void add(Character*);

        // Attacking the enemy group
        virtual void attack(Team* enemyTeam);

        // Returns the number of members of the group left alive
        int stillAlive() const;

        // Prints the details of all fighters in the group
        virtual void print() const;

       virtual void do_Attacking(Character* victim, Team* enemyTeam);
      Character* choosingTheVictim(Team* enemyTeam) const;
      Character* chooseNewLeader() const;
      //static bool chosenLeader(Character* leader);
      bool memberAlreadyAdded(Character* _member) const;
      Character* getLeader(){return this->leader;}
      void setLeader(Character* newLeader){
        if(!this->leader->isAlive()){
        this->leader = newLeader;
        }
        else{
          throw runtime_error("Can't replace a living leader!");
        }
    }
};
}
#endif
