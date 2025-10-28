#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        //simple algo over here just make a dfs visited array as well showing which call has already been made for a specific node
        unordered_map<int,vector<int>>adj;
        //here a inordere array also required
        vector<int>inOrder(V,0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            inOrder[v]++;
            adj[u].push_back(v);
        }
        
        //now just make the dfs calls
        queue<int>q;
        for(int i=0;i<V;i++){
            if(inOrder[i]==0){
                q.push(i);
            }
        }
        stack<int>st;
        //starting the BFS of Kahns algo using this 0 inorder degree graph

        
        while(!q.empty()){
            //now simple logic
            //adj nodes reduce the inorder degree 
            //if it becomes 0 add them to queue
            //the ones thjat get removed from the queue will be added to the stack
            int frontNode=q.front();
            q.pop();
            for(int i=0;i<adj[frontNode].size();i++){
                inOrder[adj[frontNode][i]]--;
                if(inOrder[adj[frontNode][i]]==0){
                    //add to queue
                    q.push(adj[frontNode][i]);
                }
            }
            
            st.push(frontNode);
        }
        
        if(st.size()==V){
            return false;
        }
        
        return true;
    }
};