#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"
#include <iostream>

namespace ariel {
    class Cowboy : public Character{

        private:
           int numofBalls;

        public:

           Cowboy(const string&, Point location); //cowboy is also a character

           int getNumofBalls() const{return numofBalls;}

          void shoot(Character* enemy);

          bool hasboolets();
          void reload();
          string print() override;





     
    };
}

#endif