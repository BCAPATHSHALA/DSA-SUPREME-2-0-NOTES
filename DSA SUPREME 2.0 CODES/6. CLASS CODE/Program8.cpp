// Program 08: Sum of all even numbers upto 1 to N
#include<iostream>
using namespace std;

// Function to print Sum of all even numbers upto 1 to N
void printEvenSum(int num){
    int count = 0;
    for(int i=2;i<=num;i=i+2){
        count+=i;
    }
    cout<<"Total even number's sum is "<<count;
}

// main function
int main(){

    // function call
    printEvenSum(9);
    return 0;
}

/*
INPUT:  when num=10
OUTPUT: Total even number's sum is 30
EXPLANATION: 2+4+6+8+10=30

INPUT:  when num=9
OUTPUT: Total even number's sum is 20
EXPLANATION: 2+4+6+8=20
*/