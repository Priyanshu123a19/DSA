#include<bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        //the bellman ford algo 
        //just loop through all the edges V-1 times
        //update their distances just like u did with the dijikstras algo
        //after doing it n-1 times
        //do it one more time and see if any distance was updated 
        //if it waas then then the negative cycle present and no ans in that case
        //if not the return the ans for the final distnace array that u got
        int infinity = 100000000;
        vector<int>dist(V,infinity);
        dist[src]=0;
        for(int i=1;i<V;i++){
            for(int j=0;j<edges.size();j++){
                //now of each of these edges we will find out the updated distance
                int u=edges[j][0];
                int v=edges[j][1];
                int wt=edges[j][2];
                
                
                //now over here we will just make sure that distance gets updated
                if(dist[u] != infinity && dist[v]>dist[u]+wt){
                    dist[v]=dist[u]+wt;
                }
            }
        }
        
        //now after this n-1 times we will do this again to see the change and detect the negative cycle
        for(int i=0;i<edges.size();i++){
            //here if any change occurs we return {-1};
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            
            
            
            //now just finish it off with all the final statement
            if(dist[u] != infinity && dist[v]>dist[u]+wt){
                return{-1};
            }
        }
        
        //else now we reutn the final ans for our dist
        return dist;
    }
};
