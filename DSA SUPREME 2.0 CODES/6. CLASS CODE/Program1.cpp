// Program 01: Write a function to print sum of 3 numbers
#include<iostream>
using namespace std;

// Function to print sum of three number
void sum(int num1, int num2, int num3){
    int result = num1+num2+num3;
    cout<<"Sum is "<<result<<endl;
}

// main function
int main(){

    // function call
    sum(2,3,4);

    return 0;
}

/*
OUTPUT:
Sum is 9
*/