// 📂 Run time polymorphism

/*
What is run time polymorphism?
It is a late binding and dynamic polymorphism.

late binding or dynamic polymorphism is a binding mechanism that occurs during runtime. 
This means that the method that is called is determined when the program is running, not when it is compiled.

Upcasting Concept: 
Parent *p = new Child();
Upcasting is using the Super/Parent class's reference or pointer to refer to a Sub/Child class's object.

Downcasting Concept:
Child *c = new Parent();
Downcasting is using the Sub/Child class's reference or pointer to refer to a Super/Parent class's object.

Function Overriding:
The process of defining a function with the same name and parameters as a function in a base class, in a derived class.

In short, A feature that allows us to use a function in the child class that is already present in its parent class.

What is virtual keyword:
1. Yeh ek late bindind karne ka tarika hai
2. Yeh ek run time par decision lene tarika hai
3. Yeh ek tarika hai function ko virtual bnane par usko compile time par seriously na le ka

Note: 
1. Virtual function can always be written in parent class.
2. Without virtual early binding, static binding
3. With virtual late binding, dynamic binding

*/

// 📂 No Function Overriding Example
#include<iostream>
using namespace std;

class Boy
{
    public:
        void behave(){
            cout<<"Behaving like a Boy!"<<endl;
        }
};

class Bus: public Boy
{
    public:
        void behave()
        {
            cout<<"In bus Behaving like passenger!"<<endl;
        }
};

class School: public Boy
{
    public:
        void behave()
        {
            cout<<"In School Behaving like student!"<<endl;
        }
};

void behave(Boy *boy){
    boy->behave();
}

int main(){
    // Upcasting
    Boy *boy = new Bus();
    behave(boy);
    boy = new School();
    behave(boy);

    delete boy;
    return 0;
}

/*
OUTPUT:
Behaving like a Boy!
Behaving like a Boy!
*/

// 📂 Function Overriding Example
#include<iostream>
using namespace std;

class Boy
{
    public:
        virtual void behave(){
            cout<<"Behaving like a Boy!"<<endl;
        }
};

class Bus: public Boy
{
    public:
        void behave() override
        {
            cout<<"In bus Behaving like passenger!"<<endl;
        }
};

class School: public Boy
{
    public:
        void behave() override
        {
            cout<<"In School Behaving like student!"<<endl;
        }
};

void behave(Boy *boy){
    boy->behave();
}

int main(){
    // Upcasting
    Boy *boy = new Bus();
    behave(boy);
    boy = new School();
    behave(boy);

    delete boy;
    return 0;
}

/*
OUTPUT:
In bus Behaving like passenger!
In School Behaving like student!
*/

// 📂 Function Overriding Example with no memory leakage
#include<iostream>
using namespace std;

class Boy
{
    public:
        virtual void behave(){
            cout<<"Behaving like a Boy!"<<endl;
        }

        virtual ~Boy(){
            cout<<"Boy DTOR called"<<endl;
        }
};

class Bus: public Boy
{
    public:
        void behave() override
        {
            cout<<"In bus Behaving like passenger!"<<endl;
        }
        
        ~Bus(){
            cout<<"Bus DTOR called"<<endl;
        }
};

class School: public Boy
{
    public:
        void behave() override
        {
            cout<<"In School Behaving like student!"<<endl;
        }
        
        ~School(){
            cout<<"School DTOR called"<<endl;
        }
};

void behave(Boy *boy){
    boy->behave();
}

int main(){
    // Upcasting
    Boy *boy = new Bus();
    behave(boy);
    delete boy;
    
    boy = new School();
    behave(boy);

    delete boy;
    return 0;
}

/*
OUTPUT:
In bus Behaving like passenger!
Bus DTOR called
Boy DTOR called
In School Behaving like student!
School DTOR called
Boy DTOR called
*/