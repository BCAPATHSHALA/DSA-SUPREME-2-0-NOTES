// 📂 17. Traverse Graph Using DFS

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

        void dfsTraversal(T src, unordered_map<T,bool> &visited){
            // Recursive Call
            visited[src] = true;
            cout << src << " ";

            // Goto adjList to get the child list of frontNode
            for(auto nbrs: adjList[src]){
                T child = nbrs.first;
                // check child is visited or not
                if(!visited[child]){
                    dfsTraversal(child, visited);
                }
            }
        }
};

int main(){
    Graph<char> g;
    g.addEdge('a','b',5,0);
    g.addEdge('a','c',7,0);
    g.addEdge('b','d',6,0);
    g.addEdge('c','e',1,0);
    g.addEdge('c','f',81,0);

    // Visited Child
    unordered_map<char,bool> visited;
    for(char node = 'a'; node <= 'f'; node++){
        if(!visited[node]){
            g.dfsTraversal(node, visited);
        }
    }
    return 0;
}

/*
Expected Output:
a b d c e f 
*/