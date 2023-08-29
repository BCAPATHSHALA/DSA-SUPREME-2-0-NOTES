#include<iostream>
using namespace std;

int main(){
    int number = -5;

    // Check if number is greater than zero
    if(number > 0){
        cout << "Statement inside of if block" << endl;
    }
    // Check if number is less than zero
    else{
        cout << "Statement inside of else block" << endl;
    }
    cout << "Statement outside of if-else block" << endl;

    return 0;
}

