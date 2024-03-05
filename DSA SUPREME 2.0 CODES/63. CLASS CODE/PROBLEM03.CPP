// 3. Flood Fill (Leetcode-733)

/*
Problem Statement:
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally 
to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally 
to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.


Example 1:
Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

Example 2:
Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation: The starting pixel is already colored 0, so no changes are made to the image.

Constraints:
1. m == image.length
2. n == image[i].length
3. 1 <= m, n <= 50
4. 0 <= image[i][j], color < 2^16
5. 0 <= sr < m
6. 0 <= sc < n
*/


class Solution {
public:
    bool isSafe(int newX, int newY, map<pair<int,int>,bool> &visited, vector<vector<int>> &ans, int oldColor){
        if(newX >= 0 && newY >= 0 && newX < ans.size() && newY < ans[0].size() && ans[newX][newY] == oldColor && visited[{newX, newY}] == false){
            return true;
        }
        else{
            return false;
        }
    }
    void dfs(int oldColor, int newColor, map<pair<int,int>, bool> &visited, vector<vector<int>> &ans, vector<vector<int>>& image, int sr, int sc){
        // visited true for each cell/node
        visited[{sr,sc}] = true;
        // ans is updated with newColor
        ans[sr][sc] = newColor;

        // We have four move from each cell janaha par hum khade hue hai
        // TopMove --> RightMove --> BottomMove --> LeftMove
        int dx[] = {-1, 0, 1, 0};
        int dy[] = { 0, 1, 0, -1};
        for(int i=0; i<4; i++){
            int newX = sr + dx[i];
            int newY = sc + dy[i];
            if(isSafe(newX, newY, visited, ans, oldColor)){
                dfs(oldColor, newColor, visited, ans, image, newX, newY);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        map<pair<int,int>, bool> visited;
        int oldColor = image[sr][sc];
        int newColor = color;

        dfs(oldColor, newColor, visited, ans, image, sr, sc);
        return ans;
    }
};