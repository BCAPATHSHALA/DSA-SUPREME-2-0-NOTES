// PROBLEM 3: Smallest Range in K Lists (Leetcode-632)
/*
Problem statement:
You have k lists of sorted integers in non-decreasing order. 
Find the smallest range that includes at least one number from each of the k lists.
We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

Example 1:
Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].

Example 2:
Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]
 

Constraints:
1. nums.length == k
2. 1 <= k <= 3500
3. 1 <= nums[i].length <= 50
4. -10^5 <= nums[i][j] <= 10^5
5. nums[i] is sorted in non-decreasing order.

Time complexity: O(N*Log N)
Space complexity: O(K)
Where 
N is number of elements of each array lists and 
K is number of all array lists
*/


class Solution {
public:
    // Own Data Type
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
    // Own Comparetor
    class Compare
    {
        public:
            bool operator()(Info* first, Info* second){
                return first->data > second->data;
            }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Create MIN Heap 
        priority_queue<Info*, vector<Info*>, Compare> pq;
        int maxi = INT_MIN;
        int mini = INT_MAX;

        // I. process first ke elements to crate the min heap [row=0,1,2,....][col=0]
        for(int i=0; i<nums.size(); i++){
            int element = nums[i][0];
            int row = i;
            int col = 0;
            Info* tempNode = new Info(element, row, col);
            pq.push(tempNode);
            maxi = max(maxi, element);
            mini = min(mini, element);
        }

        // Old Range
        int ansStart = mini;
        int ansEnd = maxi;

        // II. Fetch top and pop || update mini || update range
        while(!pq.empty()){
            Info* topNode = pq.top();
            int topData = topNode->data;
            int topRow = topNode->rowIndex;
            int topCol = topNode->colIndex;
            pq.pop();

            // Update mini
            mini = topNode->data;
            // maxi value pahle se ho updated hai
            // to ab smaller range ke liye compare kar lete hai
            int oldRangeDistance = ansEnd - ansStart;
            int newRangeDistance = maxi - mini;
            if(newRangeDistance < oldRangeDistance){
                // Update the old range
                ansStart = mini;
                ansEnd = maxi;
            }

            // III. Insert new element
            if(topCol + 1 < nums[topRow].size()){
                int newElement = nums[topRow][topCol+1];
                Info* newNode = new Info(newElement, topRow, topCol + 1);
                pq.push(newNode);

                // Update maxi
                maxi = max(maxi, newElement);
            }
            else{
                // agar koi bhi element nhi hai to Loop ko break krdo
                break;
            }

        }

        vector<int> ans;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;
    }
};