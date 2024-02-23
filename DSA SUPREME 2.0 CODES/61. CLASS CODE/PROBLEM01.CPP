// 1. Shortest path in a weighted directed graph using DFS (SSSP Algorithms)


/*
INPUT ME HAME EK WEIGHTED UNDIRECTED GRAPH AND EK SRC NODE OF INPUT GRAPH MILEGA
USS EK SRC NODE KE BASIS PAR ENTIRE NODES OF INPUT GRAPH KA SHORTEST DISTANCE/PATH FIND KARNA HAI.

🚀 SSSPA: SINGLE SOURCE SHORTEST PATH ALGORITHMS
*/

#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>
#include<limits.h>
#include<list>

using namespace std;

class Graph
{
    public:
        unordered_map<int, list<pair<int, int>>> adjList;

        void addEdges(int u, int v, int wt, int direction){
            if(direction == 1){
                // Directed Graph
                adjList[u].push_back({v,wt});
            }
            else{
                // Undirected Graph
                adjList[u].push_back({v,wt});
                adjList[v].push_back({u,wt});
            }
        }

        void printAdjList(){
            for(auto i: adjList){
                cout << i.first << " : { ";
                for(auto j: i.second){
                    cout << "( " << j.first << ", " << j.second << " ), ";
                }
                cout << " }" << endl;
            }
        }

        // Step 1: Create topological order using DFS
        void topologicalSortUsingDFS(int src, unordered_map<int, bool> &visited, stack<int> &topoOrder){
            // Initial state
            visited[src] = true;

            for(auto nbrPair: adjList[src]){
                int nbrNode = nbrPair.first;
                // int nbrDist = nbrPair.second;
                if(!visited[nbrNode]){
                    topologicalSortUsingDFS(nbrNode, visited, topoOrder);
                }
            }
            // Push into stack tocreate the topoOrder
            topoOrder.push(src);
        }

        // Step 2: Store all shortest distances from src node using topoOrder
        void shortestPath(stack<int> &topoOrder, int n){
            // Create an vector to store the shortest distance of each nodes from src node
            vector<int> dist(n, INT_MAX);

            // A: initial state
            int src = topoOrder.top();
            topoOrder.pop();
            dist[src] = 0;

            // B: Goto adjList to get the all childs of src node
            for(auto nbrPair: adjList[src]){
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;
                // C: Update the distace when 
                if(dist[src] + nbrDist < dist[nbrNode]){
                    dist[nbrNode] = dist[src] + nbrDist;
                }
            }

            // Apply the same Step A, B, & C to all remaining node
            while (!topoOrder.empty()){
                // A: initial state
                int src = topoOrder.top();
                topoOrder.pop();

                // B: Goto adjList to get the all childs of src node
                for(auto nbrPair: adjList[src]){
                    int nbrNode = nbrPair.first;
                    int nbrDist = nbrPair.second;
                    // C: Update the distace when 
                    if(dist[src] + nbrDist < dist[nbrNode]){
                        dist[nbrNode] = dist[src] + nbrDist;
                    }
                }
            }

            // Step 3: Print all shortest distance from created 
            cout << "Print all shortest distance: " << endl;
            for(auto i: dist){
                cout << i << " ";
            }
        }
};

int main(){
    Graph g;
    g.addEdges(0,1,5,1);
    g.addEdges(0,2,3,1);
    g.addEdges(2,1,2,1);
    g.addEdges(1,3,3,1);
    g.addEdges(2,3,5,1);
    g.addEdges(2,4,6,1);
    g.addEdges(4,3,1,1);

    g.printAdjList();

    int src = 0;
    unordered_map<int, bool> visited; 
    stack<int> topoOrder;
    g.topologicalSortUsingDFS(src, visited, topoOrder);

    // cout << "Printing the topo order" << endl;
    // while(!topoOrder.empty()){
    //     cout << topoOrder.top() << " ";
    //     topoOrder.pop();
    // }

    int n = 5;
    g.shortestPath(topoOrder, n);

    return 0;
}