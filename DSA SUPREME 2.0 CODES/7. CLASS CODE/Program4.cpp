// Program 04:Extreme print an array (Two pointer approach)
#include<iostream>
#include<limits.h>
using namespace std;

// Extreme print an array (Two pointer approach)
void extremeArray(int arr[],int size){
    int start=0;
    int end=size-1;

    while(start<=end){
        if(start==end){
            cout<<arr[start]<<" ";
        }
        else{
            cout<<arr[start]<<" ";
            cout<<arr[end]<<" ";
        }

        start++;
        end--;
    }
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
    extremeArray(arr,size);
    return 0;
}

/*
OUTPUT:
Enter size: 5
Enter element: 10 20 30 40 50
10 50 20 40 30 

Enter size: 6
Enter element: 10 20 30 40 50 60
10 60 20 50 30 40 
*/