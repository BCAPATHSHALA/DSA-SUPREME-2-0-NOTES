//Program 03: Find min and max
#include<iostream>
#include<limits.h>
using namespace std;

// Find max
void findMax(int arr[][3],int row,int col){
    int max=INT_MIN;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]>max){
                max=arr[i][j];
            }
        }
    }
    cout<<"Maximum is : "<<max<<endl;
}

// Find min
void findMin(int arr[][3],int row,int col){
    int min=INT_MAX;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]<min){
                min=arr[i][j];
            }
        }
    }
    cout<<"Minimum is : "<<min<<endl;
}

int main(){
    // initialization of 2D array
    int arr[3][3]={
        {10,20,30},
        {40,50,60},
        {70,80,90}
    };
    int row=3;
    int col=3;

    findMax(arr,row,col);
    findMin(arr,row,col);

    return 0;
}

/*
OUTPUT: Maximum is : 90

OUTPUT: Minimum is : 10
*/