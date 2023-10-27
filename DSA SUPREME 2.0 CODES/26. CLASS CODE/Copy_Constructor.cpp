// 📂Copy Constructor in C++

// Program 01
#include<iostream>
using namespace std;

class Student
{
private:
    string gf;

    void chatting(){
        cout<< "Chatting " << endl;
    }
    
public:
    int id;
    string name;
    int age;
    string gender;

    // Default CTOR: assign garbage value
    Student(){
        cout<< "Default ctor called" <<endl;
    }

    // Parameterized CTOR: assign sensible value 
    Student(int _id, string _name, int _age, string _gender, string _gf){
        id = _id;
        name = _name;
        age = _age;
        gender = _gender;
        gf = _gf;
        cout<< "Parameterized ctor called for " << name <<endl;
    }

    void study(){
        cout<< "Studying" << endl;
    }   
};

int main(){
    Student s1(104,"Love",25,"Male","Lovely"); // Source = s1, Programmer added parameterized CTOR
    Student s2; // Destination : s2, Compiler added default CTOR by default
    s2 = s1; // Destination = Source, Now copied s1 into s2 (In this case, copy constructor added by compiler)
    cout<< s2.age <<" "<< s2.name << endl; // Now s2 is accessing states of s1 because s1 ke data ki copy s2 ke pass hai
    return 0;
}


/*
OUTPUT:
Parameterized ctor called for Love
Default ctor called
25 Love
*/

int main(){
    Student s1(104,"Love",25,"Male","Lovely"); // Source = s1, Programmer added parameterized CTOR
    Student s2(s1) // s2 = s1; Destination = Source, Now copied s1 into s2 (In this case, copy constructor added by compiler)
    cout<< s2.age <<" "<< s2.name << endl; // Now s2 is accessing states of s1 because s1 ke data ki copy s2 ke pass hai
    return 0;
}

/*
OUTPUT:
Parameterized ctor called for Love
25 Love
*/

// How to create own copy constructor
#include<iostream>
using namespace std;

class Student
{
private:
    string gf;

    void chatting(){
        cout<< "Chatting " << endl;
    }
    
public:
    int id;
    string name;
    int age;
    string gender;

    // Default CTOR: assign garbage value
    Student(){
        cout<< "Default ctor called" <<endl;
    }

    // Parameterized CTOR: assign sensible value 
    Student(int _id, string _name, int _age, string _gender, string _gf){
        id = _id;
        name = _name;
        age = _age;
        gender = _gender;
        gf = _gf;
        cout<< "Parameterized ctor called for " << name <<endl;
    }

    // Own copy CTOR: the source 's1' is coping into the destination 's2'
    Student(const Student &srcObj){
        // Copy attributes from source object to the current object
        this->id = srcObj.id;
        this->name = srcObj.name;
        this->age = srcObj.age;
        this->gender = srcObj.gender;
        this->gf = srcObj.gf;
        cout<<"Copy CTOR called"<<endl;
    }

    void study(){
        cout<< "Studying" << endl;
    }   
};

int main(){
    Student s1(104,"Love",25,"Male","Lovely");
    Student s2=s1;
    
    cout<< s1.name <<endl; 
    cout<< s2.name <<endl; 
    return 0;
}

/*
Output:
Parameterized ctor called for Love
Copy CTOR called
Love
Love
*/