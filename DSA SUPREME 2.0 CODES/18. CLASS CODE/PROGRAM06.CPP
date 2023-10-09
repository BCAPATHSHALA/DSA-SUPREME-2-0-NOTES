// CONCEPT 06: Pass by reference

#include<iostream>
using namespace std;

void solve(int* &p){
    p = p + 1; // p = 104 + 4byte = 108
}

int main(){
    int a = 5;
    int *p = &a;

    cout<<"BEFORE SOLVE FUNCTION"<<endl;
    cout<<"p: "<<p<<endl; // 104
    cout<<"&p: "<<&p<<endl; // 204
    cout<<"*p: "<<*p<<endl; // 5

    solve(p);

    cout<<"AFTER SOLVE FUNCTION"<<endl;
    cout<<"p: "<<p<<endl; // 104
    cout<<"&p: "<<&p<<endl; // 204
    cout<<"*p: "<<*p<<endl; // GARBAGE VALUE : LIKE 4199296

    return 0;
}