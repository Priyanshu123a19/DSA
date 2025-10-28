#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    void setADJ(unordered_map<int,vector<int>>&adj,vector<vector<int>>& edges){
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    
    void DFS(int startNode,unordered_map<int,vector<int>>&adj,vector<bool>&visited,bool &flag,unordered_map<int,int>&parent){
    //now over here we will be making a new bfs traversal thing
    //now over here just declare the other adj values and check
    for(int i=0;i<adj[startNode].size();i++){
        if(flag) return;
        if(!visited[adj[startNode][i]]){
          visited[adj[startNode][i]]=true;
          parent[adj[startNode][i]]=startNode;
          DFS(adj[startNode][i],adj,visited,flag,parent);
        }else{
            if(parent[startNode]!=adj[startNode][i]){
                flag=true;
                return;
            }
        }
    }
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        //first we need to make the adj list
        //then the bfs code we need
        //there just one condition if its visited and also the parent then skip
        //else just say that its having a cycle
        unordered_map<int,vector<int>>adj;
        setADJ(adj,edges);
        bool flag=false;
        vector<bool>visited(V,false);
        unordered_map<int,int>parent;
        //now getting the for loop and the code ready for the bfs traversal
        //also the graph is having multiple components so now we need a for loop
        //so that all the componenets get visited
        for(int i=0;i<V;i++){
            if(!visited[i]){
                visited[i]=true;
                parent[i]=-1;
                DFS(i,adj,visited,flag,parent);
            }
        }
        
        return flag;
    }
};