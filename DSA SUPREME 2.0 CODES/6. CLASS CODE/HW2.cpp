// HW 02: Function to find factorial of a number
#include<iostream>
using namespace std;

// Function to find factorial of a number
void printFactorial(int num){
    int fact = 1;
    for(int i=num;i>0;i--){
        fact*=i;
    }
    cout<<"Factorial is "<<fact;
}

// main function
int main(){

    // function call
    printFactorial(2);
    return 0;
}

/*
INPUT:  when num=0
OUTPUT: Factorial is 1
EXPLANATION: Standard rule that is 0!=1

INPUT:  when num=1
OUTPUT: Factorial is 1
EXPLANATION: 1=1

INPUT:  when num=5
OUTPUT: Factorial is 120
EXPLANATION: 5*4*3*2*1=120
*/