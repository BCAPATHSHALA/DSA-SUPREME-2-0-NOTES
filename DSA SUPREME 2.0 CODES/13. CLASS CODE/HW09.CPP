// HW 09: PRATA SPOJ

/*
Problem Statement:
IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. 
The subcommittee members are asked to go to food connection and get P (P<=1000) pratas packed for the function. 
The stall has L cooks (L<=50) and each cook has a rank R (1<=R<=8). 
A cook with a rank R can cook 1 prata in the first R minutes 1 more prata in the next 2R minutes, 1 more prata in 3R minutes 
and so on (he can only cook a complete prata) 

For example: if a cook is ranked 2, he will cook 
1st prata in 2 mins
2nd prata in the next 4 mins
3rd prata in the next 6 mins 
hence he cooks 3 pratas in total 12 minutes

🖊️MUJHE FIND KYA KARNA HAI: The webmaster wants to know the minimum time to get the order done.

---------------------------------------------------------------------------------------------------------------------------------------
📌Observation:
Number of pratas = P <=1000
Number of cooks  = L <=50
Each cook has a rank = R ∈ [1,8]

---------------------------------------------------------------------------------------------------------------------------------------
Input:
3 --> Total Cases
10 --> nP
4 1 2 3 4 --> nC and remaining 4 are R [1,2,3,4]
8 --> nP
1 1 --> nC and remaining 1 are R [1]
8 -- nP
8 1 1 1 1 1 1 1 1 --> nC and remaining 8 are R [1,1,1,1,1,1,1,1]

Output:
12
36
1

Number of pratas = nP = 10
Number of cooks = nC = 4
Each cook has a rank = R = [1,2,3,4]

---------------------------------------------------------------------------------------------------------------------------------------
Example 01:
input: nP = 10, nC = 4, R = [1,2,3,4]
Output: 12

Example 02:
input: nP = 8, nC = 1, R = [1]
Output: 36

Example 03:
input: nP = 8, nC = 8, R = [1,1,1,1,1,1,1,1]
Output: 1

---------------------------------------------------------------------------------------------------------------------------------------
OPTIMAL APPROACH: Define search space and predicate function 
Step 01: Find highest ranked cooked time to create search space's end point (highest maximum time to complete the order)
Step 02: Now, Applying Binary Search on search space BinarySearch()
Step 03: create predicate function isPossibbleSol()

---------------------------------------------------------------------------------------------------------------------------------------
Time Complexity: O(N*log(end)), Here N is size of array R and end is the highest maximum time to complete the order
Space Complexity: O(1), no extra space used

---------------------------------------------------------------------------------------------------------------------------------------
Resource: https://www.spoj.com/problems/PRATA/
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// predicate function
bool isPossibleSol(vector<int> cooksRanks,int nP,int mid){
    int currP = 0; // initial cooked prata count

    for(int i=0;i<cooksRanks.size();i++){
        int R = cooksRanks[i], cP=1; // cP = completed prata
        int timeTaken = 0; // initial time taken by each cooks

        while(true){
            if(timeTaken + cP*R <= mid){
                currP++;
                timeTaken += cP*R;
                cP++;
            }
            else{
                break; // while loop se bahar nikal jaunga or dusre cook ko pakdunga order complete karne ke liye
            }
        }
        if(currP>=nP){
            return true; // agar 10 ya 10 jyada prate given time (mid) se kam time me honge to return true kardo(Possible case)
        }
    }
    // agar kisi bhi cases me diye huee prate given time(mid) ya usse kam time me nhi ho paate hai to return false kardo(Not Possible case)
    return false;
}

// Binary Search
int BinarySearch(vector<int> cooksRanks,int nP,int end){
    int start = 0, mid = start + (end - start)/2;
    int ans = -1; // minimum time stored in ans

    while(start<=end){
        // Step 03: create predicate function isPossibbleSol()
        if(isPossibleSol(cooksRanks,nP,mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int minTimeToCompleteOrder(vector<int> cooksRanks,int nP){
    // Step 01: Find highest ranked cooked time
    int maxCooksRank = *max_element(cooksRanks.begin(), cooksRanks.end());
    int end = maxCooksRank * (nP * (nP + 1) / 2);

    // Step 02: Now, Applying Binary Search on search space
    int finalAns = BinarySearch(cooksRanks,nP,end);
    return finalAns;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int nP, nC;
        cin >> nP >> nC;
        vector<int> cooksRanks;
        while(nC--){
            int R;
            cin>>R;
            cooksRanks.push_back(R);
        }
        int ans = minTimeToCompleteOrder(cooksRanks,nP);
        cout<<ans<<endl;
    }
    return 0;
}