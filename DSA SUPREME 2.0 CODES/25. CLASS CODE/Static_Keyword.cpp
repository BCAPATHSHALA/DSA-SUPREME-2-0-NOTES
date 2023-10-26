// 📂 Static Keyword in Class

/*
1️⃣How does class work:
1. In class, this pointer points to an instance of class. but does not point to any class.
2. This pointer is a hidden variable/perimeter of a function in a class.
3. This pointer is used to avoid the conflict between two or more instances/objects of a class.

2️⃣Static data members:
The variable is going to share memory with all of the class instance.

Why use of static data members?
If we want to spreadout the single copy of variable of class to all instance/object of class.

-->(Iska mtlb x and y will never be different for different instance of a class)
-->(Iska mtlb hai x and y belongs to a class but does not belong to a particular instance of a class jabki both are for all instance)

3️⃣Static member function:
*/

// Program 01: How does class work
#include<iostream>
using namespace std;

class Abc{
public:
    int x, y; // Not shared variable for all instance of class now

    void printABC(){
        cout<< this->x <<" "<< this->y <<endl;
        cout<< x <<" "<< y <<endl;
    }

};

int main(){
    Abc obj1 = {1, 2};
    Abc obj2 = {4, 5};
    obj1.printABC();
    obj2.printABC();
    return 0;
}

// Program 02: Static data members
#include<iostream>
using namespace std;

class Abc{
public:
    static int x, y; // Shared variable for all instance of class now

    void printABC(){
        cout<< x <<" "<< y <<endl;
    }

};
// Initialization of static data members x and y of class Abc
int Abc::x;
int Abc::y;

int main(){
    Abc obj1;
    obj1.x = 1;
    obj1.y = 2;
    obj1.printABC();
    
    Abc obj2;
    obj2.x = 4;
    obj2.y = 5;
    obj2.printABC();
    obj1.printABC();
    
    return 0;
}

// Program 03: Static member function:
#include<iostream>
using namespace std;

class Abc{
public:
    static int x, y; // Static data member variable: Shared variable for all instance of class now
    int z; // Non-static data member variable

    static void printABC(){ 
    // Static member method: belongs to a class but does not belong a perticular object.
    // Iska mtlb yeh hai ki pritABC() method ke pass hidden peremeter "this pointer" nhi hoga.
        cout<< x <<" "<< y <<endl;
        cout<< z << endl; // This line occurs compile time error
    }

};

// Initialization of static data members x and y of class Abc
int Abc::x;
int Abc::y;

int main(){
    Abc obj1;
    obj1.x = 1;
    obj1.y = 2;
    Abc::printABC();
    obj1.printABC();
    
    Abc obj2;
    obj2.x = 4;
    obj2.y = 5;
    Abc::printABC();
    obj2.printABC();
    
    return 0;
}