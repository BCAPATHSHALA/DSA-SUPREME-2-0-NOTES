// Program 02: Minimum Amount of Time to Collect Garbage (Leetcode-2391)
class Solution {
public:
/*
Approach:
Step 01: Calculate pick time and find travel time index from 0th index to last index
Step 02: Calculate travel time from 0th index to last index
Step 03: Return sum of travel and pick time

Time Complexity: O(N)+ O(lastM) + O(lastP) + O(lastG) = O(N), where 
N is a length of garbage vector

Space Complexity: O(1), where no extra space used
*/

    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int pickM = 0, pickP = 0, pickG = 0; // initial pick time of M, P and G
        int travelM = 0, travelP = 0, travelG = 0; // initial travel time of M, P and G
        int lastM = 0, lastP = 0, lastG = 0; // i have to count travel time from 0th index to lastM, lastP, and lastG index

        // Step 01: Calculate pick time and find travel time index from 0th index to last index
        for(int i=0; i<garbage.size();i++){

            string str = garbage[i]; // mujhe yanha ek string mil jayegi to mujhe us string ko traverse karna padega each character par 
                                     //  to calculate the pick time and find last index to traverse the travel array

            for(auto ch: str){
                if(ch == 'M'){
                    pickM++;
                    lastM = i;
                }
                if(ch == 'P'){
                    pickP++;
                    lastP = i;
                }
                if(ch == 'G'){
                    pickG++;
                    lastG = i;
                }
            }
        }

        // Step 02: Calculate travel time from 0th index to last index
        for(int i=0;i<lastM;i++){
            travelM += travel[i];
        }
        for(int i=0;i<lastP;i++){
            travelP += travel[i];
        }
        for(int i=0;i<lastG;i++){
            travelG += travel[i];
        }

        // Step 03: Return sum of travel and pick time
        int finalAns = (pickM + travelM) + (pickP + travelP) + (pickG + travelG);
        return finalAns;
    }
};

/*
Example 1:
Input: garbage = ["G","P","GP","GG"], travel = [2,4,3]
Output: 21

Example 2:
Input: garbage = ["MMM","PGM","GP"], travel = [3,10]
Output: 37

Example 3:
Input: garbage = ["M","P","G"], travel = [2,5]
Output: 12
*/