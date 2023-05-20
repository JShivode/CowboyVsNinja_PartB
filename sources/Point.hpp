#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
using namespace std;
namespace ariel{
class Point
{
    private:
       double _x, _y;

    public:

      // Getters
      double getX() const { return _x; }
      double getY() const { return _y; }

       //Point(); //default constructor


       //A constructor accepts both coordinates:
       Point(double, double);


      //prints the two coordinates between brackets:
       void print();


       //distance receives a point and calculates the distance between the two points:
       double distance(const Point&) const;


      //moveTowards gets a source point, a destination point and a distance. 
      //The function returns the closest point to the destination point, 
      //- which is at most the given distance from the source point:
       static Point moveTowards(const Point&, const Point&, double);

};
}

#endif