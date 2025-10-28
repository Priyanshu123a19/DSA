#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    void DFS(int startNode,unordered_map<int,vector<int>>&adj,vector<bool>&DFSVisited,vector<bool>&visited,bool &flag){
    //now over here the simple dfs just the node also tracked  
    for(int i=0;i<adj[startNode].size();i++){
        if(flag) return;
        if(!visited[adj[startNode][i]]){
            visited[adj[startNode][i]]=true;
            DFSVisited[adj[startNode][i]]=true;
            DFS(adj[startNode][i],adj,visited,DFSVisited,flag);
        }else{
            if(DFSVisited[adj[startNode][i]]){
                flag=true;
                return;
            }
        }
    }
        DFSVisited[startNode]=false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        //simple algo over here just make a dfs visited array as well showing which call has already been made for a specific node
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
        }
        
        vector<bool>visited(V,false);
        bool flag=false;
        vector<bool>DFSVisited(V,false);
        //now just make the dfs calls
        for(int i=0;i<V;i++){
            if(!visited[i]){
                visited[i]=true;
                DFSVisited[i]=true;
                DFS(i,adj,visited,DFSVisited,flag);
            }
        }
        return flag;
    }
};