// 4. Kosaraju Algorithm

/*
What is and where to use Kosaraju Algorithm:
A strongly connected component is the component of a directed graph that has a path from every vertex to every other vertex in that component. It can only be used in a directed graph.

What is a strongly connected component:
😊 Raju kisi bhi ek source node se kisi bhi ek destination node tak ja sakata hai usse hum strongly connected component kahate hai.

What is the flow of Kosaraju Algorithm:
✅Step 1: Find the order
Yeh Order Topological Sort ki tarah hi hai but Topological Sort nahi hai kyunki T.S. only Acyclic Graph par work karta hai jabki ek strongly connected component hum tabhi find karte hai jab graph me cycle present hoti hai.

Why use of this order:
Iss order se hoga yeh ki Raju two components me move kar sakta hai
Point 1: Raju current S.C.C. me move kar sakata hai yaa fir
Point 2: Raju visited S.C.C. me bhi move kar sakata hai

But Point 2 ki wajah se hamara time kharab ho raha hai to iss time ko save karane ke liye hum ek visited map ka use kar lenge to track the visited node already.

✅Step 2: Reverse all edges to create the disconnected component and store in new adjList
✅Step 3: Count the strongly connected components using DFS
*/

#include<iostream>
#include<unordered_map>
#include<limits.h>
#include<list>
#include<stack>

using namespace std; 

class Graph
{
    public:
        unordered_map<int, list<int>> adjList;

        void addEdges(int u, int v, int direction){
            if(direction == 1){
                // Directed Graph
                adjList[u].push_back(v);
            }
            else{
                // Undirected Graph
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }

        void dfs1(int node, stack<int> &ordering, unordered_map<int, bool> &visited1){
            visited1[node] = true;
            for(auto nbr: adjList[node]){
                if(!visited1[nbr]){
                    dfs1(nbr, ordering, visited1);
                }
            }
            // Backtracking to push the each node in stack
            ordering.push(node);
        }

        void dfs2(int src, unordered_map<int, bool> &visited2, unordered_map<int, list<int>> &newAdjList ){
            visited2[src] = true;
            for(auto nbr: newAdjList[src]){
                if(!visited2[nbr]){
                    dfs2(nbr, visited2, newAdjList);
                }
            }
        }

        void getStronglyConnectedComponents(int n){
            // Step 1: Get the ordering
            stack<int> ordering;
            unordered_map<int, bool> visited1;
            for(int i=0; i<n; i++){
                if(!visited1[i]){
                    dfs1(i, ordering, visited1);
                }
            }

            // Step 2: Reverse all edges
            unordered_map<int, list<int>> newAdjList;
            for(auto a: adjList){
                for(auto b: a.second){
                    int u = a.first;
                    int v = b;
                    // v->u ki new entry create karni hai
                    newAdjList[v].push_back(u);
                }
            }

            // Step 3: Traverse using ordering and count components
            int countSCC = 0;
            unordered_map<int, bool> visited2;

            while(!ordering.empty()){
                int topNode = ordering.top();
                ordering.pop();
                if(!visited2[topNode]){
                    dfs2(topNode, visited2, newAdjList);
                    countSCC++;
                }
            }

            // Get expected output
            cout<< "Strongly Connected Components: " << countSCC << endl;
        }

};

int main(){
    Graph g;
    g.addEdges(0, 1, 1);
    g.addEdges(1, 2, 1);
    g.addEdges(2, 3, 1);
    g.addEdges(3, 0, 1);

    g.addEdges(2, 4, 1);

    g.addEdges(4, 5, 1);
    g.addEdges(5, 6, 1);
    g.addEdges(6, 4, 1);

    g.addEdges(6, 7, 1);


    int n = 8;
    g.getStronglyConnectedComponents(n);
    return 0;
}

/*
Expected Output:
Strongly Connected Components: 3
*/