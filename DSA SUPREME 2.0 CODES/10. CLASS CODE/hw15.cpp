// HW 15: Add two numbers represented by two array (GFG)
#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

// Add two numbers represented by two array
vector<int> calc_Sum(int a[],int n,int b[],int m){        
    int i=n-1;
    int j=m-1;
    vector<int> ans;
    int carry = 0;
        
    // Case: 01 Jab i and j both are greater than or equal to 0 honge
    while(i>=0 && j>=0){
        int x = a[i] + b[j] + carry;
        int digit = x % 10;
        // Push digit in ans 
        ans.push_back(digit);
        carry = x / 10;
        i--,j--;
    }
    // Case 02: Jab i greater than or equal to 0 hoga
    while(i>=0){
        int x = a[i] + 0 + carry;
        int digit = x % 10;
        // Push digit in ans 
        ans.push_back(digit);
        carry = x / 10;
        i--;
    }
    // Case 03: Jab j greater than or equal to 0 hoga
    while(j>=0){
        int x = 0 + b[j] + carry;
        int digit = x % 10;
        // Push digit in ans 
        ans.push_back(digit);
        carry = x / 10;
        j--;
    }
    // Case 04: Jab Carry greater than 0 hoga
    if(carry > 0){
        ans.push_back(carry);
    }
    // Case 05: Jab actual ans ke last position par zero ho tab tak use delete karte rahenge
    while(ans[ans.size()-1] == 0){
        ans.pop_back();
    }
    // Actual ans ko reverse krdo correct ans ke liye
    reverse(ans.begin(), ans.end());
    return ans;
}

/*
Time Complexity: O(N + M) 
Space Complexity: O(N + M)

Where N and M are size of array of a and b respectively
*/

int main(){
    int a[]={9, 5, 4, 9};
    int b[]={2, 1, 4};
    int n = sizeof(a)/sizeof(a[0]);
    int m = sizeof(b)/sizeof(b[0]);

    vector<int> currectAns = calc_Sum(a,n,b,m);
    for (auto i : currectAns) {
        cout<<i;
    }
    
    return 0;
}


/*
Example 01:
Input : A[] = {1, 2}, B[] = {2, 1}
Output : 33
Explanation:
N=2, and A[]={1,2}
M=2, and B[]={2,1}
Number represented by first array is 12.
Number represented by second array is 21
Sum=12+21=33

Example 02:
Input : A[] = {9, 5, 4, 9}, B[] = {2, 1, 4}
Output : 9763

Example 03:
Input : A[] = {2, 1, 4}, B[] = {9, 5, 4, 9}
Output : 9763

Example 04:
Input : A[] = {9, 1, 4}, B[] = {8, 1, 4}
Output : 1728

Example 05:
Input : A[] = {0, 0, 2, 1, 4}, B[] = {0, 0, 2, 1, 4}
Output : 428

*/