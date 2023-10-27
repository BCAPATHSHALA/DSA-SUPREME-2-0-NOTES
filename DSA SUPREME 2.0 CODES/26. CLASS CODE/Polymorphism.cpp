// 📂 5.3 Polymorphism

/*
What is polymorphism: 
This is a way of the abstraction. In this case, we found many forms of one things.

Types of polymorphism:
1. Compile time: it is a static polymorphism
    (I.) Function overloading: 
    Two or more function can have same name but different parameters.

    Require each redefinition of a function to use a different function signature that is:
    a.) Different types of parameters
    b.) Or sequence of parameters
    c.) Or number of parameters
    
    (II.) Constructor overloading: its a part of function overloading
    (III.) Operator overloading

2. Run time: it is a dynamic polymorphism
    (I.) Function overriding


Which operators overload in cpp?
Here are some operators that can be overloaded in C++:
1. Unary arithmetic operators: +, -, ++, --
2. Binary arithmetic operators: +, -, *, /, %
3. Assignment operators: =, +=, *=, /=, -=, %=
4. Bitwise operators: &, |, <<, >>, ~, ^
5. Function call operator: ()

You cannot overload the following operators in C++
1. sizeof, 
2. . (member selection)
3. ?: (conditional)
4. :: (scope resolution)
5. new
6. delete
*/


//📂 (I.) Function Overloading Program
#include <iostream>
using namespace std;

// First fn
int add(int a, int b)
{
    return a + b;
}

// Second fn: different types of parameters from first
double add(double a, double b)
{
    return a + b;
}

// Third fn: different number of parameters from first
int add(int a, int b, int c)
{
    return a + b + c;
}

int main(){
    cout<< add(5, 10) << endl;
    cout<< add(5.5, 10.5) << endl;
    cout<< add(5,10, 15) << endl;

    return 0;
}

/*
OUTPUT:
15
16
30
*/

//📂 (II.) Operator Overloading Program
#include <iostream>
using namespace std;

class Vector
{
    private:
        int x, y;

    public:
        // Init list CTOR
        Vector(int x, int y): x(x), y(y){}

        // Simple member fn
        void display(){
            cout<<"x: "<<x<<" y: "<<y<<endl;
        }

        // Operator overlading(+)
        void operator+(const Vector &src)
        {
            // this would point to v1
            // src would point to v2
            this->x += src.x;
            this->y += src.y;
        }
};

int main(){
    Vector v1(2, 3);
    Vector v2(4, 5);
    
    cout<<"Before operator overloading"<<endl;
    v1.display();
    v2.display();
    
    cout<<"After operator overloading"<<endl;
    v1 + v2;
    // Additional ans (v1+v2) should be stored in v1
    v1.display();
    v2.display();

    return 0;
}

/*
OUTPUT:
Before operator overloading
x: 2 y: 3
x: 4 y: 5
After operator overloading
x: 6 y: 8
x: 4 y: 5
*/

//📂 (II.) Operator Overloading Program
#include <iostream>
using namespace std;

class Vector
{
    private:
        int x, y;

    public:
        // Init list CTOR
        Vector(int x, int y): x(x), y(y){}

        // Simple member fn
        void display(){
            cout<<"x: "<<x<<" y: "<<y<<endl;
        }

        // Operator overlading(-)
        void operator-(const Vector &src)
        {
            // this would point to v2
            // src would point to v1
            this->x -= src.x;
            this->y -= src.y;
        }
};

int main(){
    Vector v1(2, 3);
    Vector v2(4, 5);
    
    cout<<"Before operator overloading"<<endl;
    v1.display();
    v2.display();
    
    cout<<"After operator overloading"<<endl;
    v2 - v1;
    // Subtraction ans (v2-v1) should be stored in v2
    v1.display();
    v2.display();

    return 0;
}

/*
OUTPUT:
Before operator overloading
x: 2 y: 3
x: 4 y: 5
After operator overloading
x: 2 y: 3
x: 2 y: 2
*/