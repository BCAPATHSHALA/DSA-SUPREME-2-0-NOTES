// 📂 Encapsulation

/*
What is encapsulation?
It is a way to implement the abstraction by building of data and method.
In short, encapsulation is nothing special. it's just a class.

Why use of encapsulation?
1. Easy to handle
2. Protect integrity (Security): Control/How class data is modified 
3. Maintainability

Note: Security feature ko samjhne ke liye 'friend keyword' samjhana bahut zaroori hai
*/

#include<iostream>
using namespace std;

class Student
{
private:
    string gf;
public:
    int age;
    int *id;
    
    // Own CTOR
    Student(int age, int id){
        this->age = age;
        this->id = new int(id);
        cout<<age<<" "<<id<<endl;
    }

    // Setter method
    void setGFName(string gf){
        this->gf = gf;
    }

    // Getter method
    string getGfName(){
        // Protect integrity: 
        // Authentication (Who can access the GF name --> Mummy, Papa, and Me)
        return gf;
    }
    
    // Own DTOR
    ~Student(){
        cout<<"Student DTOR Called"<<endl;
        delete id;
    }
};

int main(){
    Student *s1 = new Student(25, 100);

    s1->setGFName("Lovely");
    cout<<s1->getGfName()<<endl;

    delete s1;
    return 0;
}

/*
OUTPUT:
25 100
Lovely
Student DTOR Called
*/