// 📂 Getter and setter method
#include<iostream>
using namespace std;

class Student
{
private:
    string gf;
public:
    int age;
    int *id;
    
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