#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"
#include <iostream>
#include <string>

namespace ariel {
    class Ninja : public Character{
        private:
           int speed;

        public:
            int getSpeed();
            void setSpeed(int spd);
           //Ninja(const string, const Point&, int hitPoints, int speed); //ninja is also a character
           Ninja(const string& name, Point location);

           //receives a pointer to enemy and moves towards the enemy. 
           //The ninja advances a distance equal to its speed.
           void move(Character*);

           //receives a pointer to the enemy. If the ninja is alive and 
           //the enemy is less than 1 meter away, the ninja will deal 
           //31 damage to the enemy. Otherwise, no damage will be done to the enemy.
           void slash(Character*);

           // Getters
           
           double getHitPoints() const { return getHitPoints(); }

           //double setHitPoints(int hitP);
      
    };
}

#endif
