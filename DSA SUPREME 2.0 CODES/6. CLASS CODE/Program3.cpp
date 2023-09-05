// Program 03: Find maximum of three numbers
#include<iostream>
using namespace std;

// Function to print maximum of three number
void printMaximum(int num1, int num2, int num3){
    if(num1>=num2 && num1>=num3){
        cout<<"Maximum number is "<<num1;
    }
    if(num2>=num1 && num2>=num3){
        cout<<"Maximum number is "<<num2;
    }
    else{
        cout<<"Maximum number is "<<num3;
    }
}

// Builtin method max(num1,num2)
void printMaximum1(int num1, int num2, int num3){
    int ans = max(num1,num2);
    int finalAns = max(ans,num3);
    cout<<"Maximum number is "<<finalAns<<endl;
}

// main function
int main(){

    // function call
    printMaximum1(2,3,4);
    printMaximum(2,4,4);

    return 0;
}

/*
INPUT:  when num1=2, num2=3, num3=4
OUTPUT: Maximum number is 4

INPUT:  when num1=2, num2=4, num3=4
OUTPUT: Maximum number is 4
*/