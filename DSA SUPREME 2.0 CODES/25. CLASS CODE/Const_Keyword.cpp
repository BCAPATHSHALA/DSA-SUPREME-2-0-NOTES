// 📂 Const Keyword

/*
What is the const keyword:
Ans: it is like a promise

1️⃣ Why the use of the const keyword:
Reason 1: Simplify the code
✅ The const keyword is used to declare that a variable, function, or object is immutable,i.e., its value cannot be changed after initialization.
✅ E.g., if you declare a variable as const int x = 10; you cannot modify the value of x later in the program.
Any attempt to modify the value will result in a compilation error.

Reason 2: Optimization of the code
✅ The compiler may be able to store const variables in read-only memory, which can result in faster access time.

2️⃣ What is LValue and RValue:
✅ LValue: A variable having a memory address means LValues are modifiable
Example: int x; and int y;

✅ RValue: The variable does not have a memory address means RValues are not modifiable
Example: 5; int *a = &b; where a is alias of b

3️⃣ Const with pointer
Case 1: Pointer is nonconstant and data is constant
Case 2: Pointer is constant and data is nonconstant
Case 3: Both are constant pointers and data

4️⃣ Const with class
✅ You can declare a function as const, which means that it does not modify the state of the object it is called on.
✅ In short, Const function never changes the data member variable
*/
#include<iostream>
using namespace std;

int main(){
    // x is constant 
    const int x = 10;
    // Initialization can be done
    // But we can't reassign a value
    // x = 11; error: assignment of read-only variable 'x'    
    cout<< x <<endl;
    return 0;
}


int main(){   
    // 3️⃣ Const with pointer 
    // Case 1: Pointer is nonconstant and data is constant
    const int *a = new int(2);
    cout<< *a <<endl;
    // *a = 5; error: assignment of read-only location '* a'
    // Cant change the content of pointer
    
    int b = 5;
    a = &b; // Pointer itself can be reassigned
    cout<< *a <<endl;

    return 0;
}

int main(){   
    // 3️⃣ Const with pointer 
    // Case 2: Pointer is constant and data is nonconstant
    int *const a = new int(2);
    cout<< *a <<endl;
    *a = 5; // we can change the content of pointer
    cout<< *a <<endl;
    
    int b = 5;
    // a = &b; error: assignment of read-only variable 'a'
    // Pointer itself cant be reassigned

    return 0;
}

int main(){   
    // 3️⃣ Const with pointer 
    // Case 3: Both are constant pointers and data
    const int *const a = new int(2);
    cout<< *a <<endl;
    // *a = 5; error: assignment of read-only location '*(const int*)a'
    // we cant change the content of pointer
    
    int b = 5;
    // a = &b; error: assignment of read-only variable 'a'
    // Pointer itself cant be reassigned
    
    return 0;
}

// 4️⃣ Const with class
#include<iostream>
using namespace std;
#include<iostream>
using namespace std;

class Abc
{
private:
    int x;
    int *y;
    mutable int z; // (Bad Practice) mutable is used for debugging purpose only

public:
    Abc(){
        x = 0;
        y = new int(0);
        z = 0;
    }

    Abc(int _x, int _y){
        x = _x;
        y = new int(_y);
    }

    int getX() const
    {
        // x = 10; getX() is constant function x variable ki value ko change nhi kar skta hai (Compile Time Error)
        z = 250; // getX() is constant function z variabe ki value ko change kar skta hai kyunki z mutable variable hai
        return x;
    }

    void setX(int _val)
    {
        x = _val;
    }

    int getY() const
    {
        return *y;
    }

    void setY(int _val){
        *y = _val;
    }
    
    int getZ() const
    {
        return z;
    }
};

// --> Jab class object ko as an constant argument pass karte hai to us function me only 
// constant function ko hi use kiya ja skta hai like
// --> printABC takes constant Abc object to yanha constant function use 
// kiye ja skte hai like getX(), getY() and getZ
void printABC(const Abc &obj2){
    cout<< obj2.getX() <<" "<< obj2.getY() <<" "<< obj2.getZ() << endl;
}

int main(){
    Abc obj1;
    cout<< obj1.getX() <<" "<< obj1.getY() <<" "<< obj1.getZ() << endl;
    obj1.setX(10);
    obj1.setY(20);
    cout<< obj1.getX() <<" "<< obj1.getY() <<" "<< obj1.getZ() << endl;
    
    Abc obj2(12, 14);
    cout<< obj2.getX() <<" "<< obj2.getY() <<" "<< obj2.getZ() << endl;
    printABC(obj2);
    
    return 0;
}