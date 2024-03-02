// 1. Number of Islands (Leetcode-200)

/*
Problem Statement:
Given an `m x n` 2D binary grid which represents a map of '1's (land) and '0's (water), 
return the number of islands.

Important Line: 
An `island` is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

📝 ACTUAL ME ISLANDS KA MATLB HAI COMPONENTS FIND KARNA FROM DISCONNECTED GRAPH

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

Constraints:
1. m == grid.length
2. n == grid[i].length
3. 1 <= m, n <= 300
4. grid[i][j] is '0' or '1'.
*/

// Solve Using BFS Traversal
class Solution {
public:
    bool isSafe(int newX, int newY, vector<vector<char>>& grid, map<pair<int,int>,bool> &visited){
        if(newX >= 0 && newY >= 0 && newX < grid.size() && newY < grid[0].size() && !visited[{newX, newY}] && grid[newX][newY] != '0'){
            return true;
        }
        else{
            return false;
        }
    }
    void bfs(vector<vector<char>>& grid, int srcX, int srcY, map<pair<int,int>,bool> &visited){
        queue<pair<int, int> > q;
        // initial state
        q.push({srcX, srcY});
        visited[{srcX, srcY}] = true;

        while(!q.empty()){
            pair<int, int> frontNodePair = q.front();
            q.pop();
            int tempX = frontNodePair.first;
            int tempY = frontNodePair.second;
            
            // We have four move from each cell janaha par hum khade hue hai
            // TopMove --> RightMove --> BottomMove --> LeftMove
            int dx[] = {-1, 0, 1, 0};
            int dy[] = { 0, 1, 0, -1};
            for(int i=0; i<4; i++){
                int newX = tempX + dx[i];
                int newY = tempY + dy[i];
                if(isSafe(newX, newY, grid, visited)){
                    // Update the initial state
                    q.push({newX, newY});
                    visited[{newX, newY}] = true;
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        map<pair<int,int>,bool> visited;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] !='0' && !visited[{i,j}]){
                    bfs(grid, i, j, visited);
                    // islands is increasing by 1 when bfs call is completed
                    count++;
                }
            }
        }
        return count;
    }
};


// Solve Using DFS Traversal

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        // Base case
        if(i < 0 || j < 0 || i >= m ||  j >= n || grid[i][j] =='0' || grid[i][j] == 'x'){
            return;
        }

        // 1 case hum solve kar lege: 
        // x represents the current cell of grid is visited now
        grid[i][j] = 'x';

        // We have four move from each cell janaha par hum khade hue hai
        // TopMove
        dfs(grid, i-1, j);
        // BottomMove
        dfs(grid, i+1, j);
        // RightMove
        dfs(grid, i, j+1);
        // LeftMove
        dfs(grid, i, j-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] !='0' && grid[i][j] != 'x'){
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};