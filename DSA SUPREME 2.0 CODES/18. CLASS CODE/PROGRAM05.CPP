// CONCEPT 05: Pass by value
#include<iostream>
using namespace std;

void solve(int *p){
    *p = *p + 5; // a = a + 5 = 5 + 5 = 10
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
    cout<<"*p: "<<*p<<endl; // 10

    return 0;
}