// 2. Maximum Height by Stacking Cuboids (Leetcode-1691)

/*
Problem Statement:
Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). 
Choose a subset of cuboids and place them on each other.

You can place cuboid i on cuboid j if 
widthi <= widthj and lengthi <= lengthj and heighti <= heightj. 
Note: You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.

Return the maximum height of the stacked cuboids.

Example 1:
Input: cuboids = [[50,45,20],[95,37,53],[45,23,12]]
Output: 190
Explanation:
Cuboid 1 is placed on the bottom with the 53x37 side facing down with height 95.
Cuboid 0 is placed next with the 45x20 side facing down with height 50.
Cuboid 2 is placed next with the 23x12 side facing down with height 45.
The total height is 95 + 50 + 45 = 190.

Example 2:
Input: cuboids = [[38,25,45],[76,35,3]]
Output: 76
Explanation:
You can't place any of the cuboids on the other.
We choose cuboid 1 and rotate it so that the 35x3 side is facing down and its height is 76.

Example 3:
Input: cuboids = [[7,11,17],[7,17,11],[11,7,17],[11,17,7],[17,7,11],[17,11,7]]
Output: 102
Explanation:
After rearranging the cuboids, you can see that all cuboids have the same dimension.
You can place the 11x7 side down on all cuboids so their heights are 17.
The maximum height of stacked cuboids is 6 * 17 = 102.
 
Constraints:
1. n == cuboids.length
2. 1 <= n <= 100
3. 1 <= widthi, lengthi, heighti <= 100
*/

// ================== Approach 4: Space Optimization Approach ================== //

class Solution {
public:
    bool check(vector<int> curr , vector<int> prev){
        // Curr - bade wale dibbe ko represent krta hai
        // Prev - chotte wale dibbe ko represent krta hai
        if(curr[0] >= prev[0] && curr[1] >= prev[1] && curr[2] >= prev[2]){
            return true;
        }
        else{
            return false;
        }
    }
    int solveUsingTabuOS(vector<vector<int>>& cuboids){
        int n = cuboids.size();
        vector<int> currRow (n+1, 0);
        vector<int> nextRow (n+1, 0);

        // Loop row wise hi chalana hai mujhe
        for(int currIndex = n-1; currIndex >= 0; currIndex--){
            for(int prevIndex = currIndex-1; prevIndex >= -1; prevIndex--){
                // Recursive call
                int include = 0;
                if(prevIndex == -1 || check(cuboids[currIndex], cuboids[prevIndex])){
                    int heightAdded = cuboids[currIndex][2];
                    include = heightAdded + nextRow[currIndex+1];
                }
                int exclude = 0 + nextRow[prevIndex+1];
                currRow[prevIndex+1] = max(include, exclude);
            }
            // Shift Karna Bhool Jata hu
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        // Sort each cuboid (mene rotete kar diya hai)
        for(auto &cuboid: cuboids){
            sort(cuboid.begin(), cuboid.end());
        }
        // Sort cuboids array
        sort(cuboids.begin(), cuboids.end());
        int ans = solveUsingTabuOS(cuboids);
        return ans;
    }
};