// 2. Gas Station (Leetcode-134)

/*
Problem Statement:
There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to 
its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around 
the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.

Example 1:
Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.

Example 2:
Input: gas = [2,3,4], cost = [3,4,3]
Output: -1
Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.
 
Constraints:
1. n == gas.length == cost.length
2. 1 <= n <= 10^5
3. 0 <= gas[i], cost[i] <= 10^4
*/


// Optimal Solution Without Using Queue 
/*
Time Complexity: O(N), Where N is size of array
Space Complexity: O(1), no extra space used
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficit = 0;
        int balance = 0;
        // Car start index se drive karna start karegi
        int start = 0;

        // Har ek index ko check karenge ki wo ans/starting index hai ya nahi
        for(int index = 0; index < gas.size(); index++){
            balance += gas[index] - cost[index];

            if(balance < 0){
                deficit += abs(balance);
                start = index + 1;
                balance = 0;
            }
        }

        // Car circle complete kar chuki hai
        if(balance - deficit >= 0){
            return start;
        }
        else{
        // Car circle complete nahi kar payi hai
            return -1;            
        }
    }
};