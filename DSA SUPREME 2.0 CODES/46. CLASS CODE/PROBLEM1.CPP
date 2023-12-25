// PROBLEM 1: Merge K Sorted Arrays (GFG)

/*
Time Complexity: O(K*Log(K)) + O(N*Log(K))
Space Complexity: O(N) + O(K)
Where N and K are total elements of all arrays and total numbers of arrays respectively.
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// OWN DATA TYPE
class Info
{
    public:
        int data;
        int rowIndex;
        int colIndex;

        Info(int data, int rowIndex, int colIndex){
            this->data = data;
            this->rowIndex = rowIndex;
            this->colIndex = colIndex;
        }
};

// OWN COMPARETOR TO RETURN THE MIN NODE FROM TWO DIFFERENT NODE -> true/false
class Compare
{
    public:
        bool operator()(Info* first, Info* second){
            // Returns true if first = 1 comes before second=2 in the ordering
            return first->data > second->data; // Create Min Heap
        }
};


void mergeKSortedArrays(int arr[][4], int n, int k, vector<int> &ans){
    // Create MIN Heap 
    priority_queue<Info*, vector<Info*>, Compare> pq;

    // I. process first k elements from k arrays
    for (int row = 0; row < k; row++)
    {
        int element = arr[row][0]; // arr[0][0], arr[1][0], arr[2][0]
        Info* tempNode = new Info(element, row, 0);
        pq.push(tempNode);
    }
    
    while (!pq.empty())
    {
        Info* topNode = pq.top();
        pq.pop();
        
        // II. Find topData (Min Value)
        int topData = topNode->data;
        int topRow = topNode->rowIndex;
        int topCol = topNode->colIndex;

        // III. Ab ans array me topData (Min Value) push kar do
        ans.push_back(topData);

        // IV. Ab next element kya hoga for the same row, jis row se element ko pop kiya hai
        // usse insert bhi to karna hai--> to topCol ko 1 se increament krdo
        if(topCol + 1 < n){
            // iska mtlb present row me abhi or v elements baki hai
            Info* newNode = new Info(arr[topRow][topCol+1], topRow, topCol+1);
            pq.push(newNode);
        }
    }    
}


int main(){
    int rowSize = 3;
    int colSize = 4;
    int arr[3][4] = {{1, 4, 8, 10},{2, 3, 6, 9},{5, 7, 11, 12}};

    int n = colSize;
    int k = rowSize;

    vector<int> ans;
    mergeKSortedArrays(arr, n, k, ans);

    cout<< " Printing Single Sorted Array: " << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}

/*
Printing Single Sorted Array: 
1 2 3 4 5 6 7 8 9 10 11 12 
*/