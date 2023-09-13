// Program 05: Row with maximum ones (VVImp Leetcode-2643) 
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int rowSize=mat.size();
        int colSize=mat[0].size();

        int oneCount=INT_MIN; 
        int rowNo=-1;
        vector<int> ans;

        for(int row=0;row<rowSize;row++){
            int sum=0;
            for(int col=0;col<colSize;col++){
                if(mat[row][col]==1){
                    sum++;
                }
            }

            if(sum>oneCount){
                oneCount=sum;
                rowNo=row;
            }
        }

        ans.push_back(rowNo);
        ans.push_back(oneCount);
        return ans;
    }
};


// Time Complexity: O(N*M)

/*
Example 1:
Input: mat = [[0,1],[1,0]]
Output: [0,1]
Explanation: Both rows have the same number of 1's. So we return the index of the smaller row, 0, and the maximum count of ones (1). So, the answer is [0,1]. 

Example 2:
Input: mat = [[0,0,0],[0,1,1]]
Output: [1,2]
Explanation: The row indexed 1 has the maximum count of ones (2). So we return its index, 1, and the count. So, the answer is [1,2].

Example 3:
Input: mat = [[0,0],[1,1],[0,0]]
Output: [1,2]
Explanation: The row indexed 1 has the maximum count of ones (2). So the answer is [1,2].
*/