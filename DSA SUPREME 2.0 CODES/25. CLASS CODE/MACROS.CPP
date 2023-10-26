// 📂 MACROS

/*
What is MACROS:
A MACROS is a piece of code in a program that is replaced by the value of the MACROS.
In compiler, MACROS are  preprocessor directives tool that allow to define constants, functions, or code snippets.
MACROS does not take memory space.

How to defined MACROS:
MACROS is defined by #define directive. 
MACROS definitions need not be terminated by a semi-colon(;)

Working process of MACROS:
Whenever a MACROS name is encountered by the compiler, it replaces the name with the definition of the MACROS before compilation of the code.

Why use of MACROS:
Readability of code and reusability of MACROS definition in cpp program.
*/

#include<iostream>
using namespace std;

#define PI 3.14
#define MAXX(x,y) (x > y ? x : y)

float circleArea(float r){
    return PI * r * r;
}

float circlePerimeter(float r){
    return 2 * PI * r;
}

int getMaxForA(){
    int a = 10;
    int b = 20;
    int c = MAXX(a,b);
    return c;
}

int getMaxForB(){
    int a = 1000;
    int b = 100;
    int c = MAXX(a,b);
    return c;
}

int main(){
    cout<<"Circle Area: "<<circleArea(2.5)<<endl;
    cout<<"Circle Perimeter: "<<circlePerimeter(7.5)<<endl;
    cout<<"Max for A: "<<getMaxForA()<<endl;
    cout<<"Max for B: "<<getMaxForB()<<endl;

    return 0;
}