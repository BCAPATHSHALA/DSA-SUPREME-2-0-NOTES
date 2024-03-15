// 3. Floyd Warshall Algorithm

/*
What is Floyd–Warshall algorithm:
Basically, the Floyd Warshall algorithm is a multi-source shortest path algorithm and it helps to detect negative cycles as well. 
The shortest path between node u and v necessarily means the path(from u to v) for which the sum of the edge weights is minimum.

Note: Dijkstra’s Shortest Path algorithm and Bellman-Ford algorithm are single-source shortest path algorithms.

Where to use Floyd–Warshall algorithm:
Floyd–Warshall algorithm can be used to find the shortest paths between all pairs of vertices in a directed weighted graph. 
It can also be used to find the shortest cycle in both directed and undirected graphs.

Note:  It also doesn't work for graphs with negative cycles, where the sum of the edges in a cycle is negative.

Working flow of Floyd–Warshall algorithm:
The algorithm works by checking every possible path between every possible node, and then choosing the shortest one.

Why use "1e9" instead of "INT_MAX":
Using 1e9 ensures that we are within the safe range of integer values and avoids potential overflow problems like
*/

#include<iostream>
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

        void floydWarshal(int n){
            // Step 1: initial state
            vector<vector<int>> dist(n, vector<int>(n, 1e9));

            // Step 2: fill diagonal cell with 0 distance from src to src
            for(int i=0; i<n; i++){
                dist[i][i] = 0;
            }

            // Step 3: goto adjList to fill distance cell with the given weight of graph from u to v
            for(auto a: adjList){
                for(auto b: a.second){
                    int u = a.first;
                    int v = b.first;
                    int wt = b.second;
                    dist[u][v] = wt;
                }
            }

            // Step 4: main logic -> helper node (Helper node is intermediate node between source and destination)
            for(int helper = 0; helper < n; helper++){
                for(int src = 0; src < n; src++){
                    for(int dest = 0; dest < n; dest++){
                        dist[src][dest] = min(dist[src][dest], dist[src][helper]+dist[helper][dest]);
                    }
                }
            }

            // Printing the distance array
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    cout<<dist[i][j]<<" ";
                }
                cout << endl;
            }
        }

};

int main(){
    Graph g;
    g.addEdges(0,1,3,1);
    g.addEdges(0,3,5,1);
    g.addEdges(3,2,2,1);
    g.addEdges(2,1,1,1);
    g.addEdges(1,3,4,1);
    g.addEdges(1,0,2,1);

    int n = 4;
    g.floydWarshal(n);
    return 0;
}

/*
Helper: 0
0, 3, ∞, 5, 
2, 0, ∞, 4, 
∞, 1, 0, ∞, 
∞, ∞, 2, 0, 


Helper: 1
0, 3, ∞, 5, 
2, 0, ∞, 4, 
3, 1, 0, 5, 
∞, ∞, 2, 0, 


Helper: 2
0, 3, ∞, 5, 
2, 0, ∞, 4, 
3, 1, 0, 5, 
5, 3, 2, 0, 


Helper: 3
0, 3, 7, 5, 
2, 0, 6, 4, 
3, 1, 0, 5, 
5, 3, 2, 0, 

Printing distance array
0 3 7 5 
2 0 6 4 
3 1 0 5 
5 3 2 0 
*/