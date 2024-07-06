// PROBLEM 4: Print row and col wise sum of 2D Array
#include<iostream>
#include<limits.h>
using namespace std;

void printRowAndColWiseSum(int nums[][3], int row, int col){

    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        cout<<"ROW "<<i<<" : ";
        for (int j = 0; j < col; j++)
        {
            sum += nums[i][j];
        } 
        cout<<sum<<endl;       
    }

    for (int i = 0; i < col; i++)
    {
        int sum = 0;
        cout<<"COL "<<i<<" : ";
        for (int j = 0; j < row; j++)
        {
            sum += nums[j][i];
        } 
        cout<<sum<<endl;       
    }
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

    printRowAndColWiseSum(nums, row, col);
    return 0;    
}

/*
Enter element of nums
ROW 0
1 2 3
ROW 1
4 5 6
ROW 2
7 8 9

ROW 0 : 6
ROW 1 : 15
ROW 2 : 24

COL 0 : 12
COL 1 : 15
COL 2 : 18
*/