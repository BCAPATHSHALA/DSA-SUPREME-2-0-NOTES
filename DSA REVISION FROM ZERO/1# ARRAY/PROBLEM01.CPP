// PROBLEM 1: Count 0's an 1's in an array
#include<iostream>
using namespace std;

void countZeroAndOne(int nums[], int size){
    int zeros = 0;
    int ones = 0;

    for(int i = 0; i < size; i++){
        if(nums[i] == 0){
            zeros++;
        }
        if(nums[i] == 1){
            ones++;
        }
    }

    cout<<"Zeros: "<<zeros<<endl;
    cout<<"Ones: "<<ones<<endl;
}

int main()
{
    int nums[100];
    int size;

    cout<<"Enter size of nums"<<endl;
    cin>>size;

    cout<<"Enter element of array"<<endl;
    for (int i = 0; i < size; i++)
    {
        cin>>nums[i];
    }

    countZeroAndOne(nums, size);
    return 0;    
}

/*
Enter size of nums
10
Enter element of array
1
1
1
0
0
0
0
1
1
1
Zeros: 4
Ones: 6
*/