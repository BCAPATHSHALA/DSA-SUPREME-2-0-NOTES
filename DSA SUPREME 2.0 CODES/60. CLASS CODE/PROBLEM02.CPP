// 2. Topological Sorting with BFS

#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>

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

        void printAdjList(){
            for(auto i: adjList){
                cout << i.first << " --> { ";
                for(auto neighbour: i.second){
                    cout << neighbour << ", ";
                }
                cout << " }" << endl;
            }
        }

        void topoSortUsingBFS(int n){
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
                cout << frontNode << "-> ";

                for(auto neighbour: adjList[frontNode]){
                    indegree[neighbour]--;

                    // check neighbour node indegree is zero or not
                    if(indegree[neighbour] == 0){
                        q.push(neighbour);
                    }
                }
            }
        }
};

int main(){
    Graph g;
    g.addEdges(0,1,1);
    g.addEdges(1,2,1);
    g.addEdges(2,3,1);
    g.addEdges(2,4,1);
    g.addEdges(3,5,1);
    g.addEdges(4,5,1);
    g.addEdges(5,6,1);
    g.addEdges(5,7,1);

    g.printAdjList();

    int n = 8;
    g.topoSortUsingBFS(n);
    return 0;
}

/*
Expected output:
6 --> { 7,  }
4 --> { 6,  }
5 --> { 6,  }
3 --> { 4, 5,  }
2 --> { 3,  }
1 --> { 2,  }
0 --> { 1,  }
Print topological order from stack
0-> 1-> 2-> 3-> 4-> 5-> 6-> 7-> 
*/