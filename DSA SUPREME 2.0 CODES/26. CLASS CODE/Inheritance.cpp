// 📂 5.2 Inheritance in C++

/*
What is the inheritance in C++:
its a way to implement the abstraction by inheriting the properties and characteristics of the super or derived class.

1. It allows us to create a new class (derived/super/parent class) from an existing class (base/sub/child class).
2. The derived class inherits the features from the base class and can have additional features of its own.

Mode of in heritance: may be public, private, or protected
Private: 
Members of base class are not accessible by derived class. 
It can be only accessible for class itself.

Protected:
Members of base class are accessible for both by derived class and class itself.

Public:
Members of base class are accessible for each derived class and class itself. 
It does not provide any security.
*/

// Example 01
#include<iostream>
using namespace std;

// Base Class Animal
class Animal
{
    public:
        int age;
        string colour;

        void eat(){
            cout<<"Eating"<<endl;
        }

        void sleep(){
            cout<<"Sleeping"<<endl;
        }
};

// Derived Class Dog
class Dog: public Animal
{
    public:
        void bark(){
            cout<<"Barking"<<endl;
        }
};

int main(){
    Dog dogObj;
    dogObj.age = 8;
    dogObj.colour = "Black";
    dogObj.eat();
    dogObj.bark();
    cout<<dogObj.age<<" "<<dogObj.colour<<endl;
    return 0;
}

/*
OUTPUT:
Eating
Barking
8 Black
*/

// 📂 5.2.1 Mode of inheritance table

// Case 01: Private member inherits as private mode
#include<iostream>
using namespace std;

// Base Class Animal
class Animal
{
    private:
        int age;

        void eat(){
            cout<<"Eating"<<endl;
        }
};

// Derived Class Dog
class Dog: private Animal
{
    public:
        void bark(){
            cout<<"Barking"<<endl;
        }
};

int main(){
    Dog dogObj;
    dogObj.bark();
    return 0;
}

/*
Output:
Barking
*/

// Case 02: Private member inherits as protected mode
#include<iostream>
using namespace std;

// Base Class Animal
class Animal
{
    private:
        int age;

        void eat(){
            cout<<"Eating"<<endl;
        }
};

// Derived Class Dog
class Dog: protected Animal
{
    public:
        void bark(){
            cout<<"Barking"<<endl;
        }
};

int main(){
    Dog dogObj;
    dogObj.bark();
    return 0;
}

/*
Output:
Barking
*/

// Case 03: Private member inherits as public mode
#include<iostream>
using namespace std;

// Base Class Animal
class Animal
{
    private:
        int age;

        void eat(){
            cout<<"Eating"<<endl;
        }
};

// Derived Class Dog
class Dog: public Animal
{
    public:
        void bark(){
            cout<<"Barking"<<endl;
        }
};

int main(){
    Dog dogObj;
    dogObj.bark();
    return 0;
}

/*
Output:
Barking
*/

// Case 04: Protected member inherits as private mode
#include<iostream>
using namespace std;

// Base Class Animal
class Animal
{
    protected:
        int age;

        void eat(){
            cout<<"Eating"<<endl;
        }
};

// Derived Class Dog
class Dog: private Animal
{
    public:
        void bark(){
            cout<<"Barking"<<endl;
        }
};

int main(){
    Dog dogObj;
    dogObj.bark();
    return 0;
}

/*
Output:
Barking
*/

// Case 06: Protected member inherits as public mode
#include<iostream>
using namespace std;

// Base Class Animal
class Animal
{
    protected:
        int age;

        void eat(){
            cout<<"Eating"<<endl;
        }
};

// Derived Class Dog
class Dog: public Animal
{
    public:
        void bark(){
            cout<<"Barking"<<endl;
        }
};

int main(){
    Dog dogObj;
    dogObj.bark();
    return 0;
}

/*
Output:
Barking
*/

// Case 07: Public member inherits as private mode
#include<iostream>
using namespace std;

