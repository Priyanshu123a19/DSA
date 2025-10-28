#include<bits/stdc++.h>
using namespace std;






using namespace std;

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        // Kept your unordered_map as requested
        unordered_map<int,vector<pair<int,int>>>adj;
        
        // fabricating the adj (no changes)
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int dist=edges[i][2];
            
            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});
        }
        
        // making the distance array (no changes)
        vector<int>dist(V,INT_MAX);
        
        // FIX: Replaced std::set with std::priority_queue
        // This creates a min-heap, which is what we need (smallest distance first)
        priority_queue<pair<int, int>, 
                       vector<pair<int, int>>, 
                       greater<pair<int, int>>> pq;

        
        dist[src]=0;
        
        // FIX: Use .push() instead of .insert()
        pq.push({0,src});
        
        // FIX: Use !pq.empty()
        while(!pq.empty()){
            // FIX: Get top element with .top()
            auto topElement = pq.top(); 
            int currDist = topElement.first;
            int current = topElement.second;
            
            // FIX: Remove top element with .pop()
            pq.pop(); 
            
            // Stale check (no change, this logic is perfect)
            if(currDist > dist[current]) continue;
            
            // Loop logic (no change)
            for(int i=0;i<adj[current].size();i++){
                int neighborNode = adj[current][i].first; // (just added var for clarity)
                int edgeWeight = adj[current][i].second; // (just added var for clarity)
                
                int nowDist=currDist + edgeWeight;
                
                if(nowDist < dist[neighborNode]){
                    dist[neighborNode] = nowDist;
                    
                    // FIX: Use .push() instead of .insert()
                    pq.push({nowDist, neighborNode}); 
                }
            }
            // (Removed st.erase(st.begin()), as pq.pop() is at the top)
        }
        
        return dist;
    }
};