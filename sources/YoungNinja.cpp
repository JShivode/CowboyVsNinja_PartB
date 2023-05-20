#include "YoungNinja.hpp"
#include <cmath>
#include <iostream>

using namespace std;
using namespace ariel;

/*YoungNinja::YoungNinja(const string& name, const Point& location, int hitPoints, int speed):
  Ninja(name, location, 100, 14){}
  */

YoungNinja::YoungNinja(const string& name, const Point& location):
Ninja(name, location){
  this->setHitPoints(100);
  this->speed = 14;
} 

//YoungNinja::~YoungNinja(){}  

