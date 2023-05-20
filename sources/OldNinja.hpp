#ifndef OLD_NINJA_HPP
#define OLD_NINJA_HPP

#include "Ninja.hpp"
#include <iostream>

namespace ariel {
    class OldNinja : public Ninja{
        
        public:
           //OldNinja(const std::string& name, const Point& location, int hitPoints, int speed); //Old ninja is also a character
           OldNinja(const std::string& name, const Point& location);
           //~OldNinja();
        
    };
}

#endif
