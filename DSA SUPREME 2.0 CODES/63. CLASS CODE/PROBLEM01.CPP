// 1. Number of Provinces (Leetcode-547)

/*
PROBLEM STATEMENT:
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, 
and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where 
isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

📝 ACTUAL ME PROVINCES KA MATLB HAI COMPONENTS FIND KARNA FROM DISCONNECTED GRAPH

Example 1:
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3

Constraints:
1. 1 <= n <= 200
2. n == isConnected.length
3. n == isConnected[i].length
4. isConnected[i][j] is 1 or 0.
5. isConnected[i][i] == 1
6. isConnected[i][j] == isConnected[j][i]
*/

class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int &srcNode, unordered_map<int,bool> &visited, int nodes){
        // srcNode ko true visited krdo
        visited[srcNode] = true;

        // ab srcNode ke har ek nbrNode par chechKro ki wo dono ek dusrse se connected hai ya nhi
        for(int nbrNode = 0; nbrNode < nodes; nbrNode++){
            // check both node connected or not
            if(srcNode != nbrNode && isConnected[srcNode][nbrNode] == 1){
                // check krlo nbrNode visited to nhi hai otherwise hum ek inifinite loop me fas jayenge
                if(!visited[nbrNode]){
                    dfs(isConnected, nbrNode, visited, nodes);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // Number of nodes
        int nodes = isConnected.size();
        // Number of provinces
        int count = 0;

        // Traverse from each src node 0, 1, 2, ...
        unordered_map<int,bool> visited;
        for(int srcNode = 0; srcNode < nodes; srcNode++){
            if(!visited[srcNode]){
                dfs(isConnected, srcNode, visited, nodes);
                // province is increasing by 1 when dfs call is completed
                count++;
            }
        }

        return count;
    }
};