#include <vector>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        // it can only be performed on DAGs
        // also the topo sort provides us with an ordering that will always show 
        // if there is an edge u->v in the grpah 
        // then u with come before v in that ordering that topo sort provides
        // this will be valid for all u->v(ie edges in the graph)
        
        // This is the BFS (Kahn's Algorithm) approach
        
        unordered_map<int,vector<int>> adj;
        vector<int> inDegree(V, 0);
        
        // now mapping and calculating in-degrees
        for(int i=0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            inDegree[v]++;     
            adj[u].push_back(v);
        }
        
        vector<int> ans;
        queue<int> q; // 1. Create ONE single queue
        
        // 2. Add ALL nodes with inDegree 0 to the queue ONCE
        for(int i=0; i < V; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        
        // 3. Run ONE main loop
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            // Add the node to our answer as it's processed
            ans.push_back(frontNode);
            
            // Iterate over neighbors
            for(int i=0; i < adj[frontNode].size(); i++){
                int neighbour = adj[frontNode][i];
                
                // Reduce the in-degree
                inDegree[neighbour]--;
                
                // If in-degree becomes 0, add it to the queue
                if(inDegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        
        // Check for a cycle. If a cycle exists, ans.size() will be less than V.
        if (ans.size() == V) {
            return ans;
        } else {
            return {}; // Return an empty vector to indicate a cycle
        }
    }
};