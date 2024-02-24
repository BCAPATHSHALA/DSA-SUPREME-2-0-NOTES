DATE: 22-02-2024

## Problem 16: [ Find the Town Judge (Leetcode-997) ](https://leetcode.com/problems/find-the-town-judge/)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

In a town, there are `n` people labeled from `1` to `n`. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

- The town judge trusts nobody.
- Everybody (except for the town judge) trusts the town judge.
- There is exactly one person that satisfies properties 1 and 2.

You are given an array `trust` where `trust[i] = [ai, bi]` representing that the person labeled `ai` trusts the person labeled `bi`. If a trust relationship does not exist in `trust` array, then such a trust relationship does not exist.

Return the label of the town judge if the town judge exists and can be identified, or return `-1` otherwise.

## Examples

Example 1:

```bash
Input: n = 2, trust = [[1,2]]
Output: 2
```

Example 2:

```bash
Input: n = 3, trust = [[1,3],[2,3]]
Output: 3
```

Example 3:

```bash
Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
```

Example 4:

```bash
Input: n = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3
```

Example 5:

```bash
Input: n = 3, trust = [[1,2],[2,3]]
Output: -1
```

## Constraints:

1. `1 <= n <= 1000`
2. `0 <= trust.length <= 10^4`
3. `trust[i].length == 2`
4. All the pairs of `trust` are **unique**.
5. `ai != bi`
6. `1 <= ai, bi <= n`

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Graph](https://leetcode.com/tag/graph/)

**Similar Questions**:
* [Find the Celebrity (Medium)](https://leetcode.com/problems/find-the-celebrity/)

## Solution 1

```cpp
/*
Optimal approach: Using Array Only
Time Complexity: O(N)
Space Complexity: O(N)
Author: github.com/BCAPATHSHALA
*/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // Step 1: create array of size n+1 to store the trust count
        vector<int> trustV(n + 1, 0);

        // Step 2: store the trust count for each people
        for (auto relation : trust) {
            trustV[relation[0]]--;  // outDegree
            trustV[relation[1]]++;  // InDegree
        }

        // Step 3: traverse from 1 to n people on trustV
        // to return a town Judge when "Trust Count == N-1"
        for (int i = 1; i <= n; i++) {
            if (trustV[i] == n-1) {
                return i;
            }
        }

        // Step 3: town does not have a judge because all people trust to each other or
        // at least 1 or more people trust to each other
        return -1;
    }
};
```

## Solution 2

```cpp
/*
Brute force approach: Using Graph
Time Complexity: O(N^2)
Space Complexity: O(N)
Author: github.com/BCAPATHSHALA
*/
class Solution {
public:
    // Function to add edges for each node
    void addEdges(int u, int v, unordered_map<int, list<int>> &adjList){
        // Directed graph
        adjList[u].push_back(v);
    }

    int findJudge(int n, vector<vector<int>>& trust) {

        // Step 1: Calling addEdges function to create adjList
        unordered_map<int, list<int>> adjList;
        for (auto relation : trust) {
            addEdges(relation[0], relation[1], adjList);
        }

        // Step 2: Initialize the indegree
        unordered_map<int,int> indegree;
        for(auto i: adjList){
            for(auto neighbour: i.second){
                indegree[neighbour]++;
            }
        }

        // Corner case : when all people are trusting on all
        if(adjList.size() == n){
            return -1;
        }

        // Step 3: Traverse on indegree to return the Town Judge
        // when indegree == n-1
        for(int node = 1; node <= n; node++){
            if(indegree[node] == n-1){
                std::cout<<node<<" -> "<<indegree[node]<<endl;
                return node;
            }
        }

        // Noramal case: when all people are trusting on all
        return -1;
    }
};
```
