// 📂 Shallow vs deep copy

// 📂 SHALLOW COPY CONSTRUCTOR EXAMPLE 
#include<iostream>
using namespace std;

class abc
{
    public:
        int x;
        int *y;

        abc(int _x, int _y):x(_x), y(new int(_y)){}

        // Default dumb copy constructor: it is shallow copy
        abc(const abc &obj){
            x = obj.x;
            y = obj.y;
        }

        void print() const
        {
            printf("PTR X:%p\nX:%d\nPTR Y:%p\nContent of Y:%d\n\n",&x,x,y,*y);
        }
};

int main(){
    abc a(1,2);
    cout<< "Printing a\n";
    a.print();
    
    abc b = a;
    cout<< "Printing b\n";
    b.print();

    // update the value of Y of b
    *b.y = 20;

    cout<< "Printing a\n";
    a.print();

    cout<< "Printing b\n";
    b.print();
    return 0;
}

/*
Printing a
PTR X:0x7ffeadd4bd40
X:1
PTR Y:0x9d2eb0
Content of Y:2

Printing b
PTR X:0x7ffeadd4bd30
X:1
PTR Y:0x9d2eb0
Content of Y:2

Printing a
PTR X:0x7ffeadd4bd40
X:1
PTR Y:0x9d2eb0
Content of Y:20

Printing b
PTR X:0x7ffeadd4bd30
X:1
PTR Y:0x9d2eb0
Content of Y:20
*/

// 📂 DEEP COPY CONSTRUCTOR EXAMPLE
#include<iostream>
using namespace std;

class abc
{
    public:
        int x;
        int *y;

        abc(int _x, int _y):x(_x), y(new int(_y)){}
        
        // Our Smart copy constructor: it is Deep Copy
        abc(const abc &obj){
            x = obj.x;
            y = new int(*obj.y);
        }

        void print() const
        {
            printf("PTR X:%p\nX:%d\nPTR Y:%p\nContent of Y:%d\n\n",&x,x,y,*y);
        }
};

int main(){
    abc a(1,2);
    cout<< "Printing a\n";
    a.print();
    
    abc b = a;
    cout<< "Printing b\n";
    b.print();

    // update the value of Y of b
    *b.y = 20;

    cout<< "Printing a\n";
    a.print();

    cout<< "Printing b\n";
    b.print();
    return 0;
}

/*
Printing a
PTR X:0x7ffe2c9bc220
X:1
PTR Y:0x140beb0
Content of Y:2

Printing b
PTR X:0x7ffe2c9bc210
X:1
PTR Y:0x140c2e0
Content of Y:2

Printing a
PTR X:0x7ffe2c9bc220
X:1
PTR Y:0x140beb0
Content of Y:2

Printing b
PTR X:0x7ffe2c9bc210
X:1
PTR Y:0x140c2e0Content of Y:20
*/

// 📂 SHALLOW COPY CONSTRUCTOR DISADVANTAGE
#include<iostream>
using namespace std;

class abc
{
    public:
        int x;
        int *y;

        abc(int _x, int _y):x(_x), y(new int(_y)){}

        // Default dumb copy constructor: it is Shallow Copy
        abc(const abc &obj){
            x = obj.x;
            y = obj.y;
        }

        void print() const
        {
            printf("PTR X:%p\nX:%d\nPTR Y:%p\nContent of Y:%d\n\n",&x,x,y,*y);
        }
        
        ~abc(){
            cout<<"DTOR Called\n";
            delete y;
        }
};

int main(){
    // abc a(1,2);
    // cout<< "Printing a\n";
    // a.print();
    
    // abc b = a;
    // cout<< "Printing b\n";
    // b.print();
    
    abc *a = new abc(1,2);
    abc b = *a;
    delete a;
    b.print();
    return 0;
}

/*
DTOR Called

PTR X:0x7ffdacc998d0
X:1
PTR Y:0x11e9ed0
Content of Y:0

DTOR Called

free(): double free detected in tcache 2
Aborted
*/