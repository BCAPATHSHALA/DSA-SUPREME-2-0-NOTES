// Program 02: Write a function to return sum of 3 numbers
#include<iostream>
using namespace std;

// Function to return sum of three number
int sum(int num1, int num2, int num3){
    int result = num1+num2+num3;
    return result;
}

// main function
int main(){

    // function call
    int finalResult=sum(2,3,4);
    cout<<"Sum is "<<finalResult<<endl;

    return 0;
}

/*
OUTPUT:
Sum is 9
*/