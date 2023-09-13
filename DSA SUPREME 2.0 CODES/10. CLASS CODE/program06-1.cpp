// Program 06-1: Rotate Image by 90 degree (VVImp Leetcode-48) 
class Solution {
public:
    void reverseVector(vector<int>& arr){
        int size=arr.size();
        int start=0;
        int end=size-1;
        while(start<=end){
            swap(arr[start],arr[end]);
            start++;
            end--;
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();

        // Step 01: Transpose of matrix
        for(int i=0;i<n;i++){
            for(int j=i;j<matrix[0].size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        // Step 02: Reverse each from 0 to n-1
        for(int i=0;i<n;i++){
            reverseVector(matrix[i]);
        }
        
    }
};

/*
Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Example 2:
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
*/