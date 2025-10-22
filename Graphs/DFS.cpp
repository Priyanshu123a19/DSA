#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    void helper(vector<vector<int>> adj,vector<int>&ans,vector<bool>&visited,int node){
        //now over here just push in the ans
        ans.push_back(node);
        visited[node]=true;
        //now check for its remaining nodes
        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i]]){
                //call the dfs again 
                helper(adj,ans,visited,adj[node][i]);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        //here also the adj list givern 
       //algo
       //first a for loop for all the vectors in the adj matrix
       //each of them dfs call for the unvisited ones
       vector<bool>visited(adj.size(),false);
       vector<int>ans; 
       for(int i=0;i<adj.size();i++){  
           //now just find weather its visited or not
           if(!visited[i]){
               helper(adj,ans,visited,i);
           }
       }
       return ans;
    }
};