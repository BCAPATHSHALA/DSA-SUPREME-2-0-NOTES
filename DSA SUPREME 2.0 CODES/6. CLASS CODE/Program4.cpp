// Program 04: Counting from 1 to N
#include<iostream>
using namespace std;

// Function to print the counting from 1 to N
void printCounting(int num){
    for(int i=1;i<=num;i++){
        cout<<(i)<<" ";
    }
}

// main function
int main(){

    // function call
    printCounting(5);
    return 0;
}

/*
INPUT:  when num=5
OUTPUT: 1 2 3 4 5 

INPUT:  when num=3 
OUTPUT: 1 2 3
*/