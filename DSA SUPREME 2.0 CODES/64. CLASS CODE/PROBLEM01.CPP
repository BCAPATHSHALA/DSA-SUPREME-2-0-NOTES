// 1. Shortest path in a weighted undirected graph using Dijkstra Algorithm

/*
What is Dijkstra Algorithm and where to use?
Dijkstra’s Algorithm is a popular graph search algorithm used to 
find the shortest path between a source node and all other nodes in a weighted, directed or undirected graph.

Note 1: It is used to find all shortest path from source to all nodes in a negative and positive weighted, directed or undirected graph.
Note 2: It is not used to when a graph have the negative cycle because of occurring the infinite loop


Dijkstra's Algorithm Applications in real life:
1. To find the shortest path from source to destination
2. In social networking applications
3. In a telephone network
4. To find the locations in the map

Dijkstra's Algorithm Complexity:
Time Complexity: O(E Log V)
Space Complexity: O(V)
where, E is the number of edges and V is the number of vertices
*/

#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>
#include<limits.h>
#include<list>
#include<set>

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

        void dijkstraShortestDistance(int n, int src, int dest) {
            vector<int> dist(n+1, INT_MAX);
            set<pair<int,int>> st;

            // Initial state
            st.insert({0,src});
            dist[src] = 0;

            // Distance updation logic 
            while (!st.empty()){
                // A. select shortest distance node from the set
                auto topElement = st.begin();  
                pair<int, int> topPair = *topElement;
                int topDist = topPair.first;
                int topNode = topPair.second;
                // B. delete the selected node from the set
                st.erase(st.begin());   

                // C. update new distance for nbr node and
                // create the new entry for the new distance in set
                for(auto nbrPair: adjList[topNode]) {
                    int nbrNode = nbrPair.first;
                    int nbrDist = nbrPair.second;

                    // Now check the distance: ki mujhe new distance update krna hai ya nhi
                    if(topDist + nbrDist < dist[nbrNode]) {
                        // Found the new distance

                        // 📝 Update the new entry to the set
                        // Find previousEntry and delete it
                        auto previousEntry = st.find({dist[nbrNode], nbrNode});
                        if(previousEntry != st.end()) {
                            // previousEntry present in set then delete it
                            st.erase(previousEntry);
                        }

                        // Update dist array for new distance
                        dist[nbrNode] = topDist + nbrDist;
                        // Create a new entry in the set for new distance
                        st.insert({dist[nbrNode], nbrNode});
                    }
                }           
            }
            cout << "Shortest Distance from " << src << " Node to " << dest << " Node: " << dist[dest] << endl;
        }
};

int main(){
    Graph g;
	g.addEdges(1,6,14,0);
	g.addEdges(1,3,9,0);
	g.addEdges(1,2,7,0);
	g.addEdges(2,3,10,0);
	g.addEdges(2,4,15,0);
	g.addEdges(3,4,11,0);
	g.addEdges(6,3,2,0);
	g.addEdges(6,5,9,0);
	g.addEdges(5,4,6,0);

    g.printAdjList();

    int n = 6;
	int src = 6;
	int dest = 4;
	g.dijkstraShortestDistance(n, src, dest);

    return 0;
}

/*
Undirected Graph adjList:
5 : { ( 6, 9 ), ( 4, 6 ),  }
4 : { ( 2, 15 ), ( 3, 11 ), ( 5, 6 ),  }
1 : { ( 6, 14 ), ( 3, 9 ), ( 2, 7 ),  }
6 : { ( 1, 14 ), ( 3, 2 ), ( 5, 9 ),  }
3 : { ( 1, 9 ), ( 2, 10 ), ( 4, 11 ), ( 6, 2 ),  }
2 : { ( 1, 7 ), ( 3, 10 ), ( 4, 15 ),  }

Shortest Distance from 6 Node to 4 Node: 13
*/