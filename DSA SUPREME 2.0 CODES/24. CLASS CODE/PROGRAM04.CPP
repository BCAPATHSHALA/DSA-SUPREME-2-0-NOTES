// 📂 Program 04: Painting Fence Algorithm (GFG)
/*
Problem Statement:
The painting fence algorithm determines the number of ways to paint a fence with multiple 'N' posts and 'K' colors. 
The algorithm ensures that at most 2 adjacent posts (no more than two adjacent posts) have the same color. 
Since answer can be large return it modulo 10^9 + 7 (1000000007).

Examples:

Input : N = 1 K = 3
Output : 3

Input : N = 2 K = 3
Output : 9

Input : N = 3 K = 3
Output : 24

Input : N = 4 K = 3
Output : 66
*/

#include<iostream>
using namespace std;

int getPaintWays(int N, int K){
    // Base Case
    if(n == 1){
        return K;
    }
    if(n == 2){
        return K + (K*(K-1));
    }

    int ans = (K-1) * (getPaintWays(N-2,K) + getPaintWays(N-1, K));
    return ans;
}

int main(){
    int N = 3; // Posts
    int K = 3; // Colors
    cout<<getPaintWays(N,K)<<endl;
}