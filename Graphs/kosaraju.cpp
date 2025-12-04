#include<bits/stdc++.h>
using namespace std;


#include <vector>
#include <stack>
using namespace std; // Added for stack and vector

class Solution {
public:
    // This function is correct
    void dfs(vector<vector<int>> &adj, int start, vector<bool>&visited, stack<int>&st) {
        visited[start] = true;
        
        for(int i = 0; i < adj[start].size(); i++) {
            // now over here ram throgh the whole of the connected neighbours of the node start and then get them 
            if(!visited[adj[start][i]]) {
                dfs(adj, adj[start][i], visited, st);
            }
        }
        
        // add this one to the stack for its returning call
        st.push(start);
    }
    
    // This function is correct
    void dfs2(vector<vector<int>> &adj, int start, vector<bool>&visited) {
        visited[start] = true;
        
        for(int i = 0; i < adj[start].size(); i++) {
            // now over here ram throgh the whole of the connected neighbours of the node start and then get them 
            if(!visited[adj[start][i]]) {
                dfs2(adj, adj[start][i], visited);
            }
        }
        
        // add this one to the stack for its returning call
        
    }
    
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        //now over here finding the transpose of this 
        // ... (your comments are all correct)
        
        // Step 1: This part is perfect
        int V = adj.size();
        vector<bool>visited(V, false);
        stack<int>st;
        for(int i = 0; i < adj.size(); i++) {
            if(!visited[i]) {
                dfs(adj, i, visited, st);
            }
        }
        
        // Step 2: Finding the transpose
        vector<vector<int>> adjj(V);
        for(int i = 0; i < adj.size(); i++) {
            for(int j = 0; j < adj[i].size(); j++) {
                int neighbour = adj[i][j];
                
                // --- FIX 1: Add to 'adjj', not 'adj' ---
                adjj[neighbour].push_back(i); 
            }
        }
        
        int ans = 0;
        // Step 3: DFS on transpose graph
        vector<bool>visited2(V, false);
        while(!st.empty()) {
            // now over here we will add the other nodes
            
            int top = st.top();
            // --- FIX 2: Pop the element to prevent infinite loop ---
            st.pop(); 
            
            // --- FIX 3: Check 'visited2', not 'visited' ---
            if(!visited2[top]) { 
                
                // --- FIX 4: Increment the answer for the new component ---
                ans++; 
                dfs2(adjj, top, visited2);
            }
        }
        
        return ans;
    }
};