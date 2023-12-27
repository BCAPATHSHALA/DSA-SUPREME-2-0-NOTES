// PROBLEM 1: Remove Stones to Minimize the Total (Leetcode-1962)

/*
Problem Statement:
You are given a 0-indexed integer array piles, where piles[i] represents the number of stones in the ith pile, and an integer k. 
You should apply the following operation exactly k times:

1. Choose any piles[i] and remove floor(piles[i] / 2) stones from it.

Notice that you can apply the operation on the same pile more than once.

Return the minimum possible total number of stones remaining after applying the k operations.

floor(x) is the greatest integer that is smaller than or equal to x (i.e., rounds x down).

Example 1:
Input: piles = [5,4,9], k = 2
Output: 12
Explanation: Steps of a possible scenario are:
- Apply the operation on pile 2. The resulting piles are [5,4,5].
- Apply the operation on pile 0. The resulting piles are [3,4,5].
The total number of stones in [3,4,5] is 12.

Example 2:
Input: piles = [4,3,6,7], k = 3
Output: 12
Explanation: Steps of a possible scenario are:
- Apply the operation on pile 2. The resulting piles are [4,3,3,7].
- Apply the operation on pile 3. The resulting piles are [4,3,3,4].
- Apply the operation on pile 0. The resulting piles are [2,3,3,4].
The total number of stones in [2,3,3,4] is 12.
 

Constraints:
1. 1 <= piles.length <= 10^5
2. 1 <= piles[i] <= 10^4
3. 1 <= k <= 10^5

Time complexity: O(N Log N) + O(K* Log(N))
Space complexity: O(N)
Where
N: Number of elements of array
K: Number of operations 
S.C.: max heap takes space of O(N)
*/
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap;

        for(int pile = 0; pile < piles.size(); pile++){
            int stonesPile = piles[pile];
            maxHeap.push(stonesPile);
        }

        while(k--){
            // Step 1: find max stones pile from the MaxHeap
            int maxStonesPile = maxHeap.top();
            maxHeap.pop();

            // Step 2: perform the operations to minimize the stones pile
            maxStonesPile = maxStonesPile - floor(maxStonesPile/2);
            // update MaxHeap with stonePile
            maxHeap.push(maxStonesPile);
        }

        // Step 3: return total sum of minimize stones pile
        int sum = 0;
        while(!maxHeap.empty()){
            int top = maxHeap.top();
            sum += top;
            maxHeap.pop();
        }

        return sum;
    }
};