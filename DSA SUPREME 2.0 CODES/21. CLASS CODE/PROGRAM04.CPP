// ✅Program 04: Maximize the cost segment (GFG)
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // Base Case
        if(n == 0){
            return 0;
        }
        if(n < 0){
            return INT_MIN;
        }
        
        // Maine x length ka ek segment cut kar liya, baki ka recursion dekh lega
        int option1 = 1 + maximizeTheCuts(n-x, x, y, z);
        // Maine y length ka ek segment cut kar liya, baki ka recursion dekh lega
        int option2 = 1 + maximizeTheCuts(n-y, x, y, z);
        // Maine z length ka ek segment cut kar liya, baki ka recursion dekh lega
        int option3 = 1 + maximizeTheCuts(n-z, x, y, z);
        
        int finalAns = max(option1, max(option2, option3));
        return finalAns;
    }
};

/*

Input:
N = 4
x = 2, y = 1, z = 1
Output: 4

Explanation:Total length is 4, and the cut lengths are 2, 1 and 1.  We can make maximum 4 segments each of length 1.

Input:
N = 5
x = 5, y = 3, z = 2
Output: 2

Explanation: Here total length is 5, and the cut lengths are 5, 3 and 2. We can make two segments of lengths 3 and 2.
*/