// PROBLEM 5: Print sum of principle and secondary diagonal of a matrix
#include<iostream>
#include<limits.h>
using namespace std;

void printDiagonalSum(int nums[][3], int row, int col){
    int sumPD = 0;
    int sumSD = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j)
            {
                sumPD += nums[i][j];
            } 
            if (i+j == (col-1))
            {
                sumSD += nums[i][j];
            }             
        }       
    }
    cout<<"SUM OF PRINCIPLE DIAGONAL: "<<sumPD<<endl;
    cout<<"SUM OF SECONDARY DIAGONAL: "<<sumSD<<endl;
}

int main(){
    int nums[3][3];
    int row = 3;
    int col = 3;

    cout<<"Enter element of nums"<<endl;
    for (int i = 0; i < row; i++)
    {
        cout<<"ROW "<<i<<endl;
        for (int j = 0; j < col; j++)
        {
            cin>>nums[i][j];
        }       
    }

    printDiagonalSum(nums, row, col);
    return 0;    
}

/*
Enter element of nums
ROW 0
1 2 3
ROW 1
9 8 7
ROW 2
5 4 3
SUM OF PRINCIPLE DIAGONAL: 12
SUM OF SECONDARY DIAGONAL: 16
*/