// 📂 01: Local and global variable
/*
Global variable: 
1. Written outside of the function
2. Accessible to all function (Same Copy)

Local variable:
1. Written inside function
2. Accessible inside that function scope only.
3. Scoped
*/

#include<iostream>
using namespace std;

int x = 2; // Global variable

void fun(){
    int x = 60;
    cout<< x << endl; // Access local variable to fun()
    ::x = 40; // Udated global variable x by 40
    cout<< ::x << endl; // Access global variable by ::var_name in fun()
}

int main(){

    ::x = 4; // Udated global variable x by 4

    int x = 20; // Local variable to main() function

    cout<< x << endl; // Access local variable to main()
    cout<< ::x << endl; // Access global variable by ::var_name in main()

    {
        int x = 5;
        cout<< x << endl; // Access local variable to scope {}
        cout<< ::x << endl; // Access global variable by ::var_name in scoped{}
    }

    fun();
    return 0;
}