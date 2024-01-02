DATE: 02-01-2024

## Problem 7: [Two Sum (Leetcode-1)](https://leetcode.com/problems/two-sum/)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

You may assume that each input would have **exactly one solution**, and you may not use the same element twice.

You can return the answer in any order.

### Examples

Example 1:

```bash
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
```

Example 2:

```bash
Input: nums = [3,2,4], target = 6
Output: [1,2]
```

Example 3:

```bash
Input: nums = [3,3], target = 6
Output: [0,1]
```

### Constraints:

1. `2 <= nums.length <= 10^4`
2. `-10^9 <= nums[i] <= 10^9`
3. `-10^9 <= target <= 10^9`
4. **Only one valid answer exists.**

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Adobe](https://leetcode.com/company/adobe), [Apple](https://leetcode.com/company/apple), [Microsoft](https://leetcode.com/company/microsoft), [Yahoo](https://leetcode.com/company/yahoo), [Bloomberg](https://leetcode.com/company/bloomberg), [Facebook](https://leetcode.com/company/facebook), [Uber](https://leetcode.com/company/uber), [Yandex](https://leetcode.com/company/yandex), [Spotify](https://leetcode.com/company/spotify), [Oracle](https://leetcode.com/company/oracle), [Accenture](https://leetcode.com/company/accenture), [Deloitte](https://leetcode.com/company/deloitte), [tcs](https://leetcode.com/company/tcs), [Tinkoff](https://leetcode.com/company/tinkoff), [IBM](https://leetcode.com/company/ibm), [wipro](https://leetcode.com/company/wipro), [Capgemini](https://leetcode.com/company/capgemini), [Careem](https://leetcode.com/company/careem), [Expedia](https://leetcode.com/company/expedia), [Cisco](https://leetcode.com/company/cisco), [Visa](https://leetcode.com/company/visa), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Morgan Stanley](https://leetcode.com/company/morgan-stanley), [Samsung](https://leetcode.com/company/samsung), [Barclays](https://leetcode.com/company/barclays), [BlackRock](https://leetcode.com/company/blackrock), [eBay](https://leetcode.com/company/ebay), [Nagarro](https://leetcode.com/company/nagarro), [Zillow](https://leetcode.com/company/zillow), [Accolite](https://leetcode.com/company/accolite), [Zoho](https://leetcode.com/company/zoho), [American Express](https://leetcode.com/company/american-express), [Walmart Labs](https://leetcode.com/company/walmart-labs), [Dell](https://leetcode.com/company/dell), [PayPal](https://leetcode.com/company/paypal), [JPMorgan](https://leetcode.com/company/jpmorgan), [VMware](https://leetcode.com/company/vmware), [Intel](https://leetcode.com/company/intel), [Salesforce](https://leetcode.com/company/salesforce), [Infosys](https://leetcode.com/company/infosys), [MakeMyTrip](https://leetcode.com/company/makemytrip), [ServiceNow](https://leetcode.com/company/servicenow), [Citadel](https://leetcode.com/company/citadel), [Qualcomm](https://leetcode.com/company/qualcomm), [ZScaler](https://leetcode.com/company/zscaler), [Zoom](https://leetcode.com/company/zoom), [Zomato](https://leetcode.com/company/zomato), [Info Edge](https://leetcode.com/company/info-edge), [turing](https://leetcode.com/company/turing), [Bank of America](https://leetcode.com/company/bank-of-america), [SAP](https://leetcode.com/company/sap), [Grab](https://leetcode.com/company/grab), [Intuit](https://leetcode.com/company/intuit), [Nvidia](https://leetcode.com/company/nvidia), [Twitter](https://leetcode.com/company/twitter), [Deutsche Bank](https://leetcode.com/company/deutsche-bank), [Capital One](https://leetcode.com/company/capital-one), [FactSet](https://leetcode.com/company/factset), [Cruise Automation](https://leetcode.com/company/cruise-automation), [Twitch](https://leetcode.com/company/twitch), [LinkedIn](https://leetcode.com/company/linkedin), [Airbnb](https://leetcode.com/company/airbnb), [Yelp](https://leetcode.com/company/yelp), [Dropbox](https://leetcode.com/company/dropbox)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Hash Table](https://leetcode.com/tag/hash-table)

**Similar Questions**:

- [3Sum (Medium)](https://leetcode.com/problems/3sum)
- [4Sum (Medium)](https://leetcode.com/problems/4sum)
- [Two Sum II - Input Array Is Sorted (Medium)](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted)
- [Two Sum III - Data structure design (Easy)](https://leetcode.com/problems/two-sum-iii-data-structure-design)
- [Subarray Sum Equals K (Medium)](https://leetcode.com/problems/subarray-sum-equals-k)
- [Two Sum IV - Input is a BST (Easy)](https://leetcode.com/problems/two-sum-iv-input-is-a-bst)
- [Two Sum Less Than K (Easy)](https://leetcode.com/problems/two-sum-less-than-k)
- [Max Number of K-Sum Pairs (Medium)](https://leetcode.com/problems/max-number-of-k-sum-pairs)
- [Count Good Meals (Medium)](https://leetcode.com/problems/count-good-meals)
- [Count Number of Pairs With Absolute Difference K (Easy)](https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k)
- [Number of Pairs of Strings With Concatenation Equal to Target (Medium)](https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target)
- [Find All K-Distant Indices in an Array (Easy)](https://leetcode.com/problems/find-all-k-distant-indices-in-an-array)
- [First Letter to Appear Twice (Easy)](https://leetcode.com/problems/first-letter-to-appear-twice)
- [Number of Excellent Pairs (Hard)](https://leetcode.com/problems/number-of-excellent-pairs)
- [Number of Arithmetic Triplets (Easy)](https://leetcode.com/problems/number-of-arithmetic-triplets)
- [Node With Highest Edge Score (Medium)](https://leetcode.com/problems/node-with-highest-edge-score)
- [Check Distances Between Same Letters (Easy)](https://leetcode.com/problems/check-distances-between-same-letters)
- [Find Subarrays With Equal Sum (Easy)](https://leetcode.com/problems/find-subarrays-with-equal-sum)
- [Largest Positive Integer That Exists With Its Negative (Easy)](https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative)
- [Number of Distinct Averages (Easy)](https://leetcode.com/problems/number-of-distinct-averages)
- [Count Pairs Whose Sum is Less than Target (Easy)](https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target)

### Solution 1

```cpp
/*
Optimal Approach: Two-pass Hash Table
Time complexity: O(N)
Space complexity: O(N)
Author: github.com/BCAPATHSHALA
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // First pass: Build the hash table
        unordered_map<int,int> mapping;
        for(int i=0; i<nums.size(); i++){
            mapping[nums[i]] = i;
        }

        // Second pass: Find the second number
        for(int i=0; i<nums.size(); i++){
            int firstNum = nums[i];
            int secondNum = target - firstNum;
            if(mapping.count(secondNum) && mapping[secondNum] != i){
                return {i, mapping[secondNum]};
            }
        }

        // No solution found
        return {};
    }
};
```

### Solution 2

```cpp
/*
Optimal Approach: One-pass Hash Table
Time complexity: O(N)
Space complexity: O(N)
Author: github.com/BCAPATHSHALA
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> mapping;

        // First pass: Find the second number from hash table
        for(int i=0; i<nums.size(); i++){
            int firstNum = nums[i];
            int secondNum = target - firstNum;

            if(mapping.count(secondNum)){
                return {i, mapping[secondNum]};
            }
            mapping[nums[i]] = i;
        }

        // No solution found
        return {};
    }
};
```

### Solution 3

```cpp
/*
Optimal Approach: Two pointer approach
Time complexity: O(N LogN)
Space complexity: O(N)
Author: github.com/BCAPATHSHALA
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Step 1: store value with its index in an array
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); i++) {
            v.push_back({nums[i], i});
        }
        // Step 2: sort array v
        sort(v.begin(), v.end());

        // Step 3: apply two pointer approach
        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {
            int sum = v[start].first + v[end].first;

            // If our current sum is equal to target, return ans
            if (sum == target) {
                return {v[start].second, v[end].second};
            }
            // If our current sum is too large, move closer to the left
            else if (sum > target) {
                end--;
            }
            // If our current sum is too small, move closer to the right
            else {
                start++;
            }
        }
        return {}; // No solution found!
    }
};
```
