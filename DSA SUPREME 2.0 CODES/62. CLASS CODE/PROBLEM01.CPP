// 1. Course Schedule (Leetcode-207)

/*
Problem Statement:
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that 
you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return true if you can finish all courses. Otherwise, return false.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. 
So it is impossible.

Constraints:
1. 1 <= numCourses <= 2000
2. 0 <= prerequisites.length <= 5000
3. prerequisites[i].length == 2
4. 0 <= ai, bi < numCourses
5. All the pairs prerequisites[i] are unique.
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
            return true;
        }
        else{
            // Cycle does present: means all course are never finished
            return false;
        }
    }
};