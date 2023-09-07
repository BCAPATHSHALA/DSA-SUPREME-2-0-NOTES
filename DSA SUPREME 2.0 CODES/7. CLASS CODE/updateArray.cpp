#include<iostream>
using namespace std;

int main(){
    int n=10;
    int arr[10];

    // Taking input from user
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    // Double-up each value of that array
    for (int i = 0; i < n; i++)
    {
        // Updating array's element
        arr[i]=2*arr[i]; 
    }

    // Printing array
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" value at index "<<i<<endl;
    }
    return 0;   
    
}

/*
INPUT: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
OUTPUT: [2, 4, 6, 8, 10, 12, 14, 16, 18, 20]
*/