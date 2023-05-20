#include "Character.hpp"
#include <cmath>
#include <iostream>

using namespace std;
using namespace ariel;

//Character::Character(){}

/*Character::Character(const string name, const Point& position, int hitPoints):
name(name), location(position), hitPoints(hitPoints) {}*/

Character::Character(const string& name, Point location):
name(name), location(location), notAdded(true)
{this->hitPoints = 0;}


//Character::~Character(){}
/*
void Character::setHitPoints(int point) {
     this->hitPoints = point;
}
*/

bool Character::added_character() const{return notAdded;}
void Character::wasAdded(){notAdded=false;}

bool Character::isAlive(){
     return hitPoints > 0; //i.e has more than zero hit points 
     }
          
double Character::distance(Character* other_character){
    return location.distance(other_character->location);
}  

void Character::hit(int hits){
    if(hits<0)
        throw std::invalid_argument("Hit negative value not allowed!");
    hitPoints -= hits ;    
}

string Character::getName() const{
    return name;
}

Point Character::getLocation() const{
    return location;
}

std::string Character::print(){
    bool result = isAlive();
    if (result) {
        std::string print = "Alive, Name: " + name + ", Hit Points: " + std::to_string(hitPoints);
        print += ", Location: (" + std::to_string(location.getX()) + ", " + std::to_string(location.getY()) + ")";
        return print;
    }

    // If the character dies:
    return "Dead, Name: " + name + ", Location: (" + std::to_string(location.getX()) + ", " + std::to_string(location.getY()) + ")";
}


int Character::setHitPoints(int hitP){
   return this->hitPoints = hitP;
}

///////////////

