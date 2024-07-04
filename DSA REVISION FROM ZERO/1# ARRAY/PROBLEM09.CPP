// PROBLEM 9: Shift array's element by one (right to left)
#include<iostream>
using namespace std;

void shiftArrayElementByOneFromRightToLeft(int nums[], int size){
    int rightMostValue = nums[size - 1];
    for(int i = size - 1; i >= 0; i--)
    {
        nums[i] = nums[i-1];
    }

    // Right most value ko 0th index par place karna mat bhoolna
    nums[0] = rightMostValue;

    for (int i = 0; i < size; i++)
    {
        cout<<nums[i]<<" ";
    }
}

int main(){
    int nums[100];
    int size;

    cout<<"Enter the size of nums"<<endl;
    cin>>size;

    cout<<"Enter the elements of nums"<<endl;
    for (int i = 0; i < size; i++)
    {
        cin>>nums[i];
    }

    shiftArrayElementByOneFromRightToLeft(nums, size);
    return 0;    
}

/*
Enter the size of nums
6
Enter the elements of nums
10
20
30
40
50
60
60 10 20 30 40 50
*/