// PROBLEM 5: Find unique element (Each elements occurs twice except one)
#include<iostream>
using namespace std;

int getUniqueOne(int nums[], int size){
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans ^= nums[i];
    }

    return ans;    
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

    int uniqueValue = getUniqueOne(nums, size);
    cout<<"Unique number: " << uniqueValue << endl;
    return 0;    
}

/*
Enter the size of nums
5
Enter the elements of nums
1
1
2
3
3
Unique number: 2
*/