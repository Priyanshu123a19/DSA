#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        
        
        //part 1
        //simple algo
        //make a key array to track the dist for the current iteration 
        //the iteraation will indicate the vertice that we are at
        //then a array for tracking visited(when all true we stop)
        //then we go for the parent array where the parent will be tracked for the updated ones
        
        //part 2
        //first mark all dist for keys as infinite
        //make the src 0
        //get the src 
        //mark it true in visited
        //then get its adjs
        //then just see the distance if lesser than their current key distance than update for that key
        //mark their parent in the parent array
        //return the sum at the end of all the dist after all visited are true
        
        
        unordered_map<int,vector<pair<int,int>>>adj;
        
        //making adj
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int dist= edges[i][2];
            
            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});
        }
        
        //now lets initialize the basics
        vector<int>keys(V,INT_MAX);
        vector<bool>inserted(V,false);
        vector<int>parent(V,-1);
        int flag=0;
        
        
        //making src node 0 key to start
        keys[0]=0;
        //now lets go for the code logic(part2)
        
        //finding the min 
        while(flag<V){
            //find the min out of the unvisited keys only
            int minVal=INT_MAX;
            int mini=-1;
            for(int i=0;i<V;i++){
                //check for the visited and then see the min and then update
                if(!inserted[i] && keys[i]<minVal){
                    mini=i;
                    minVal=keys[i];
                }
            }
            
            inserted[mini]=true;
            flag++;
            //now since we got the minimum now we can update the keys and visited for the adj nodes as wel
            for(int i=0;i<adj[mini].size();i++){
                if(!inserted[adj[mini][i].first] && keys[adj[mini][i].first]>adj[mini][i].second){
                    keys[adj[mini][i].first]=adj[mini][i].second;
                    parent[adj[mini][i].first]=mini;
                }
            }
        }
        
        //now lets return the sum loop
        int ans=0;
        for(int i=0;i<keys.size();i++){
            ans+=keys[i];
        }
        
        return ans;
        
    }
};