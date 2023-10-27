// 📂 Destructor in C++
/*
Why we need of destructor?
A destructor is called automatically when the object goes out of scope or is explicitly deleted.

It's not mandatory to write a destructor. In majority of the cases, the compiler takes care of this for you.

However, when a class contains dynamic object, it is mandatory to write a destructor function to release memory 
before the class instance is destroyed. 

This must be done to avoid memory leak.
*/
#include<iostream>
using namespace std;

class Student
{
public:
    int age;

    Student(){
        cout<<"Default CTOR Called"<<endl;
    }
    
    Student(int age){
        this->age = age;
        cout<<age<<endl;
    }
    
    // Default DTOR
    ~Student(){
        cout<<"Student DTOR Called"<<endl;
    }
};

int main(){
    {
        Student s1(25);
    }
    Student s2;
    return 0;
}

/*
OUTPUT:
25
Student DTOR Called
Default CTOR Called
Student DTOR Called
*/



// PROGRAM 02
#include<iostream>
using namespace std;

class Student
{
public:
    int age;
    int *id; 
    
    Student(int age, int id){
        this->age = age;
        this->id = new int(id);
        cout<<age<<" "<<id<<endl;
    }
    
    // Own DTOR
    ~Student(){
        cout<<"Student DTOR Called"<<endl;
        delete id;
    }
};

int main(){
    Student s1(25, 100);
    return 0;
}

/*
OUTPUT:
25 100
Student DTOR Called
*/

// PROGRAM 03
#include<iostream>
using namespace std;

class Student
{
public:
    int age;
    int *id; 
    
    Student(int age, int id){
        this->age = age;
        this->id = new int(id);
        cout<<age<<" "<<id<<endl;
    }
    
    // Own DTOR
    ~Student(){
        cout<<"Student DTOR Called"<<endl;
        delete id;
      	cout<<"Student DTOR Called"<<endl;
    }
};

int main(){
    Student *s1 = new Student(25, 100);
    delete s1;
    return 0;
}

/*
OUTPUT:
25 100
Student DTOR Called
Student DTOR Called
*/