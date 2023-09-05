// Program 06: Check number is even or odd
#include<iostream>
using namespace std;

// Function to check number is even or odd
bool checkEvenOdd(int num){
    if(num%2==0){
        return true;
    }
    else{
        return false;
    }
}

// main function
int main(){

    // function call
    bool ans=checkEvenOdd(5);

    if(ans==true){
        cout<<"Even number";
    }
    else{
        cout<<"Odd number";
    }
    return 0;
}

/*
INPUT:  when num=5
OUTPUT: Odd number
EXPLANATION: 5 is not perfectly divided by 2

INPUT:  when num=4
OUTPUT: Even number
EXPLANATION: 4 is perfectly divided by 2
*/