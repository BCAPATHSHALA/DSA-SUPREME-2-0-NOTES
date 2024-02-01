// 2. Detect cycle in an undirected graph using DFS

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

        bool checkCycleUndirectedDFS(T src, unordered_map<T,bool> &visited, int parent){
            // AdjList Graph members me already present hai
            // Initial State
            visited[src] = true;

            for(auto child: adjList[src]){
                    if(!visited[child]){
                        // Child Not Visited Yet
                        bool ans = checkCycleUndirectedDFS(child, visited, src);
                        if(ans == true){
                            return true;
                        }
                    }
                    else if(visited[child] && child == parent){
                        // Child Already Visited && Skip DFS Call
                        continue;
                    }
                    else if(visited[child] && child != parent){
                        // Child Already Visited && Cycle Present Hai
                        return true;
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
           int parent = -1;
           bool ans = g.checkCycleUndirectedDFS(i,visited,parent);
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
        bool checkCycleUndirectedDFS(int src, unordered_map<int,bool> &visited, int parent, vector<int> adjList[]){
            // Initial State
            visited[src] = true;

            for(auto child: adjList[src]){
                    if(!visited[child]){
                        // Child Not Visited Yet
                        bool ans = checkCycleUndirectedDFS(child, visited, src, adjList);
                        if(ans == true){
                            return true;
                        }
                    }
                    else if(visited[child] && child == parent){
                        // Child Already Visited && Skip DFS Call
                        continue;
                    }
                    else if(visited[child] && child != parent){
                        // Child Already Visited && Cycle Present Hai
                        return true;
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
               int parent = -1;
               bool ans = checkCycleUndirectedDFS(i,visited,parent,adj);
               if(ans == true){
                   return true;
               }
            }
        }
        return false;
    }
};