/*
What is Topological sort and where to use?
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices 
such that for every directed edge u-v, vertex u comes before v in the ordering.

Note: Topological Sorting for a graph is not possible if the graph is not a DAG.

Where to use in real life?
JAB KABHI BHI DEPENDENCY ORDER KI BAT KI JA RAHI HOGI TAB HUM TOPOLOGICAL SORT KO APPLY KAR SKTE HAI.
LIKE: 🧞‍♀️NAMRATA -> 🧞‍♂️LOVE BHAIYA -> 🧞LAKSHAY BHAIYA -> 🧟‍♀️MALIK AND 🧟‍♂️KUNAL -> NULL
EXPLANATION: 
🧞‍♀️NAMRATA KISI PAR BHI DEPEND NHI KARTI HAI BUT 🧞‍♂️LOVE BHAIYA ISS LADKI PAR DEPEND HAI KI YEH PAHLE KUCH KARGI TABHI ME KUCH KAR PAUNGA
🧞LAKSHAY BHAIYA DEPENDS ON 🧞‍♂️LOVE BHAIYA
🧟‍♀️MALIK AND 🧟‍♂️KUNAL DEPENDS ON 🧞LAKSHAY BHAIYA
NO ONE DEPENDS ON 🧟‍♀️MALIK AND 🧟‍♂️KUNAL
*/

// 1. Topological Sorting with DFS

#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>

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

        void topoSortUsingDFS(int src, unordered_map<int, bool> &visited, stack<int> &st){
            // we have already a adjList 
            visited[src] = true;

            // Goto AdjList to visite the all child of each node
            for(auto neighbour: adjList[src]){
                if(!visited[neighbour]){
                    topoSortUsingDFS(neighbour, visited, st);
                }
            }

            // When no one depends on any node then push into stack first
            // and all child of any node are visited then push node into stack
            st.push(src);
        }
};

int main(){
    Graph g;
    g.addEdges(0,1,1);
    g.addEdges(1,2,1);
    g.addEdges(2,3,1);
    g.addEdges(3,4,1);
    g.addEdges(3,5,1);
    g.addEdges(5,6,1);
    g.addEdges(4,6,1);
    g.addEdges(6,7,1);

    g.printAdjList();

    int n = 8;
    unordered_map<int, bool> visited;
    stack<int> st;
    for(auto node = 0; node < n; node++){
        if(!visited[node]){
            g.topoSortUsingDFS(node, visited, st);
        }
    }

    cout << "Print topological order from stack" << endl;
    while(!st.empty()){
        cout << st.top() << " -> ";
        st.pop();
    }
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
0 -> 1 -> 2 -> 3 -> 5 -> 4 -> 6 -> 7 -> 
*/