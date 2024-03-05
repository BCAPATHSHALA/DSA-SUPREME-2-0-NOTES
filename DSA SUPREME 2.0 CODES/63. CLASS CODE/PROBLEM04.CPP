// 4. Rotting Oranges (Leetcode-994)

/*
You are given an m x n grid where each cell can have one of three values:

1. 0 representing an empty cell,
2. 1 representing a fresh orange, or
3. 2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

Example 4:
Input: grid = [[2,1,1],[1,1,0],[2,0,2]]
Output: 2

Constraints:
1. m == grid.length
2. n == grid[i].length
3. 1 <= m, n <= 10
4. grid[i][j] is 0, 1, or 2.
*/


class Solution {
public:
    bool isSafe(int newX, int newY, vector<vector<int>> &temp){
        if(newX >= 0 && newY >= 0 && newX < temp.size() && newY < temp[0].size() && temp[newX][newY] == 1){
            return true;
        }
        else{
            return false;
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> temp = grid;
        queue<pair<pair<int,int>, int>> q;
        int minTime = 0;

        // find all rotten oranges and push into the queue
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(temp[i][j] == 2){
                    // Initial state: 
                    // push each src node into the queue with initial time is 0 minute
                    q.push({{i, j}, 0});
                }
            }
        }

        // BFS Logic start
        while(!q.empty()){
            // Step 1: get front node and pop it
            auto frontNodePair = q.front();
            q.pop();

            auto frontNodeCoordinates = frontNodePair.first;
            int frontNodeTime = frontNodePair.second;
            int tempX = frontNodeCoordinates.first;
            int tempY = frontNodeCoordinates.second;

            // Step 2: we have four move from each node so goto
            // each possible move to make rotten orange
            int dx[] = {-1, 0, 1, 0};
            int dy[] = { 0, 1, 0, -1};
            for(int i=0; i<4; i++){
                int newX = tempX + dx[i];
                int newY = tempY + dy[i];
                if(isSafe(newX, newY, temp)){
                    // Push rotten orange into queue
                    q.push({{newX, newY}, frontNodeTime+1});
                    // Mark as rotten orange
                    temp[newX][newY] = 2;
                    // Update the minTime
                    minTime = max(frontNodeTime+1, minTime);
                }
            }
        }

        // Step 3: ab queue empty ho chuka hai it means 
        // hamne all possible oranges ko rotten bna diya hai
        // check karo ki koi orange fresh to nhi hai agar hai to return -1
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(temp[i][j] == 1){
                    return -1;
                }
            }
        }

        // Koi fresh ornage nhi hai to minTime return krdo
        return minTime;
    }
};