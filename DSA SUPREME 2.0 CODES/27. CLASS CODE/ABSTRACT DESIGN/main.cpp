#include<iostream>
#include "bird.h" // Own header file
using namespace std;

void birdDoesSomething(Bird *&bird)
{
    bird->eat();
    bird->fly();
}

int main()
{
    Bird *bird = new Eagle();
    birdDoesSomething(bird);
    return 0;
}

/*
OUTPUT:
Eagle is eating
Eagle is flying
*/