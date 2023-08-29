#include<iostream>
using namespace std;

int main(){
    int number = 10;
    // Check if number is greater than zero
    if(number < 0){
        cout << "Statement inside of if block" << endl;
    }
    cout << "Statement outside of if block" << endl;

    return 0;
}

