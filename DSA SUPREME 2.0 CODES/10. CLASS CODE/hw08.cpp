// HW 08: Spiral Print A Matrix (Leetcode-54)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans;
        int m=matrix.size();
        int n=matrix[0].size();

        // Step 01: Total elements of matrix
        int totalElements=m*n;

        int startingRow = 0;
        int endingCol = n-1;
        int endingRow = m-1;
        int startingCol = 0;

        // Step 02: Iterate matrix till end of the total element
        int count=0;
        while(count<totalElements){
            // Print startingRow
            for(int i=startingRow;i<=endingCol && count<totalElements;i++){
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;

            // Print endingCol
            for(int i=startingRow;i<=endingRow && count<totalElements;i++){
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;

            // Print endingRow
            for(int i=endingCol;i>=startingCol && count<totalElements;i--){
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;

            // Print startingCol
            for(int i=endingRow;i>=startingRow && count<totalElements;i--){
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
    }
};


/*
Example 01:
Input:  {{1,   2,   3,   4},
        {5,    6,   7,   8},
        {9,   10,  11,  12},
        {13,  14,  15,  16 }}

Output: 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 

Example 02:
Input: {{1,   2,   3,   4,  5,   6},
        {7,   8,   9,  10,  11,  12},
        {13,  14,  15, 16,  17,  18}}

Output: 1 2 3 4 5 6 12 18 17 16 15 14 13 7 8 9 10 11
*/