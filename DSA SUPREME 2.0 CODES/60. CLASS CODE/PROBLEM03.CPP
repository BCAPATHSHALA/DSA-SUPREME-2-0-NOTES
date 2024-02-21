// 3. Detect cycle in a directed graph using BFS
#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>

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

        void topoSortUsingBFS(int n, vector<int> &topoOrder){
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
                topoOrder.push_back(frontNode);

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
    g.addEdges(3,4,1);
    g.addEdges(4,5,1);
    g.addEdges(5,2,1);

    int n = 6;
    vector<int> topoOrder;
    g.topoSortUsingBFS(n, topoOrder);

    cout << "Printing the topo Sort ordering: " << endl;
	for(auto i: topoOrder) {
		cout << i << endl;
	}

	if(topoOrder.size() == n) {
		cout << "No Cycle " << endl;
	}
	else {
		cout << "Cycle present " << endl;
	}
    return 0;
}

/*
Expected output:
Printing the topo Sort ordering: 
0
1
Cycle present 
*/