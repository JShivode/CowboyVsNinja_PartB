#include "Point.hpp"
#include <cmath>
#include <iostream>

using namespace std;
using namespace ariel;

/*Point::Point(): 
   _x(0), _y(0) {

}
*/
Point::Point(double x, double y):
_x(x), _y(y){
//this->_x = x;
//this->_y = y;
}
       
void Point::print(){
   std::cout << "(" << Point::getX() << ", " << Point::getY()<< ")" << std::endl;
}

double Point::distance(const Point& p) const{
        double dx = _x - p._x;
        double dy = _y - p._y;
        return sqrt(pow(dx, 2) + pow(dy, 2));    
}
Point Point::moveTowards(const Point& src, const Point& dest, double distance){
    if (distance < 0) {
        throw std::invalid_argument("Negative distance");
    }

   // Calculate the distance between the source and destination points
    double fromStoD = src.distance(dest);

    // If the distance <= the maximum distance,
    // just return the destination point
    if (fromStoD <= distance) {
        return dest;
    }

    // Otherwise, calculate the direction from the src to the dest point
    double dirX = (dest.getX() - src.getX()) / fromStoD;
    double dirY = (dest.getY() - src.getY()) / fromStoD;

    // Calculate the new point that is "distance" distance away from the source in the
    // direction towards the destination
    double newX = src.getX() + dirX * distance;
    double newY = src.getY() + dirY * distance;

    // Return the new point
    return Point(newX, newY);
}


///////////////

