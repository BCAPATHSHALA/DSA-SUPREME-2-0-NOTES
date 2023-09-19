// Program 04: Binary search in 2D array (Leetcode-74)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize=matrix.size();
        int colSize=matrix[0].size();
        int matrixSize=rowSize*colSize;

        int s=0;
        int e=matrixSize-1;
        int mid=s+(e-s)/2;

        while(s<=e){
            int rowIndex = mid / colSize;
            int colIndex = mid % colSize;
            int currentNumber = matrix[rowIndex][colIndex];

            if(target==currentNumber){
                return true;
            }
            else if(target>currentNumber){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
            mid=s+(e-s)/2;
        }
        return false;
    }
};

