// 4. Graph Creation Using Adjacency  List

#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

//! Create Weighted Graph
class Graph{
    public:
        unordered_map<int, list<pair<int, int>>> adjList;

        void addEdge(int u, int v, int wt, int direction){
            if(direction == 1){
                // Directed Graph: u se v ki taraf ek edge hai only "u-->v"
                adjList[u].push_back({v,wt});
            }
            else{
                // Undirected Graph: u se v ki taraf do edge hai "u-->v" and "v-->u"
                adjList[u].push_back({v,wt});
                adjList[v].push_back({u,wt});
            }
            cout << "Printing adjList:" << endl;
            printAdjList();
            cout<<endl;
        }

        void printAdjList(){
            for(auto i: adjList){
                cout << i.first << " --> { ";
                for(pair<int,int> neighbour: i.second){
                    cout << "{ " << neighbour.first << ", " << neighbour.second << " }, ";
                }
                cout << " }" << endl;
            }
        }
};

int main(){
    // Create weighted Graph Object g
    Graph g;
    // Insert Edges to adjList
    g.addEdge(0,1,5,1);
    g.addEdge(1,2,7,1);
    g.addEdge(1,3,6,1);
    g.addEdge(2,3,8,1);
    g.addEdge(3,4,9,1);
    g.addEdge(4,5,11,1);
    g.addEdge(5,3,15,1);
    return 0;
}

/*
Expected Output:
Printing adjList:
0 --> { { 1, 5 },  }

Printing adjList:
1 --> { { 2, 7 },  }
0 --> { { 1, 5 },  }

Printing adjList:
1 --> { { 2, 7 }, { 3, 6 },  }
0 --> { { 1, 5 },  }

Printing adjList:
2 --> { { 3, 8 },  }
1 --> { { 2, 7 }, { 3, 6 },  }
0 --> { { 1, 5 },  }

Printing adjList:
3 --> { { 4, 9 },  }
2 --> { { 3, 8 },  }
1 --> { { 2, 7 }, { 3, 6 },  }
0 --> { { 1, 5 },  }

Printing adjList:
4 --> { { 5, 11 },  }
3 --> { { 4, 9 },  }
2 --> { { 3, 8 },  }
1 --> { { 2, 7 }, { 3, 6 },  }
0 --> { { 1, 5 },  }

Printing adjList:
5 --> { { 3, 15 },  }
4 --> { { 5, 11 },  }
3 --> { { 4, 9 },  }
2 --> { { 3, 8 },  }
1 --> { { 2, 7 }, { 3, 6 },  }
0 --> { { 1, 5 },  }
*/