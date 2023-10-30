#if !defined(BIRD_H)
#define BIRD_H

// Starting Coding..........
#include<iostream>
using namespace std;

class Bird
{
    public:
        virtual void eat() = 0;
        virtual void fly() = 0;
        // Classes that inherits this class 
        // has to implement pur virtual function.
};

class Sparrow: public Bird
{
    public:
        void eat()
        {
            cout<<"Sparrow is eating\n";
        }
        void fly()
        {
            cout<<"Sparrow is flying\n";
        }
};

class Eagle: public Bird
{
    public:
        void eat()
        {
            cout<<"Eagle is eating\n";
        }
        void fly()
        {
            cout<<"Eagle is flying\n";
        }
};
// Ending Coding..........

#endif