// Base Class Animal
class Animal
{
    public:
        int age;

        void eat(){
            cout<<"Eating"<<endl;
        }
};

// Derived Class Dog
class Dog: private Animal
{
    public:
        void bark(){
            cout<<"Barking"<<endl;
        }
};

int main(){
    Dog dogObj;
    dogObj.bark();
    return 0;
}

/*
Output:
Barking
*/

// Case 08: Public member inherits as protected mode
#include<iostream>
using namespace std;

// Base Class Animal
class Animal
{
    public:
        int age;

        void eat(){
            cout<<"Eating"<<endl;
        }
};

// Derived Class Dog
class Dog: protected Animal
{
    public:
        void bark(){
            cout<<"Barking"<<endl;
        }
};

int main(){
    Dog dogObj;
    dogObj.bark();
    return 0;
}

/*
Output:
Barking
*/


// Case 09: Public member inherits as public mode
#include<iostream>
using namespace std;

// Base Class Animal
class Animal
{
    public:
        int age;

        void eat(){
            cout<<"Eating"<<endl;
        }
};

// Derived Class Dog
class Dog: public Animal
{
    public:
        void bark(){
            cout<<"Barking"<<endl;
        }
};

int main(){
    Dog dogObj;
    dogObj.bark();
    dogObj.age = 8;
    dogObj.eat();
    return 0;
}

/*
Output:
Barking
Eating
*/

// 📂 5.2.2 Type of inheritance

/*
Type 01: Single inheritance
Type 02: Multilevel inheritance
Type 03: Hierarchical inheritance
Type 04: Multiple inheritance
Type 05: Diamond Problem (Hybrid inheritance)
*/

// 📂 5.2.2.1 Single inheritance program
#include<iostream>
using namespace std;

// Base Class A
class A
{
    public:
        int id;

        void funA(){
            cout<<"FunA called"<<endl;
        }
};

// Derived Class B
class B: public A
{
    public:
        void funB(){
            cout<<"FunB called"<<endl;
        }
};

int main(){
    B BObj;
    BObj.funA();
    BObj.id = 8;
    BObj.funB();
    return 0;
}
/*
Output:
FunA called
FunB called
*/

// 📂 5.2.2.2 Multilevel inheritance program
#include<iostream>
using namespace std;

// Base Class A for B
class A
{
    public:
        int id;

        void funA(){
            cout<<"FunA called"<<endl;
        }
};

// Derived Class B for A and Base class B for C
class B: public A
{
    public:
        void funB(){
            cout<<"FunB called"<<endl;
        }
};

// Derived Class C for B
class C: public B
{
    public:
        void funC(){
            cout<<"FunC called"<<endl;
        }
};

int main(){
    B BObj;
    BObj.funA();
    BObj.funB();
    BObj.id = 8;

    C CObj;
    CObj.funA();
    CObj.funB();
    CObj.funC();
    CObj.id = 10;
    return 0;
}
/*
Output:
FunA called
FunB called
FunA called
FunB called
FunC called
*/

// 📂 5.2.2.3 Hierarchical inheritance program
#include<iostream>
using namespace std;

// Base Class A for B, C, and D
class A
{
    public:
        int id;

        void funA(){
            cout<<"FunA called"<<endl;
        }
};

// Derived Class B for A
class B: public A
{
    public:
        void funB(){
            cout<<"FunB called"<<endl;
        }
};

// Derived Class C for A
class C: public A
{
    public:
        void funC(){
            cout<<"FunC called"<<endl;
        }
};

// Derived Class D for A
class D: public A
{
    public:
        void funD(){
            cout<<"FunD called"<<endl;
        }
};

int main(){
    B BObj;
    BObj.funA();
    BObj.funB();
    BObj.id = 8;

    C CObj;
    CObj.funA();
    CObj.funC();
    CObj.id = 10;

    D DObj;
    DObj.funA();
    DObj.funD();
    DObj.id = 12;
    return 0;
}

