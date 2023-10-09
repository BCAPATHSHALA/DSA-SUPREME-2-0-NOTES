// CONCEPT 04: Pointer to pointer
#include<iostream>
using namespace std;

int main(){
    int a = 5;
    int *p = &a;
    int **q = &p;
    int ***r = &q;
    int ****s = &r;
    
    cout<<a<<endl; // 5
    cout<<p<<endl; // 104
    cout<<q<<endl; // 204
    cout<<r<<endl; // 304
    cout<<s<<endl; // 404
    cout<<endl;

    cout<<*p<<endl; // 5
    cout<<*q<<endl; // 104
    cout<<*r<<endl; // 204
    cout<<*s<<endl; // 304
    cout<<endl;

    cout<<**q<<endl; // 5
    cout<<**r<<endl; // 104
    cout<<**s<<endl; // 204
    cout<<endl;

    cout<<***r<<endl; // 5
    cout<<***s<<endl; // 104
    cout<<endl;

    cout<<****s<<endl;// 5
    cout<<endl;

    return 0;
}