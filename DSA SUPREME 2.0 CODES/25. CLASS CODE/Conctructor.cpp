// 📂 Constructor

/*
What is constructor:
1. A constructor is a special method (Member Function) that initializes a newly created object. 
2. The constructor is automatically called when an object is created.
3. A constructor has the same name as the class name and has not return data type.
4. If we do not create any constructor then compiler add default constructor.
5. It is used to assign the value to class data members.
6. It is used to assign default value to class data members.
7. It is used when we want to assign sensible value to data members.
8. A constructor will be always public.
9. Two types of constructor: default, parameterized, and copy constructor

What is polymorphism(Briefly):
1. Many more form of one things
jaise: Ek ladka
GF  --> BF
SIS --> BRO
Wife --> Husband and ...so on
*/

#include<iostream>
using namespace std;

class Student
{
private:
    string gf;
    string bf;

    void chatting(string name){
        cout<< "Chatting " << name << endl;
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
        chatting(name);
    }

    // Parameterized CTOR: assign sensible value 
    Student(int _id, string _name, string _gender, string _bf){
        id = _id;
        name = _name;
        gender = _gender;
        bf = _bf;
        cout<< "Parameterized ctor called for " << name <<endl;
        chatting(name);
    }

    void study(){
        cout<< "Studying" << endl;
    }   
};

int main(){

    Student s1(104,"Love",25,"Male","Lovely");
    cout<< s1.name << endl;

    Student s2(105,"Lovely","Female","Love");
    cout<< s2.name << endl;

    return 0;
}