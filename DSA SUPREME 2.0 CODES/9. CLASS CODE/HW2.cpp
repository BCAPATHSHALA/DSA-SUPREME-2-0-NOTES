//HW 01: Sum of secondary diagonal elements of a matrix
#include<iostream>
#include<limits.h>
using namespace std;

// Sum of secondary diagonal elements of a matrix
void secondaryDiagonalSum(int arr[][3],int row,int col){
    int sum=0;
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(i+j==(col-1)){
                sum+=arr[i][j];
            }
        }
    }
    cout<<sum<<endl;
}

int main(){
    // initialization of 2D array
    int arr[3][3]={
        {1,2,3},
        {4,6,6},
        {7,8,9}
    };
    int row=3;
    int col=3;

    cout<<"Secondary Diagonal Sum"<<endl;
    secondaryDiagonalSum(arr,row,col);

    return 0;
}

/*
Secondary Diagonal Sum
16
*/