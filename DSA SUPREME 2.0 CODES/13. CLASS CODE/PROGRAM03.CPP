// Program 03: Find the Number Occurring Odd Number of Times
#include<iostream>
#include<vector>
using namespace std;

// Find number occurring odd number of times
int findOddOccuringElement(vector<int> arr){
    int n=arr.size();
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    int ans = -1;

    while(s<=e){
        // Single element
        if(s==e){
            return s;
        }
        // when mid index is odd
        if(mid & 1){

            // Goto right side and CATCH: 01 mid-1>=0 because arr[-1] nahi ho skta hai
            if(mid-1>=0 && arr[mid]==arr[mid-1]){
                s=mid+1;
            }
            // Goto left side
            else{
                e=mid-1;
            }
        } 
        // when mid index is even
        else{
            
            // Goto right side to get ans and CATCH: 02 mid+1<n because agar n=7 hai to arr[n] nahi ho skta hai
            if(mid+1<n && arr[mid]==arr[mid+1]){
                // CATCH: 03 we don't want to capare twice for one element
                s=mid+2;
            }
            // CATCH: 04 Store mid in ans and go to left side to get ans (ans/end || peak/ans)
            else{
                ans=mid;
                e=mid;
            }
        }
        // updated mid
        mid=s+(e-s)/2;
    }
    return ans;
}
/*
Time Complexity: O(logN), where N is array's length
Space Compexity: O(1)
*/

int main(){
    vector<int> arr{10,10,2,2,5,5,2,5,5,20,20,11,11,10,10};

    int ansIndex = findOddOccuringElement(arr);

    if(ansIndex==-1){
        cout<<ansIndex<<endl;
    }
    else{
        cout<<"Final ans is "<<arr[ansIndex]<<endl;
    }

    return 0;
}

/*
Program 03: Find the Number Occurring Odd Number of Times
Conditions: 
1. All elements - even number of times occurs except one 
2. All repeating elements - pairs repeat and pairs are not repeated 
3. Ek element ek bar me 2 times nahi aa skta hai 

OUTPUT --> Find element that occurs odd time

Example 01: 
Input: arr[10,10,2,2,5,5,2,5,5,20,20,11,11,10,10], N=15
Output: Final ans is 2

Example 02: 
Input: arr[1,1,5,5,2,2,3,3,2,4,4], N=11
Output: Final ans is 2

Example 03: 
Input: arr[1,1,5,5,2,2,3,3,4,4], N=10
Output: -1

Example 04:
Input: arr[1,1,5,5,2,2,3,3,4,4,4,4]
Output: -1
*/