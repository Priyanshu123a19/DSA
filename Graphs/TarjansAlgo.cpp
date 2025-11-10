#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
  void dfs(unordered_map<int,vector<int>>&adj,vector<bool>&visited,vector<int>&disc,vector<int>&low,int parent,int &timer,bool &flag,int start,const int &c,const int &d){
      //here just normal dfs traversal
      //but just need to make sure some condition
      //at each dfs call incriment the timer
      //for each node 2 condition are main
      //if the neighbour u are going to was the parent of the current ndoe then skip it 
      //if the neghbout was already visited then its a back edge update its time by min(low[currnode],disc[neighbour]);
      //if normal dfs call can be make ie above both condirtion not there then u can use simple dfs call
      //while returning again update the low coz the child could have been a back edge and its low could have been updatred so update that with the min(low[node],low[child]);
      //finally while returning only see that weather that edge was a bridge or not formula(if(low[neighbour]>low[retrning node])) then its a bridge
      visited[start]=true;
      disc[start]=timer;
      low[start]=timer;
      timer++;
      for(int i=0;i<adj[start].size();i++){
          //contdition 1 where the neghbour is parent where just have to ignore
          if(adj[start][i]==parent){
            continue;  
          }
          
          //backedge condition ie already visited and not the parent
          else if(visited[adj[start][i]]){
              //update the values for this current node 
              low[start]=min(low[start],disc[adj[start][i]]);
          }
          
          else{
              dfs(adj,visited,disc,low,start,timer,flag,adj[start][i],c,d);
              
              
              //also the return call for each of them will be from here only so backtracking logic from here only
              
              
              low[start]=min(low[adj[start][i]],low[start]);
      
      //now finally checking that weather the bridge was there ornot
            if(low[adj[start][i]]>disc[start]){
                if ((start == c && adj[start][i] == d) || (start == d && adj[start][i] == c)){
                    flag=true;
                    return;
                }
            }
        }
      }
      
      
  }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        //simple logic for this one
        //make 4 data structures linear
        //the first one stores the discovery time
        //the second one stores the lowest time for that node
        //the third one stores the parent
        //the fourth one stores the visited array
        
        
        //lets first make the adj list
        
        unordered_map<int,vector<int>>adj;
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        //now lets make the linear data structures required and the timer
        int timer=0;
        bool flag=false;
        vector<int>disc(V,-1);
        vector<int>low(V,-1);
        int parent=-1;
        vector<bool>visited(V,false);
        
        //now simple dfs 
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(adj,visited,disc,low,parent,timer,flag,i,c,d);
            }
        }
        
        return flag;
    }
    };      

