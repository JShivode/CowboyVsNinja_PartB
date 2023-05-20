#ifndef YOUNG_NINJA_HPP
#define YOUNG_NINJA_HPP

#include "Ninja.hpp"
#include <iostream>

namespace ariel {
    class YoungNinja : public Ninja{
        public:
           //YoungNinja(const string& name, const Point& location, int hitPoints, int speed); //Young ninja is also a character
           YoungNinja(const string& name, const Point& location);
           //~YoungNinja();
        
    };
}

#endif
