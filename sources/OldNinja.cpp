#include "OldNinja.hpp"
#include <cmath>
#include <iostream>

using namespace std;
using namespace ariel;

/*OldNinja:: OldNinja(const string& name, const Point& location, int hitPoints, int speed):
  Ninja(name, location, 150, 8){}
  */

OldNinja::OldNinja(const std::string& name, Point location):
Ninja(name, location)
{
this->setHitPoints(150);
this->setSpeed(8);
} 

//OldNinja::~OldNinja(){}  

