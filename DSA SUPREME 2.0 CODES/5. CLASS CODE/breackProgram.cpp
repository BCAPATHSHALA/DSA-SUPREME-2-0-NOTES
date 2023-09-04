#include<iostream>
using namespace std;

int main(){
    for(int i=0; i<5; i++){
        if(i==2){
            break; // It is used to get out of the loop when a particular condition occurs.
        }
        cout<<i<<endl;
    }
    return 0;
}

/*
OUTPUT:
0
1
*/