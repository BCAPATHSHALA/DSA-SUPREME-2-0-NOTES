// 2. Course Schedule II (Leetcode-210)

/*
Problem Statement:
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that 
you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return the ordering of courses you should take to finish all courses. 
If there are many valid answers, return any of them. 
If it is impossible to finish all courses, return an empty array.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So the correct course order is [0,1].

Example 2:
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. 
To take course 3 you should have finished both courses 1 and 2. 
Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

Example 3:
Input: numCourses = 1, prerequisites = []
Output: [0]

Constraints:
1. 1 <= numCourses <= 2000
2. 0 <= prerequisites.length <= numCourses * (numCourses - 1)
3. prerequisites[i].length == 2
4. 0 <= ai, bi < numCourses
5. ai != bi
6. All the pairs [ai, bi] are distinct.
*/


class Solution {
public:
    void topoSortUsingBFS(int n, vector<int> &topoOrder, unordered_map<int, list<int>> &adjList){
        queue<int> q;
        unordered_map<int,int> indegree;

        // Step 1: initialize the indegree
        for(auto i: adjList){
            for(auto neighbour: i.second){
                indegree[neighbour]++;
            }
        }

        // Step 2: push all nodes jinki indegree zero hai
        for(int node = 0; node < n; node++){
            if(indegree[node] == 0){
                q.push(node);
            }
        }

        // Step 3: BFS on queue to print the order dependency wise
        while(!q.empty()){
            auto frontNode = q.front();
            q.pop();
            topoOrder.push_back(frontNode);

            for(auto neighbour: adjList[frontNode]){
                indegree[neighbour]--;

                // check neighbour node indegree is zero or not
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Create adjList first
        unordered_map<int, list<int>> adjList;
        for(auto i: prerequisites){
            int u = i[0];
            int v = i[1];
            adjList[v].push_back(u);
        }

        // Create the topo order for checking all courses are finished or not
        vector<int> topoOrder;
        topoSortUsingBFS(numCourses, topoOrder, adjList);

        if(topoOrder.size() == numCourses){
            // Cycle does not present: means all course are finished
            return topoOrder;
        }
        else{
            // Cycle does present: means all course are never finished
            return {};
        }
    }
};