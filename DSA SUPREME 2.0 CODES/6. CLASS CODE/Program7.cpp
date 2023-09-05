// Program 07: Sum of all numbers upto 1 to N
#include<iostream>
using namespace std;

// Function to print sum of all numbers upto 1 to N
void printSum(int num){
    int count = 0;
    for(int i=1;i<=num;i++){
        count+=i;
    }
    cout<<"Total sum is "<<count;
}

// main function
int main(){

    // function call
    printSum(5);
    return 0;
}

/*
INPUT:  when num=5
OUTPUT: Total sum is 15
EXPLANATION: 1+2+3+4+5=15

INPUT:  when num=3 
OUTPUT: Total sum is 6
EXPLANATION: 1+2+3=6
*/