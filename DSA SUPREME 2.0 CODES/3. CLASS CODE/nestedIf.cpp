#include<iostream>
using namespace std;

int main(){
    int number = 4;

    if(number == 4){
        if(number >= 10){
            cout << "Statement inside of nested if block" << endl;
        }
        else{
            cout << "Statement inside of nested else block" << endl;
        }
        cout << "Statement inside of if block" << endl;
    }
    else{
        cout << "Statement inside of else block" << endl;
    }
    cout << "Statement outside of if-else and nested if-else block" << endl;
    return 0;
}

