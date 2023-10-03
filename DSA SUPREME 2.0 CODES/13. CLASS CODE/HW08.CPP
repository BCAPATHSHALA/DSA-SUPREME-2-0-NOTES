// HW 08: EKO SPOJ
/*
Problem Statement:
LAKSHAY BHAIYA needs to chop down M metres of wood.
It is an easy job for him since he has a nifty new wood-cutting machine that can take down forests like wildfire.
However, LAKSHAY BHAIYA is only allowed to cut a single row of trees.

LAKSHAY BHAIYA's machine works as follows:
He sets a height parameter H (in meters), and the machine raises a giant sawblade to that height 
and cuts off all tree parts higher than H (of course, trees not higher than H meters remain intact). 
He then takes the parts that were cut off.

He is ecologically minded, so he doesn't want to cut off more wood than necessary. 
That's why he wants to set his sawblade as high as possible. 
Help LAKSHAYA find the 'maximum integer height of the sawblade' that still allows him to cut off 'at least M metres of wood'.

---------------------------------------------------------------------------------------------------------------------------------
Example 01:
Input:
4 7
20 15 10 17

Output:
15

📌Observation:
Number of trees/Array's size => N = 4
At least M metres of wood => M = 7
Trees Array => trees [20, 15, 10, 17]

1st tree ki height = trees[0] = 20 meters
2nd tree ki height = trees[1] = 15 meters
3rd tree ki height = trees[2] = 10 meters
4rt tree ki height = trees[3] = 17 meters

🖊️PROBLEM KYA HAI: We have to find maximum integer height of sawblade that still allows to cut off at least M meters of wood.

hame sawblade ki height ko aisa rakhna hai ki trees ko iss tarike se kate jo required height of wood se kam to bilkul na ho 
or usse bahut jyada bhi na ho. 
To meaning yeh niklta hai ki hame sawblade ki highest maximum height me se (Possible)least maximum height btani hai.

📌agar saw blade ki height = 0 meter hai to => ek bhi tree jungle nhi rahega to hum kah skte hai ki yeh least minimum height hai 
(wood height = 20+15+10+17 = 62 meters)

📌agar sow blade ki height = 20 meter hai to => all trees will save tu hum kah skte hai ki yeh highest maximum height hai 
(wood height = 0 meters)

Required (sow blade height) answer always less than or equal to 20 meters in this case Janha par M meters of wood ya usse thodi jyada M meters of wood milegi. DRY RUN KARNE SE OR BHI SAMJH AYEGA ABHI...

---------------------------------------------------------------------------------------------------------------------------------------
OPTIMAL APPROACH: Define search space and predicate function 
Step 01: Find maximum height of tree to create search space's end point (highest maximum height of sawblade)
Step 02: Now, Applying Binary Search on search space BinarySearch()
Step 03: create predicate function isPossibbleSol()

---------------------------------------------------------------------------------------------------------------------------------------
Time Complexity: O(N*log(end)), Here N is size of array trees and end is the maximum heighted tree in array
Space Complexity: O(1), no extra space used

---------------------------------------------------------------------------------------------------------------------------------------
Resource: https://www.spoj.com/problems/EKO/
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Step 03: Create predicate function
bool isPossibleSol(vector<long long int> trees,long long int m,long long int mid){
    long long int totalWood = 0;
    for(int i=0; i<trees.size(); i++){
        if(trees[i] > mid){
            totalWood = totalWood + (trees[i]-mid);
            if(totalWood >= m){
                return true;
            }
        }
    }
    return false;
}

// Step 02: Now, Applying Binary Search
int BinarySearch(vector<long long int> trees,long long int m,long long int end){
    long long int start = 0, ansH = -1, mid = start + (end - start)/2;

    while(start<=end){
        // Step 03: create predicate function isPossibbleSol()
        if(isPossibleSol(trees,m,mid)){
            ansH = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return ansH;

}

// EKO SPOJ
int maxSawBladeHeight(vector<long long int> trees,long long int m){
    // Step 01: Find maximum height of tree
    long long int end = *max_element(trees.begin(), trees.end());

    // Step 02: Now, Applying Binary Search
    long long int sawbladeMaxHeight = BinarySearch(trees,m,end);

    return sawbladeMaxHeight;
}

int main(){
    long long int n, m;
    cin>>n>>m;
    vector<long long int> trees;
    while(n--){
        long long int height;
        cin>> height;
        trees.push_back(height);
    }

    cout <<maxSawBladeHeight(trees,m);
    return 0;
}