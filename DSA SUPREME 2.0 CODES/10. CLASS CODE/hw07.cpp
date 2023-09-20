// HW 07: Wave Print A Matrix (GFG)
#include<iostream>
#include<vector>
using namespace std;

// Print wave matrix
void printWaveMatrix(vector<vector<int>> matrix){
    int row = matrix.size();
    int col = matrix[0].size();
    
    // Iterate array column wise
    for(int startCol=0; startCol<col; startCol++){
        
        // when startCol==even then print row top to bottom
        if((startCol & 1)==0){
            for(int i=0;i<row;i++){
                cout<<matrix[i][startCol]<<" ";
            }
        }
        // when startCol==odd then print row bottom to top
        else{
            for(int i=row-1;i>=0;i--){
                cout<<matrix[i][startCol]<<" ";
            }
        }
    }
}

int main(){
    vector<vector<int>> matrix
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    printWaveMatrix(matrix);

    return 0;
}

/*
Input: matrix[][] =     
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    }
Output: 1 5 9 10 6 2 3 7 11 12 8 4 
Explanation: Output is printed in wave form. 
*/