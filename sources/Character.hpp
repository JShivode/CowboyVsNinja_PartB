#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Point.hpp"
#include <iostream>
#include <sstream>

namespace ariel{ 

    //This class presents a character
    class Character{
        protected:
           Point location;
           string name;
           int hitPoints;
           bool notAdded;                                 

        public:                                  
            
            //Character();
            //Character(const string , const Point& , int);
            Character(const string , const Point&);
           // virtual ~Character();
            Character(string , const Point& , int);
            virtual ~Character() = default;

            Character(const Character& other) ;
            Character& operator=(const Character& other);
            Character(Character&& other) noexcept;
            Character& operator=(Character&& other) noexcept;


            bool added_character() const;
            void wasAdded();

           // void setHitPoints(int point) const;

            //is the character alive (it has more than zero hit points)
            bool isAlive();

            
            //receives a pointer to another character and returns the distance between the characters
            double distance(Character*);  

            //Subtracts the appropriate amount of hit points from the character. returns nothing
            void hit(int);


           // Getters:
            
            //returns the name of the character.
            string getName() const;

            //Returns the position of the character
            Point getLocation() const;

            //Prints the name of the character, the number of its hit points, and the point where the character is.
            virtual string print();

            virtual int setHitPoints(int hitP);



    };
}
#endif