// PROBLEM 4: Extreme print an array (Two Pointers Approach)
#include<iostream>
using namespace std;

void extremeArray(int nums[], int size){
    int start = 0;
    int end = size - 1;
    
    while (start <= end)
    {
        if(start == end){
            cout<<nums[start]<<" ";
        }
        else{
            cout<<nums[start]<<" ";
            cout<<nums[end]<<" ";
        }
        start++;
        end--;
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

    extremeArray(nums, size);
    return 0;    
}

/*
Enter the size of nums
5
Enter the elements of nums
10
20
30
40
50
10 50 20 40 30
*/