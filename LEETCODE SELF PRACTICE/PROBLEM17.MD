DATE: 23-02-2024

## Problem 17: [ Cheapest Flights Within K Stops (Leetcode-787) ](https://leetcode.com/problems/cheapest-flights-within-k-stops)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

There are `n` cities connected by some number of flights. You are given an array `flights` where `flights[i] = [fromi, toi, pricei]` indicates that there is a flight from city `fromi` to city `toi` with cost `pricei`.

You are also given three integers `src`, `dst`, and `k`, return the **cheapest price** from `src` to `dst` with at most `k` stops. If there is no such route, return `-1`.

## Examples

Example 1:

<p align="center">
  <img src="https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-3drawio.png" alt="Example 1">
</p>

```bash
Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
```

Example 2:

<p align="center">
  <img src="https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-1drawio.png" alt="Example 2">
</p>

```bash
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
```

Example 3:

<p align="center">
  <img src="https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-2drawio.png" alt="Example 3">
</p>

```bash
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
```

## Constraints:

1. `1 <= n <= 100`
2. `0 <= flights.length <= (n * (n - 1) / 2)`
3. `flights[i].length == 3`
4. `0 <= fromi, toi < n`
5. `fromi != toi`
6. `1 <= pricei <= 10^4`
7. `There will not be any multiple flights between two cities.`
8. `0 <= src, dst, k < n`
9. `src != dst`

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Heap](https://leetcode.com/tag/heap/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

**Similar Questions**:

- [Maximum Vacation Days (Hard)](https://leetcode.com/problems/maximum-vacation-days/)

## Solution 1

```cpp
/*
Optimal approach: Using Dijkstra Algorithm
Time Complexity:  O(VEK)
Space Complexity: O(V + E + VK)
Author: github.com/BCAPATHSHALA

Where
V be the number of vertices (cities),
E be the number of edges (flights),
K be the maximum number of stops allowed
*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Step 1: create the adjList
        vector<pair<int,int>> adjList[n];
        for (auto &flight : flights) {
            adjList[flight[0]].push_back({flight[1], flight[2]});
        }

        // Step 2: Create array to store the cheapest price/shortest distance from source to destination
        vector<int> dist(n, INT_MAX);
        // Step 3: Create queue to get the minimum distance node/city first
        queue<pair<int,pair<int,int>>> pq;

        // Initial State
        dist[src]=0;
        pq.push({src,{0,0}}); // src, stop, dist

        // Distance updation logic
        while(!pq.empty()){
            int frontNode = pq.front().first;
            int stops = pq.front().second.first;
            int frontDist = pq.front().second.second;
            pq.pop();

            for(auto &nbrPair: adjList[frontNode]){
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;

                // Now check the distance: ki mujhe new distance update krna hai ya nhi
                if((frontDist + nbrDist < dist[nbrNode]) && stops <= k){
                    // Found the new distance
                    // Update dist array for new distance
                    dist[nbrNode] = frontDist + nbrDist;
                    // Update the new entry in the queue for new distance and stops
                    pq.push({nbrNode, {stops + 1, frontDist + nbrDist}});
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
```
