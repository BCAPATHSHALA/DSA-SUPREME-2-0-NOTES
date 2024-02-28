// 3. Path With Minimum Effort (Leetcode-1631)

/*
Problem Statement:
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, 
where heights[row][col] represents the height of cell (row, col). 
You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). 
You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

Example 1:
Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

Example 2:
Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].

Example 3:
Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.

Constraints:
1. rows == heights.length
2. columns == heights[i].length
3. 1 <= rows, columns <= 100
4. 1 <= heights[i][j] <= 10^6
*/

class Solution {
public:
    bool isSafe(int newX, int newY, int row, int col,vector<vector<int> >& diff, int currX, int currY ) {
        if(newX >=0 && newY >=0 && newX < row && newY < col && diff[currX][currY] < diff[newX][newY]) {
            return true;
        }
        else {
            return false;
        }
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue< pair<int, pair<int,int> > , vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > mini;
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int> > diff(row, vector<int>(col, INT_MAX));
        int destX = row-1;
        int destY = col-1;

        // Initial state: 
        // Set the src difference ==> 0
        diff[0][0] = 0;
        // Insert MinHeap Entry for src ==> {diff of src,{position cell of src}}
        mini.push({0,{0,0}});

        while(!mini.empty()) {
            // Step 1: get the topPair and pop it
            pair<int, pair<int,int>> topPair = mini.top();
            mini.pop();
            int currDiff = topPair.first;
            pair<int,int>  currNodeIndexPair = topPair.second;
            int currX = currNodeIndexPair.first;
            int currY = currNodeIndexPair.second;
            
            // Step 2: Now we can travel to all nbr i.e. top, right, down, left
            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i=0; i<4; i++) {
                int newX = currX + dx[i];
                int newY = currY + dy[i];

                // Step 3: Check the isSafe to update the diff
                if(isSafe(newX, newY,row,col,diff,currX, currY)) {
                    int maxDiff = max(currDiff, abs(heights[currX][currY]-heights[newX][newY]));
                    // Update the minDiff in the diff array
                    diff[newX][newY] = min(diff[newX][newY], maxDiff);
                    // Create new entry for minHeap
                    if(newX != destX || newY != destY) {
                        mini.push({diff[newX][newY], {newX, newY}});
                    }
                }
            }
        }
        // Return destination minimum difference effort
        return diff[destX][destY];
    }
};