// 📂 this pointer

/*
What is this pointer:
1. this pointer is a private data member in class
2. this pointer points to current object
3. this pointer added by compiler privately

Why use of this pointer:
whenever a local variable or parameter has the same name as a member variable, 
the 'this' pointer can be used to explicitly refer to the member variable.
*/

#include<iostream>
using namespace std;

class Student
{
private:
    string gf;
    // Student *this;

public:
    int id;
    string name;
    int age;
    string gender;

    // Parameterized CTOR: assign sensible value 
    Student(int id, string name, int age, string gender, string gf){
        this->id = id;
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->gf = gf;
        cout<< "Parameterized ctor called for " << name <<endl;
    } 
};

int main(){

    Student s1(104,"Love",25,"Male","Lovely");
    cout<< s1.name << endl;

    return 0;
}