// Program 05: Check prime or not prime number
#include<iostream>
using namespace std;

// Function to check prime or not prime number
bool checkPrime(int num){
    if(num<=1){
        return false;
    }
    for(int i=2;i<num;i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}

// main function
int main(){

    // function call
    bool ans=checkPrime(5);

    if(ans==true){
        cout<<"Prime number";
    }
    else{
        cout<<"Not prime number";
    }
    return 0;
}

/*
INPUT:  when num=5
OUTPUT: Prime number
EXPLANATION: 5 is perfectly divided by 1 and itself

INPUT:  when num=1
OUTPUT: Not prime number
EXPLANATION: prime number start from 2
*/