// 📂 16. Traverse Graph Using BFS

#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;

template<typename T>
class Graph{
    public:
        unordered_map<T, list<pair<T, int>>> adjList;

        void addEdge(T u, T v, int wt, int direction){
            if(direction == 1){
                adjList[u].push_back({v,wt});
            }
            else{
                adjList[u].push_back({v,wt});
                adjList[v].push_back({u,wt});
            }
        }

        void bfsTraversal(T src, unordered_map<T,bool> &visited){
            // AdjList Alrady Data Menber Me Hai
            // Queue
            queue<T> q;

            // Initial State
            q.push(src);
            visited[src] = true;

            while (!q.empty())
            {
                // Step 1: Save front, print it, and pop it
                T frontNode = q.front();
                cout << frontNode << " ";
                q.pop();

                // Step 2: Goto adjList to get the child list of frontNode
                for(auto nbrs: adjList[frontNode]){
                    T child = nbrs.first;

                    // Step 3: check child is visited or not
                    if(!visited[child]){
                        q.push(child);
                        visited[child] = true;
                    }
                }
            }
            
        }
};

int main(){
    Graph<char> g;
    g.addEdge('a','b',5,0);
    g.addEdge('a','c',7,0);
    g.addEdge('b','d',6,0);
    g.addEdge('e','f',81,0);

    // Visited Child
    unordered_map<char,bool> visited;
    for(char node = 'a'; node <= 'f'; node++){
        if(!visited[node]){
            g.bfsTraversal(node, visited);
        }
    }
    return 0;
}

/*
Expected Output:
a b c d e f 
*/