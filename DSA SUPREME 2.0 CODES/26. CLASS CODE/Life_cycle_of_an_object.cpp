// 📂 Life cycle of an object
#include<iostream>
using namespace std;

class Student
{
public:
    int age;

    Student(int age){
        this->age = age;
        cout<<age<<endl;
    }
};

int main(){
    Student *s1 = new Student(25);
    return 0;
}

/*
OUTPUT:
25
*/