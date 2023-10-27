// 📂 Perfect encapsulation

/*
What is Perfect encapsulation?
1. All data members are private.
2. All private data members are used through getter and setter methods.
*/

#include<iostream>
using namespace std;

class Student
{
private:
    // Private data member only
    string gf;

public:
    // Setter method
    void setGFName(string gf){
        this->gf = gf;
    }

    // Getter method
    string getGfName(){
        return gf;
    }
};

int main(){
    Student *s1 = new Student();

    // Set gf name through setGFName
    s1->setGFName("Lovely");

    // Get gf name through getGfName
    cout<<s1->getGfName()<<endl;

    delete s1;
    return 0;
}

/*
OUTPUT:
Lovely
*/