// Program 02:Minimum and maximum number in an array 
#include<iostream>
#include<limits.h>
using namespace std;

// Minimum in an array
void findMinimumInArray(int arr[],int size){
    int minVal=INT_MAX;

    for(int i=0;i<size;i++){
        if(minVal>arr[i]){
            minVal=arr[i];
        }
    }
    cout<<"Minimum Element: "<<minVal<<endl;
}

// Maximum in an array
void findMaximumInArray(int arr[],int size){
    int maxVal=INT_MIN;

    for(int i=0;i<size;i++){
        if(maxVal<arr[i]){
            maxVal=arr[i];
        }
    }
    cout<<"Maximum Element: "<<maxVal<<endl;
}


int main(){
    int arr[100];
    int size;

    // Entering size of array
    cout<<"Enter size: ";
    cin>>size;

    // Taking input in array
    cout<<"Enter element: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    // Calling method
    findMinimumInArray(arr,size);
    findMaximumInArray(arr,size);
    return 0;
}

/*
OUTPUT:
Enter size: 8
Enter element: 20 4 15 2 6 8 11 25
Minimum Element: 2
Maximum Element: 25

*/