/*
Output:
FunA called
FunB called
FunA called
FunC called
FunA called
FunD called
*/

// 📂 5.2.2.4 Multiple inheritance program
#include<iostream>
using namespace std;

// Base Class A as Teacher
class Teacher
{
    public:
        void teach(){
            cout<<"Teaching"<<endl;
        }
};

// Base Class B as Researcher
class Researcher
{
    public:
        void research(){
            cout<<"Researching"<<endl;
        }
};

// Derived Class C as Professor
class Professor: public Teacher, public Researcher
{
    public:
        void bore(){
            cout<<"Boring"<<endl;
        }
};

int main(){
    Professor PObje;
    PObje.bore();
    PObje.teach();
    PObje.research();
    return 0;
}

/*
Output:
Boring
Teaching
Researching
*/

// 📂 5.2.2.5 Diamond Problem (Hybrid inheritance)
#include<iostream>
using namespace std;

// Base Class A as Person for Teacher and Researcher
class Person
{
    public:
        void walk(){
            cout<<"Walking"<<endl;
        }
};

// Derived class B as Teacher for Person and  Base Class Teacher for Professor
class Teacher: public Person
{
    public:
        void teach(){
            cout<<"Teaching"<<endl;
        }
};

// Derived class C as Researcher for Person and  Base Class Researcher for Professor
class Researcher: public Person
{
    public:
        void research(){
            cout<<"Researching"<<endl;
        }
};

// Derived Class D as Professor for Teacher and Researcher
class Professor: public Teacher, public Researcher
{
    public:
        void bore(){
            cout<<"Boring"<<endl;
        }
};

int main(){
    Professor PObje;
    PObje.walk(); // error: request for member ‘walk’ is ambiguous
    return 0;
}

/*
Output:
Ambiguous Problem Error: request for member ‘walk’ is ambiguous
*/


// Ambiguous Problem Error Solutions
// 📂 5.2.2.5.1 Sol 01: Scope resolution
// 📂 5.2.2.5.2 Sol 02: Using virtual

// 📂 5.2.2.5.1 Diamond Problem (Hybrid inheritance) with Scope resolution
#include<iostream>
using namespace std;

// Base Class A as Person for Teacher and Researcher
class Person
{
    public:
        void walk(){
            cout<<"Walking"<<endl;
        }
};

// Derived class B as Teacher for Person and  Base Class Teacher for Professor
class Teacher: public Person
{
    public:
        void teach(){
            cout<<"Teaching"<<endl;
        }
};

// Derived class C as Researcher for Person and  Base Class Researcher for Professor
class Researcher: public Person
{
    public:
        void research(){
            cout<<"Researching"<<endl;
        }
};

// Derived Class D as Professor for Teacher and Researcher
class Professor: public Teacher, public Researcher
{
    public:
        void bore(){
            cout<<"Boring"<<endl;
        }
};

int main(){
    Professor PObje;
    // Diamond Problem
    // Solution 1: Scope Resolution
    p.Teacher::walk();
    p.Researcher::walk();
    return 0;
}

/*
Output:
Walking
Walking
*/

// 📂 5.2.2.5.2 Diamond Problem (Hybrid inheritance) with virtual
#include<iostream>
using namespace std;

class Person
{
    public:
        void walk(){
            cout<<"Walking"<<endl;
        }
};

class Teacher: virtual public Person
{
    public:
        void teach(){
            cout<<"Teaching"<<endl;
        }
};

class Researcher: virtual public Person
{
    public:
        void research(){
            cout<<"Researching"<<endl;
        }
};

class Professor: public Teacher, public Researcher
{
    public:
        void bore(){
            cout<<"Boring"<<endl;
        }
};

int main(){
    Professor PObje;
    // Diamond Problem
    // Solution 2: using virtual
    PObje.walk();
    return 0;
}

/*
Output:
Walking
*/