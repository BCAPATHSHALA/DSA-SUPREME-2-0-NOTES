// Program 01: Moving All Negative Number to the Left Side of an Array
#include<iostream>
using namespace std;

// Way 01: Moving All Negative Number to the Left Side of an Array
void shiftNegativeOneSide(int arr[],int size){
    int j=0;
    int i=0;
    while(i<size){
        if(arr[i]>0){
            i++;
        }else{
            swap(arr[i],arr[j]);
            i++;
            j++;
        }
    }
}
// Time Complexity: O(N)

// Way 02: Moving All Negative Number to the Left Side of an Array
void shiftNegativeOneSide1(int arr[],int size){
    int start=0;
    int end=size-1;
    while(start<end){
        if(arr[start]<0){
            start++;
        }
        else if(arr[end]>0){
            end--;
        }
        else if(arr[start]>0 && arr[end]<0){
            swap(arr[start],arr[end]);
            start++;
            end++;
        }
    }
}
// Time Complexity: O(N)

// Print array
void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

// MAIN METHOD
int main(){
    int arr[]={23,-7,12,-10,-11,40,-60};
    int size=7;

    shiftNegativeOneSide(arr,size);
    printArray(arr,size);

    return 0;
}

/*
EXAMPLE 01
INPUT: [23,-7,12,-10,-11,40,60]
OUTPUT: -7 -10 -11 23 12 40 60

EXAMPLE 02
INPUT: [-23,-7,-12,-10,-11,-40,-60]
OUTPUT: -23 -7 -12 -10 -11 -40 -60 

EXAMPLE 03
INPUT: [23,7,12,10,11,40,60]
OUTPUT: 23 7 12 10 11 40 60 

EXAMPLE 04
INPUT: [23,-7,12,-10,-11,40,-60]
OUTPUT: -7 -10 -11 -60 12 40 23 
*/