// 📂 2: Can CTOR be made private?

/*
Can CTOR be made private?
ANS: Yes we can make private CTOR implicitly.

Why use of private CTOR?
   We can make private CTOR but can not be called in main() method directly.
   Means, We can't initialize data members directly in main() method.
   Means, We can't create object directly in main() method. 
   But we can make object of private constructor using friend class.

Application of private CTOR:
1. Singleton class
2. Count how many object of private CTOR class are used in whole program.
*/

// Example 01
#include<iostream>
using namespace std;

class Box
{
    private:
        int width;

        // Initialization list constructor
        Box(int w):width(w){}
    
    public:
        
        int getWidth() const
        {
            return width;
        }

        void setWidth(int val) 
        {
            width = val;
        }
};

int main()
{
    // Can't make obj of Box directly
    // Box b(5);
    return 0;
}

// Example 02
#include<iostream>
using namespace std;

class Box
{
    private:
        int width;

        // Initialization list constructor
        Box(int w):width(w){}
    
    public:
        
        int getWidth() const
        {
            return width;
        }

        void setWidth(int val) 
        {
            width = val;
        }

        friend class BoxFactory;
};

class BoxFactory
{
    private:
        int count;
    public:
        Box getABox(int w)
        {
            count++;
            cout<<"How many time used Box model in this program: "<<count<<endl;
            return Box(w);
        }
};

int main()
{
    BoxFactory bFact;
    
    Box b = bFact.getABox(5);
    cout<<b.getWidth()<<endl;
    
    Box c = bFact.getABox(10);
    cout<<c.getWidth()<<endl;
    
    return 0;
}

/*
How many time used Box model in this program: 1
5
How many time used Box model in this program: 2
10
*/