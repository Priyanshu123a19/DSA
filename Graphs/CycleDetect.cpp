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
    
    void BFS(int StartNode,unordered_map<int,vector<int>>&adj,vector<bool>&visited,bool &flag,unordered_map<int,int>&parent){
    //now over here we will be making a new bfs traversal thing
    queue<int>q;
    q.push(StartNode);
    visited[StartNode]=true;
    
    parent[StartNode]=-1;
    
    //now over here we will make the rest of the elements to come and get added to the queue
    while(!q.empty()){
        int frontNode=q.front();
        
        //now check for its children
        for(int i=0;i<adj[frontNode].size();i++){
            if(!visited[adj[frontNode][i]]){
                q.push(adj[frontNode][i]);
                visited[adj[frontNode][i]]=true;
                //now over here we will add some new values
                parent[adj[frontNode][i]]=frontNode;
            }else{
                //now if visited it must be its parent
                if(parent[frontNode]!=adj[frontNode][i]){
                    flag=true;
                    return;
                }
            }
        }
        q.pop();
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
                BFS(i,adj,visited,flag,parent);
            }
        }
        
        return flag;
    }
};