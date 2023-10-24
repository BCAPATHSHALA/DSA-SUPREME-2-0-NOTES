// 📂 Stack and Heap memory allocation 

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

    Student s1(104,"Love",25,"Male","Lovely"); // Stack Memory Allocation
    cout<< s1.name << endl; // Access Member of Class using "." operator in case of Stack

    Student* s2 = new Student(105,"Lakshay",25,"Male","Lekha"); // Heap Memory Allocation
    cout<< (*s2).name <<endl; // Access Member of Class using "(*s2).member" dereference operator in case of Heap
    cout<< s2->name <<endl; // Access Member of Class using "s2->member" this pointer in case of Heap

    return 0;
}