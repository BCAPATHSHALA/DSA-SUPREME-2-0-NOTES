// 📂 Program 03: Count Derangements (GFG)
// Permutation such that no element appears in its original position

/*
Input: n = 2
Output: 1
For two elements say {0, 1}, there is only one 
possible derangement {1, 0}

Input: n = 3
Output: 2
For three elements say {0, 1, 2}, there are two 
possible derangements {2, 0, 1} and {1, 2, 0}

Input: n = 4
Output: 9
For four elements say {0, 1, 2, 3}, there are 9
possible derangements {1, 0, 3, 2} {1, 2, 3, 0}
{1, 3, 0, 2}, {2, 3, 0, 1}, {2, 0, 3, 1}, {2, 3,
1, 0}, {3, 0, 1, 2}, {3, 2, 0, 1} and {3, 2, 1, 0}
*/

#include<iostream>
using namespace std;

int solve(int n){
    // Base case
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }

    // Recursive call
    int ans = (n-1) * (solve(n-1) + solve(n-2));
    return ans;
}

int main(){
    int n = 4;
    cout<< solve(n) << endl;

    return 0;
}