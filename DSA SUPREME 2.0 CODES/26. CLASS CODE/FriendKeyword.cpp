// 📂 3: Friend Keyword

/*
1. friend is a keyword in C++ that is used to share the information of a class that was previously hidden.
2. For example, the private members of a class are hidden from every other class and cannot be modified except through getters or setters. 
Similarly, the protected members are hidden from all classes other than its children classes.
*/

#include<iostream>
using namespace std;

class A
{
    private:
        int x;    
    public:

        // Initialization list constructor
        A(int x):x(x){}
        
        int getX() const
        {
            return x;
        }

        void setX(int val) 
        {
            x = val;
        }

        // Friend class B of A
        friend class B;

        // Friend function prinX of class A
        friend void printX(const A &a);
};

class B
{
    public:
        void print(const A &a)
        {
            // We can use private data member of class A
            cout<<a.x<<endl;
        }
};

void printX(const A &a)
{
    // We can use private data member of class A
    cout<<a.x<<endl;
}

int main()
{
    A a(5);
    B b;

    b.print(a);

    printX(a);

    return 0;
}