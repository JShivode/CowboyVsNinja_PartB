#include "Ninja.hpp"
#include <cmath>
#include <iostream>

using namespace std;
using namespace ariel;

/*Ninja::Ninja(const string name, const Point& location, int hitPoints, int speed):
  Character(name, location, hitPoints), speed(speed){}
  */

Ninja::Ninja(const string& name, Point location):
Character(name, location)
{}  

void Ninja::move(Character* enemy){
    if (isAlive()) { // first checks if the ninja is alive 
        double dist = distance(enemy); // calculates the distance to the enemy 
        if (dist <= getSpeed()) { // the distance to the enemy is <= the ninja's speed
            setLocation(enemy->getLocation()); // the ninja can directly reach the enemy 
        
        
        } else { // the distance to the enemy is greater than ninja's speed
         double vectX = abs(enemy->getLocation().getX()-getLocation().getX());
         double vectY = abs(enemy->getLocation().getY()-getLocation().getY());
         double length = sqrt(pow(vectX, 2) + pow(vectY, 2));
         double shiftX;                     
         double shiftY; 
         if(getLocation().getX()>enemy->getLocation().getX())
            shiftX = getLocation().getX() - (getSpeed()*vectX)/length;
         else 
            shiftX = getLocation().getX() + (getSpeed()*vectX)/length;
        
         if(getLocation().getY()>enemy->getLocation().getY())
            shiftY = getLocation().getY() - (getSpeed()*vectY)/length;
         else 
            shiftY = getLocation().getY() + (getSpeed()*vectY)/length;
        
        setLocation(Point(shiftX, shiftY));        
        }
    }
}


void Ninja::slash(Character* enemy){
     if(!enemy->isAlive())
     throw std::runtime_error("You cannot kill whos'e already dead!");

     if(!isAlive())
     throw std::runtime_error("The dead cannot kill!");

     if(enemy == this)
     throw std::runtime_error("You cannot kill thy self!");

  if (isAlive() && (distance(enemy) < 1.0)) {
            enemy->hit(40);
        }
}

int Ninja::getSpeed() { return speed; }
void Ninja::setSpeed(int spd){speed=spd;}
/*double Ninja::setHitPoints(int hitP){
    this->hitPoints = hitP;
}*/
