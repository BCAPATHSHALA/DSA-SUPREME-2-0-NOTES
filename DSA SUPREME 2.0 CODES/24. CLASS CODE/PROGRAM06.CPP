// 📂 Program 06: Maximal Square (Leetcode-221)

/*
Problem Statement:
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
*/


class Solution {
public:
    int solve(vector<vector<char>>& matrix, int i, int j, int row, int col, int& maxi){
        // Base case
        if(i >= row || j >= col){
            return 0;
        }

        // Explore all three directions
        int right = solve(matrix, i, j+1, row, col, maxi);
        int diagonal = solve(matrix, i+1, j+1, row, col, maxi);
        int down = solve(matrix, i+1, j, row, col, maxi);

        // Check can we build square form current position
        if(matrix[i][j] == '1'){
            int ans = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, ans);
            return ans;
        }
        else{
            // agar matrix[i][j] == 0 hai to ans hi zero hoga
            return 0;
        }
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int i = 0;
        int j = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int maxi = 0;

        int ans = solve(matrix, i, j, row, col, maxi);

        int area =  maxi*maxi;
        return area;
    }
};