#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> traversal(vector<int>&ans,vector<bool>visited,vector<vector<int>> adj){
        //getting the first node ready
        queue<int>q;
        q.push(0);
        visited[0]=true;
        
        while(!q.empty()){
            //gett the front node
            int frontNode=q.front();
            ans.push_back(frontNode);
            //now check for its visitedness and add its children accordingly
                for(int i=0;i<adj[frontNode].size();i++){
                    if(!visited[adj[frontNode][i]]){
                    visited[adj[frontNode][i]]=true;
                    q.push(adj[frontNode][i]);
                    }
                }
            //now pop this node
            q.pop();
        }
        
        return ans;
    }
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        vector<int>ans;
        vector<bool>visited(adj.size(),false);
        
        
        //now over here we will call the function directly for making the bfs traversal
        return traversal(ans,visited,adj);
    }
};