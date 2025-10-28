#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void DFS(int startNode,unordered_map<int,vector<int>>&adj,vector<bool>&visited,stack<int>&st){
    //getting the other elements of this startNode
    for(int i=0;i<adj[startNode].size();i++){
        if(!visited[adj[startNode][i]]){
            visited[adj[startNode][i]]=true;
            DFS(adj[startNode][i],adj,visited,st);
        }
    }
    //now just push at the return call
    st.push(startNode);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        //it can only be performed on DAGs
        //also the topo sort provides us with an ordering that will always show 
        //if there is an edge u->v in the grpah 
        //then u with come before v in that ordering that topo sort provides
        //this will be valid for all u->v(ie edges in the graph)
        
        //algo 
        
        //normal dfs code
        //just maintain a stack 
        //the element that get the return call in the recursion 
        //just add that in the stack 
        //get the stack elements in the vector 
        //return it
        
        unordered_map<int,vector<int>>adj;
        
        //now mapping
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
        }
        
        vector<bool>visited(V,false);
        stack<int>st;
        //now over here i will call the dfs in the systemmm manner
        for(int i=0;i<V;i++){
            //now over here we will add osme new edges
            if(!visited[i]){
                visited[i]=true;
                DFS(i,adj,visited,st);
            }
        }
        
        vector<int>ans;
        while(!st.empty()){
            int temp=st.top();
            ans.push_back(temp);
            st.pop();
        }
        
        return ans;
    }
};