// PROBLEM 2: Minimum and maximum number in an array
#include<iostream>
#include<limits.h>
using namespace std;

pair<int,int> getMinAndMaxValue(int nums[], int size){
    int mini = INT_MAX;
    int maxi = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if(nums[i] < mini){
            mini = nums[i];
        }
        if(nums[i] > maxi){
            maxi = nums[i];
        }
    }

    return pair<int,int> {mini, maxi};
}

int main(){
    int nums[100];
    int size;

    cout<<"Size of the nums"<<endl;
    cin>>size;

    cout<<"Enter the elements of nums"<<endl;
    for (int i = 0; i < size; i++)
    {
        cin>>nums[i];
    }

    pair<int,int> pairValue =  getMinAndMaxValue(nums, size);
    cout<<"Min Value: "<<pairValue.first<<" Max Value: "<<pairValue.second<<endl;
    return 0;
}

/*
Size of the nums
5
Enter the elements of nums
10
20
30
40
50
Min Value: 10 Max Value: 50
*/