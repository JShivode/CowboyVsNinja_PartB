#include "Cowboy.hpp"
#include "Ninja.hpp"
#include <cmath>
#include <iostream>

using namespace std;
using namespace ariel;

//Cowboy::Cowboy(){}

Cowboy::Cowboy(const string& name, Point location):
  Character(name, location), numofBalls(6)
{this->setHitPoints(110);
 //this->numofBalls = 6;
 } 

//Cowboy::~Cowboy(){}

//int Cowboy::getNumofBalls(){ return 0;}
bool Cowboy::hasboolets(){
  if(numofBalls > 0){
    return true;
  }
  return false;
}

void Cowboy::shoot(Character* enemy){
   if(!enemy->isAlive())
     throw std::runtime_error("Cowboy: You cannot kill whos'e already dead!");

     if(!isAlive())
     throw std::runtime_error("Cowboy: The dead cannot kill!");

     if(enemy == this)
     throw std::runtime_error("Cowboy: You cannot kill thy self!");

  if(isAlive() && hasboolets()){ //hasBullets
    enemy->hit(10);
    numofBalls--;
  }
}


void Cowboy::reload(){
  if(!isAlive())
     throw std::runtime_error("The dead can't reload!");
  numofBalls = 6 ; 
}

std::string Cowboy::print(){
  return Character::print();
}




