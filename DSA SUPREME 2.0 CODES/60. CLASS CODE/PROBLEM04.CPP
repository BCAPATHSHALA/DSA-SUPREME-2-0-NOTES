// 4. Shortest path in an undirected graph using BFS
#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

class Graph
{
    public:
        unordered_map<int, list<int>> adjList;

        void addEdges(int u, int v, bool direction){
            if(direction == 1){
                // Directed graph
                adjList[u].push_back(v);
            }
            else{
                // Undirected graph
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }

        void shortestPathUsingBFS(int src, int dist){
            queue<int> q;
            unordered_map<int, bool> visited;
            unordered_map<int,int> parent;

            // Initial state
            q.push(src);
            visited[src] = true;
            parent[src] = -1;

            while(!q.empty()){
                auto frontNode = q.front();
                q.pop();

                for(auto neighbour: adjList[frontNode]){
                    // check neighbour node is visited or not
                    if(!visited[neighbour]){
                        q.push(neighbour);
                        visited[neighbour] = true;
                        parent[neighbour] = frontNode;
                    }
                }
            }

            // Ab parent map banakar ready hai
            // We are making the shortest path through parent map
            vector<int> shortestPath; 
            while(dist != -1){
                shortestPath.push_back(dist);
                dist = parent[dist];
            }

            // Reverse the shortestPath
            reverse(shortestPath.begin(), shortestPath.end());

            // Print the shoretest Path
            for(auto i: shortestPath){
                cout << i << " ";
            }
        }
};

int main(){
    Graph g;
    g.addEdges(0,1,0);
    g.addEdges(1,2,0);
    g.addEdges(2,5,0);
    g.addEdges(0,3,0);
    g.addEdges(3,5,0);
    g.addEdges(0,4,0);
    g.addEdges(4,6,0);
    g.addEdges(6,5,0);

    int src = 0;
    int dist = 5;
    g.shortestPathUsingBFS(src, dist);    
    return 0;
}

// src and dist are input value
// Expected output: 0 3 5 