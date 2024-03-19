// 5. Tarjans Algorithm (Bridges in Graph) (Leetcode-1192)

/*
Why use Tarjans Algorithm:
Used for an undirected Graph, The task is to find the Bridges in Graph.

What is Bridge in Graph:
In an undirected connected graph, a bridge is an edge removal that increases the number of disconnected components.

😊 Bridge ek aise edge hai jisko remove karane par disconnected component increase ho jate hai.

What is timer and tin & low ?
timer: this is a initial time for a node jnha par hum khade hue hai
tin: this is a current time jab hum uss node par pahunch chuke hai
low: this is a minimum time jab hum uss node par pahunch chuke hai
*/

class Solution {
public:
    void dfs(int src, int parent, unordered_map<int,list<int> >& adjList, int &timer, 
    vector<vector<int>>& ans,vector<int>& tin,vector<int>& low,unordered_map<int,bool>& visited ) {
        // Initial state
        visited[src] = true;
        tin[src] = timer;
        low[src] = timer;
        timer++;

        // Go for nbr of each src
        for(auto nbr: adjList[src]) {
            if(nbr == parent) {
                // Ignore this
                continue;
            }
            if(!visited[nbr]) {
                // Step 1: Pahle DFS call karlo jitne bhi src ke nbr hai un sabhi par
                dfs(nbr, src, adjList, timer, ans, tin, low, visited);
                // Step 2: Jab koi bhi nbr na ho to back tracking karlo
                // A: low update
                low[src] = min(low[src], low[nbr]);
                // B: bridge testing
                if(low[nbr] > tin[src]) {
                    vector<int> temp;
                    temp.push_back(src);
                    temp.push_back(nbr);
                    ans.push_back(temp);
                }
            }
            else {
                // Step 2: Ek aur raasta milgya hai iska mtlb mujhe back tracking karni hai
                // A: low update
                low[src] = min(low[src], low[nbr]);
                // B: no need of bridge testing kyunki me already yeh kam kar chuka hoonga 
                // jav pahli bar nbr visite huaa hoga
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Create the adjList
        unordered_map<int,list<int> > adjList;
        for(auto vec: connections) {
            int u = vec[0];
            int v = vec[1];
            // Undirected graph hai to u->v & v->u
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        // Main logic to get the bridge 
        int timer = 1;
        vector<vector<int>> ans;
        vector<int> low(n,0); // (Node, Low time)
        vector<int> tin(n,0); // (Node, Current time)
        int src = 0;
        int parent = -1;
        unordered_map<int,bool> visited;
        dfs(src, parent, adjList,timer,ans, tin, low,visited);
        return ans;
    }
};