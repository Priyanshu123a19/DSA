#include<bits/stdc++.h>
using namespace std;


class Graph{
    public:
    //makin gout the functon for making sure we add and then print all the edges
    vector<vector<int>> adj;
    Graph(int v){
        adj.resize(v);
    }
    void addEdge(int v,int u){
        adj[u].push_back(v);
        adj[v].push_back(u);
        //now over here we will add on some new things
    }
    
    //now just the function to priont out the the edges
    void printadj() {
        // Loop from i = 0 to the number of vertices. 'i' is our vertex number.
        for (int i = 0; i < adj.size(); ++i) {
            cout << i << " -> ";
            // Now, loop through the list of neighbors for vertex 'i'
            for (int neighbor : adj[i]) {
                cout << neighbor << ", ";
            }
            cout << endl;
        }
    }
};


class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        // Code here
        Graph g(V);
        //now just making out the new thing
        for(int i=0;i<edges.size();i++){
            int u=edges[i].first;
            int v=edges[i].second;
            
            g.addEdge(u,v);
        }
        
        return g.adj;
    }
};