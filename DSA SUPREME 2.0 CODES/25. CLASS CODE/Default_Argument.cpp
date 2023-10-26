// 📂 Default argument

// Note: Default argument always right most side me likha jata hai

#include<iostream>
using namespace std;

class Abc
{
private:
    int x = 0;
    int *y;

public:
    Abc(int _x, int _y = 0){
        x = _x;
        y = new int(_y);
    }

    int getX() const
    {
        return x;
    }
    int getY() const
    {
        return *y;
    }
};

void printABC(const Abc &obj){
    cout<< obj.getX() <<" "<< obj.getY() <<endl;
}

int main(){
    Abc obj1(12);
    printABC(obj1);
    
    Abc obj2(12, 14);
    printABC(obj2);
    
    return 0;
}