#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution {
  public:
  void DFSTopo(unordered_map<int,vector<pair<int,int>>>&adj, vector<bool>&visited,int startNode,stack<int>&st){
    visited[startNode]=true;
    for(int i=0;i<adj[startNode].size();i++){
        if(!visited[adj[startNode][i].first]){
            DFSTopo(adj,visited,adj[startNode][i].first,st);
        }
    }
    //now here the callback for the current recursion will occur and now we will add that in out stack
    st.push(startNode);
  }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        //the algo
        //first find the adj list
        //then try to find the topo sort order
        //that stack from topo....u get
        //make a new distance array 
        //initial all infinite just 0th node ie starting node will be 0 
        //the pop the stack update the distance
        //at the end u will have the ans
        
        
        unordered_map<int,vector<pair<int,int>>>adj;
        vector<bool>visited(V,false);
        vector<int>distance(V,INT_MAX);
        stack<int>st;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int dist=edges[i][2];
            
            //now add them to our list
            
            adj[u].push_back({v,dist});
            //hence we formed out array with distance values as well
        }
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                DFSTopo(adj,visited,i,st);
            }
        }
        
        //now we have the topo sort and lets make a new distance array
        distance[0]=0;
        
        //now just traverse it all and update the distances thats all
        
        while(!st.empty()){
            int top=st.top();
            st.pop();
            
            if(distance[top]==INT_MAX){
                continue;
            }
            
            for(int i=0;i<adj[top].size();i++){
                //now for all its element use the current el
                if(distance[adj[top][i].first]>distance[top]+adj[top][i].second){
                distance[adj[top][i].first]=distance[top]+adj[top][i].second;
                }
            }
        }
        
        for (int i = 0; i < V; i++) {
            if (distance[i] == INT_MAX) {
            distance[i] = -1;
            }
        }
        
        return distance;
        
    }
};
