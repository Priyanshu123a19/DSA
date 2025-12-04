#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(unordered_map<int,vector<int>>&adj,vector<int>&disc,vector<int>&low,int &timer,int parent,int start,vector<bool>&visited,vector<bool>&isArticulation){
        //updating the things for the current node
        visited[start]=true;
        disc[start]=timer;
        low[start]=timer;
        timer++;
        
        int children=0;
        //now the dfs call for all the other points connected to this point
        for(int i=0;i<adj[start].size();i++){
            if(parent==adj[start][i]){
                continue;
            }
            
            //now the second condition on the visited ones
            else if(visited[adj[start][i]]){
                low[start]=min(low[start],disc[adj[start][i]]);
            }
            
            else{
                //this is the exception case where we have to wathc for the bridge in the returning call
                children++;
                dfs(adj,disc,low,timer, start, adj[start][i], visited, isArticulation);
                
                //returning call to see the bridge
                
                
                
                low[start]=min(low[start],low[adj[start][i]]);
                
                //now we see the final articulation condition
                if(low[adj[start][i]]>=disc[start] && parent!=-1){
                    isArticulation[start]=true;
                }
                
            }
            
        }
            if(parent==-1 && children>1){
                isArticulation[start]=true;
            }
    }
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        
        //the algo is simple we use tarjans algo only to find the solution of this 
        //just one more condition will be added where we checked for the bridge and also one more extra condition for the starting point thatsall baaki sab same
        unordered_map<int,vector<int>>adj;
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            
            //now we map the things up
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        //making the necessary data structuires
        vector<int>disc(V,-1);
        vector<int>low(V,-1);
        int timer=0;
        int parent=-1;
        vector<bool>visited(V,false);
        vector<bool>isArticulation(V,false);
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(adj, disc, low, timer, parent, i, visited, isArticulation);
            }
        }
        
        for(int i=0;i<V;i++){
            if(isArticulation[i]){
                ans.push_back(i);
            }
        }
        if(ans.empty()){
            return {-1};
        }
        return ans;
        
    }
};