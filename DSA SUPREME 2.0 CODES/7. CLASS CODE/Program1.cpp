// Program 01: Count 0's and 1's in an array
#include<iostream>
using namespace std;

// Counting zero's and one's
void countZeroOne(int arr[],int size){
    int zeroCount=0;
    int oneCount=0;

    for(int i=0;i<size;i++){
        if(arr[i]==0){
            zeroCount++;
        }
        else{
            oneCount++;
        }
    }
    cout<<"Zero Counts: "<<zeroCount<<endl;
    cout<<"One Counts: "<<oneCount<<endl;
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
    countZeroOne(arr,size);
    return 0;
}

/*
OUTPUT:
Enter size: 8
Enter element: 0 1 0 1 0 1 0 1
Zero Counts: 4
One Counts: 4
*/