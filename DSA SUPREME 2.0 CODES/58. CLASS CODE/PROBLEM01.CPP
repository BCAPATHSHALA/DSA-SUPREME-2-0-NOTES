// 4. Graph Creation Using Adjacency  List

#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

//! Create Unweighted Graph
class Graph{
    public:
        unordered_map<int, list<int>> adjList;

        void addEdge(int u, int v, int direction){
            if(direction == 1){
                // Directed Graph: u se v ki taraf ek edge hai only "u-->v"
                adjList[u].push_back(v);
            }
            else{
                // Undirected Graph: u se v ki taraf do edge hai "u-->v" and "v-->u"
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
            cout << "Printing adjList:" << endl;
            printAdjList();
            cout<<endl;
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
};

int main(){
    // Create Unweighted Graph Object g
    Graph g;
    // Insert Edges to adjList
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(1,3,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(4,5,1);
    g.addEdge(5,3,1);
    return 0;
}

/*
Expected Output:
Printing adjList:
0 --> { 1,  }

Printing adjList:
1 --> { 2,  }
0 --> { 1,  }

Printing adjList:
1 --> { 2, 3,  }
0 --> { 1,  }

Printing adjList:
2 --> { 3,  }
1 --> { 2, 3,  }
0 --> { 1,  }

Printing adjList:
3 --> { 4,  }
2 --> { 3,  }
1 --> { 2, 3,  }
0 --> { 1,  }

Printing adjList:
4 --> { 5,  }
3 --> { 4,  }
2 --> { 3,  }
1 --> { 2, 3,  }
0 --> { 1,  }

Printing adjList:
5 --> { 3,  }
4 --> { 5,  }
3 --> { 4,  }
2 --> { 3,  }
1 --> { 2, 3,  }
0 --> { 1,  }
*/