// 📂 Classes and objects

/*
What is Object oriented programming:
Object-oriented programming (OOP) is a computer programming model that organizes software design around data, 
or objects, rather than functions and logic. 

What is a class:
1. Bundle of properties/states/attributes and behaviors.
2. It is a blueprint and also a user defined data type.

What is an object:
1. This is an instance of a class.
2. An object can be defined as a data field that has unique attributes and behaviors.

What is access modifiers:
1. In class, states and behaviors are private by default.
2. They are used to define scope of access.
3. Access modifiers are private, public and protected.
*/

#include<iostream>
using namespace std;

class Student
{
private:
    string gf;
    string bf;

    void chatting(){
        cout<< "Chatting" << endl;
    }
    
public:
    int id;
    string name;
    int age;
    string gender;

    void study(){
        cout<< "Studying" << endl;
    }

    void sleep(){
        cout<< "Sleeping" << endl;
    }

    void bunck(){
        cout<< "Buncking" << endl;
    }    
};

int main(){
    Student s1;
    s1.id = 104;
    s1.name = "Love";
    s1.age = 25;
    s1.gender = "Male";

    Student s2;
    s2.id = 105;
    s2.name = "Lovely";
    s2.age = 24;
    s2.gender = "Female";

    return 0;
}