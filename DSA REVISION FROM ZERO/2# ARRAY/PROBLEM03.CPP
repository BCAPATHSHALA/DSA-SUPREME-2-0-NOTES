// PROBLEM 3: Find min and max in 2D Array
#include<iostream>
#include<limits.h>
using namespace std;

void findMinAndMax(int nums[][3], int row, int col){
    int mini = INT_MAX;
    int maxi = INT_MIN;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(nums[i][j] > maxi)
            {
                maxi = nums[i][j];
            }
            if(nums[i][j] < mini)
            {
                mini = nums[i][j];
            }
        }        
    }

    cout<<"MAX: "<<maxi<<" MIN: "<<mini<<endl;  
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

    findMinAndMax(nums, row, col);
    return 0;    
}

/*
Enter element of nums
ROW 0
10 20 30
ROW 1
40 50 60
ROW 2
70 80 90
MAX: 90 MIN: 10
*/