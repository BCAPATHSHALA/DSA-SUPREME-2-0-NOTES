// 📂 Initialization list

/*
What is initialization list:
It is a way to write constructor with new style.

Why use of initialization list:
It helps to re-initialization of a constant variable but not re-assignment
*/

#include<iostream>
using namespace std;

class Abc
{
private:
    int x;
    int *y;
    const int z;

public:
    // CTOR: Old style
    Abc(int _x, int _y, int _z = 0){
        x = _x;
        y = new int(_y);
        z = _z; // const variable ko re-initialized nhi kar skte ho (Compile time error)
    }

    // CTOR: Initialization list style
    Abc(int _x, int _y, int _z = 0): x(_x), y(new int(_y)), z(_z)  {
        cout<< "Initialization list style" <<endl;
        *y = *y + 100;
        z = 100; // const variable ko re-assign nhi kar skte ho (Compile time error)
    }

    int getX() const
    {
        return x;
    }
    int getY() const
    {
        return *y;
    }
    int getZ() const
    {
        return z;
    }
};

void printABC(const Abc &obj){
    cout<< obj.getX() <<" "<< obj.getY() <<" "<< obj.getZ() <<endl;
}

int main(){
    Abc obj1(10, 20, 30);
    printABC(obj1);

    return 0;
}
