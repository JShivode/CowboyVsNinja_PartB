#include "TrainedNinja.hpp"
#include <cmath>
#include <iostream>

using namespace std;
using namespace ariel;

/*TrainedNinja::TrainedNinja(const string& name, const Point& location, int hitPoints, int speed):
  Ninja(name, location, 120, 12){}
  */

TrainedNinja::TrainedNinja(const string& name, Point location):
Ninja(name, location){
  this->setHitPoints(120);
  this->setSpeed(12);
}

//TrainedNinja::~TrainedNinja(){}  

