// 📂 1. Virtual CTOR Vs Virtual DTOR

/*
What is virtual in C++?
Way to achieve Runtime polymorphism.

How does 'virtual' work?
1. VTables
    1. Formed for every class having at least one virtual function and for its derived classes.
    2. It is static arrays, hence one instance for a class.
    3. VPtr (a hidden member pointer) is added by compiler to classes with virtual and its derived classes.
    4. Depending upon the object type VPtr is bonded to a VTable.

2. VTables are created at compile time.
3. When object of a particular type is created at runtime. 
There will be a VPtr which will be initialised to point to a static VTable at the time of construction.

Can we make virtual ctor?
1. NO.
2. Constructor cannot be virtual, because when constructor of a class is executed there is no virtual table in the memory, 
   means no virtual pointer defined yet. So, the constructor should always be non-virtual.
3. A virtual call is a mechanism to get work done given partial information. In particular, "virtual" allows us to call a 
   function knowing only any interfaces and not the exact type of the object. To create an object you need complete information. 
   In particular, you need to know the exact type of what you want to create. Consequently, a "call to a constructor" cannot be virtual.

Can we make virtual CTOR?
1. YES.
2. It is important to handle proper destruction of Derived class.
*/

#include<iostream>
using namespace std;

class Base
{
    public:
        Base()
        {
            cout<<"Base CTOR Called\n";
        }

        // Non-Virtual DTOR
        ~Base()
        {
            cout<<"Base DTOR Called\n";
        }
};

class Derived: public Base
{
    public:
        Derived()
        {
            cout<<"Derived CTOR Called\n";
        }

        ~Derived()
        {
            cout<<"Derived DTOR Called\n";
        }
};

int main()
{
    Base *b = new Derived();
    delete b;
    return 0;
}

/*
OUTPUT:
Base CTOR Called
Derived CTOR Called
Base DTOR Called
*/

#include<iostream>
using namespace std;

class Base
{
    public:
        Base()
        {
            cout<<"Base CTOR Called\n";
        }

        // Virtual DTOR
        virtual ~Base()
        {
            cout<<"Base DTOR Called\n";
        }
};

class Derived: public Base
{
    public:
        Derived()
        {
            cout<<"Derived CTOR Called\n";
        }

        ~Derived()
        {
            cout<<"Derived DTOR Called\n";
        }
};

int main()
{
    Base *b = new Derived();
    delete b;
    return 0;
}

/*
OUTPUT:
Base CTOR Called
Derived CTOR Called
Derived DTOR Called
Base DTOR Called
*/