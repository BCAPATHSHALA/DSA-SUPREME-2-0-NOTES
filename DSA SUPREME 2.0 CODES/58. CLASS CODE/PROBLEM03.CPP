// 4. Graph Creation Using Adjacency  List

#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

//* Generalize the code of the graph creation
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
            cout << "Printing adjList:" << endl;
            printAdjList();
            cout<<endl;
        }

        void printAdjList(){
            for(auto i: adjList){
                cout << i.first << " --> { ";
                for(pair<T,int> neighbour: i.second){
                    cout << "{ " << neighbour.first << ", " << neighbour.second << " }, ";
                }
                cout << " }" << endl;
            }
        }
};

int main(){
    Graph<char> g;
    g.addEdge('a','b',5,1);
    g.addEdge('b','c',7,1);
    g.addEdge('c','d',6,1);
    g.addEdge('c','e',8,1);
    return 0;
}

/*
Expected Output:
Printing adjList:
a --> { { b, 5 },  }

Printing adjList:
b --> { { c, 7 },  }
a --> { { b, 5 },  }

Printing adjList:
c --> { { d, 6 },  }
b --> { { c, 7 },  }
a --> { { b, 5 },  }

Printing adjList:
c --> { { d, 6 }, { e, 8 },  }
b --> { { c, 7 },  }
a --> { { b, 5 },  }
*/