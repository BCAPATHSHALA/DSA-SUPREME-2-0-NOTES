// PROBLEM 2: Linear search in 2D Array
#include<iostream>
using namespace std;

bool findTarget(int nums[][3], int row, int col, int target){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(nums[i][j] == target)
            {
                return true;
            }
        }        
    }
    return false;    
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

    bool isFound = findTarget(nums, row, col, 5);
    if(isFound){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }
    return 0;    
}

/*
Enter element of nums
ROW 0
1 2 3 
ROW 1
1 2 3
ROW 2
5 6 7
Found
*/