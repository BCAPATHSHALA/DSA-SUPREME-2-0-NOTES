// 3. Detect cycle in an directed graph using DFS

/*
Problem Statement:
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

Question Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
*/

class Solution {
  public:
  
    bool checkCyclicDFS(int src, unordered_map<int, bool> &visited, 
    unordered_map<int, bool> &DFSTrack, vector<int> adjList[]){
        // Initial State
        visited[src] = true;
        DFSTrack[src] = true;
        
        // Recursive Call
        for(auto child: adjList[src]){
            if(!visited[child]){
                bool ans = checkCyclicDFS(child, visited, DFSTrack, adjList);
                if(ans == true){
                    return true;
                }
            }
            if(visited[child] == 1 && DFSTrack[child] == 1){
                // Cycle present hai
                return true;
            }
        }
        
        // BackTracking: Me Yani Par Hamesha Galti Karoonga
        DFSTrack[src] = false;
        // Cycle present nhi hai
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
       unordered_map<int,bool> vis;
       unordered_map<int,bool> dfsTrack;
       
       for(int node=0; node<V; node++) {
           if(!vis[node]) {
               bool isCyclic = checkCyclicDFS(node, vis, dfsTrack, adj);
               if(isCyclic) {
                   return true;
               }
           }
       }
       return false;
    }
};