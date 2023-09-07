// HW 01: Function to find area of circle
#include "bits/stdc++.h"
#include<iostream>
using namespace std;

// Function to print Function to find area of circle
void printAreaOfCircle(int rad){
    float area = 3.14*rad*rad;
    cout<<"Area of circle is "<<area<<endl;
}

/*
TODO: Builtin method: acos() 
Since using acos(0.0) will return the value for Π/2. 
Therefore, to get the value of Π: 
double pi = 2*acos(0.0);
pi=3.141593

TODO: Builtin method: pow(x, y);
*/
void printAreaOfCircle1(int rad){
    double pi=2*acos(0.0);
    double sqr=pow(rad,2);
    double area = pi*sqr;
    cout<<"Area of circle is "<<area;
}

// main function
int main(){

    // function call
    printAreaOfCircle(2);
    printAreaOfCircle1(3);
    return 0;
}

/*
INPUT:  when rad=2
OUTPUT: Area of circle is 12.56

INPUT:  when rad=3
OUTPUT: Area of circle is 28.2743
*/