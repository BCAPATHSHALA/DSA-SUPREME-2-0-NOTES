#include<iostream>
using namespace std;

// printA function
void printA(){
    cout<<"Inside A"<<endl;
    cout<<"Going back to main"<<endl;
}

// main function
int main(){
    cout<<"Inside main"<<endl;
    // function call
    printA();
    cout<<"Back in main"<<endl;

    return 0;
}

/*
OUTPUT:
Inside main
Inside A
Going back to main
Back in main
*/