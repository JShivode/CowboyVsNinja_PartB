#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"
#include <iostream>
#include <string>

namespace ariel {
    class Ninja : public Character{
        protected:
           int speed;

        public:
           //Ninja(const string, const Point&, int hitPoints, int speed); //ninja is also a character
           Ninja(const string, const Point&);

           //receives a pointer to enemy and moves towards the enemy. 
           //The ninja advances a distance equal to its speed.
           void move(Character*);

           //receives a pointer to the enemy. If the ninja is alive and 
           //the enemy is less than 1 meter away, the ninja will deal 
           //31 damage to the enemy. Otherwise, no damage will be done to the enemy.
           void slash(Character*);

           // Getters
           double getSpeed();
           double getHitPoints() const { return hitPoints; }

           //double setHitPoints(int hitP);
      
    };
}

#endif
