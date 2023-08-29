#include<iostream>
using namespace std;

int main(){
    int number = 2;

    // Check if number is greater than zero
    if(number > 0){
        cout << "Statement inside of if block" << endl;
    }
    // Check if number is equal to zero
    else if (number == 0)
    {
        cout << "Statement inside of else-if block" << endl;
    }
    // Check if number is leass than zero
    else{
        cout << "Statement inside of else block" << endl;
    }
    cout << "Statement outside of if-else-if block" << endl;

    return 0;    
    
}



