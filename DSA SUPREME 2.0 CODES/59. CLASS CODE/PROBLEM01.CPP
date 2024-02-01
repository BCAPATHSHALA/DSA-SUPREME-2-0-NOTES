// 1. Detect cycle in an undirected graph using BFS

/*
Intuition: 
The intuition behind this is to check for the visited element if it is found again, 
this means the cycle is present in the given undirected graph.
*/

#include<iostream>
#include<list>
#include<queue>
#include<unordered_map>
using namespace std;

template<typename T>
class Graph{
    public:
        unordered_map<T, list<T>> adjList;

        void addEdge(T u, T v, int direction){
            if(direction == 1){
                adjList[u].push_back(v);
            }
            else{
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }

        void printAdjList(){
            for(auto i: adjList){
                cout << i.first << " --> { ";
                for(auto neighbour: i.second){
                    cout << neighbour << ", ";
                }
                cout << " }" << endl;
            }
        }

        bool checkCycleUndirectedBFS(T src, unordered_map<T,bool> &visited){
            // AdjList Graph members me already present hai
            // Parent
            unordered_map<T,T> parent;
            // Queue
            queue<T> q;

            // Initial State
            q.push(src);
            visited[src] = true;
            parent[src] = -1;

            while (!q.empty())
            {
                T frontNode = q.front();
                q.pop();

                for(auto child: adjList[frontNode]){
                    if(!visited[child]){
                        // Child Not Visited Yet
                        q.push(child);
                        visited[child] = true;
                        parent[child] = frontNode;
                    }
                    else if(visited[child] && child == parent[frontNode]){
                        // Child Already Visited && Skip BFS Call
                        continue;
                    }
                    else if(visited[child] && child != parent[frontNode]){
                        // Child Already Visited && Cycle Present Hai
                        return true;
                    }
                }
            }
            // Cycle Does Not Present
            return false;          
        }
};

int main(){
    Graph<int> g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,5,0);
    g.addEdge(2,4,0);
    g.addEdge(4,3,0);
    g.addEdge(3,1,0);

    cout << "Printing adjList:" << endl;
    g.printAdjList();

    // Visited
    unordered_map<int,bool> visited;
    for(int i=0; i<=5; i++){
        if(!visited[i]){
           bool ans = g.checkCycleUndirectedBFS(i,visited);
           if(ans == true){
            cout<<"Cycle Present Hai" << endl;
           }
           else{
            cout<<"Cycle Absent Hai" << endl;
           }
        }
    }
    return 0;
}

/*
OUTPUT 1:
Printing adjList:
3 --> { 4, 1,  }
4 --> { 2, 3,  }
5 --> { 2,  }
2 --> { 1, 5, 4,  }
1 --> { 0, 2, 3,  }
0 --> { 1,  }
Cycle Present Hai

OUTPUT 2:
Printing adjList:
2 --> { 1, 0,  }
1 --> { 0, 2,  }
0 --> { 1, 2,  }
Cycle Present Hai

OUTPUT 3:
Printing adjList:
1 --> { 0,  }
0 --> { 1,  }
Cycle Absent Hai
*/


// Solve On GFG Using BFS
class Solution {
  public:
    bool checkCycleUndirectedBFS(int src, unordered_map<int,bool> &visited, vector<int> adjList[]){
            // Parent
            unordered_map<int, int> parent;
            // Queue
            queue<int> q;

            // Initial State
            q.push(src);
            visited[src] = true;
            parent[src] = -1;

            while (!q.empty())
            {
                int frontNode = q.front();
                q.pop();

                for(auto child: adjList[frontNode]){
                    if(!visited[child]){
                        // Child Not Visited Yet
                        q.push(child);
                        visited[child] = true;
                        parent[child] = frontNode;
                    }
                    else if(visited[child] && child == parent[frontNode]){
                        // Child Already Visited && Skip BFS Call
                        continue;
                    }
                    else if(visited[child] && child != parent[frontNode]){
                        // Child Already Visited && Cycle Present Hai
                        return true;
                    }
                }
            }
            // Cycle Does Not Present
            return false;          
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {

        // Visited
        unordered_map<int,bool> visited;
        for(int i=0; i<V; i++){
            if(!visited[i]){
               bool ans = checkCycleUndirectedBFS(i,visited,adj);
               if(ans == true){
                   return true;
               }
            }
        }
        return false;
    }
};