#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void makeSet(vector<int>&rank,vector<int>&parent,int V){
        //initially the parent of each node will be itself only
        //and also the rank will be zero initially for each of them
        for(int i=0;i<V;i++){
            rank[i]=0;
            parent[i]=i;
        }
    }
    
    //now here is the function for finding the parent of the node that we give as input
    int findParent(vector<int>&parent,int node){
        if(parent[node]==node){
            return node;
        }
        //basically here we use the property of compressing the path for each node
        //what we do basically is when the node is the not the parent of itself then we find parent of that node till we reach a node that is the parent of itself so then we attach this node directly to that node
        //thatswhy we are doing this type of return statement
        return parent[node]=findParent(parent,parent[node]);
    }
    
    void unionSet(vector<int>&rank,vector<int>&parent,int u,int v){
        //here the logic is simple 
        //1 get the parent of both u and v
        //get their ranks
        //make the lower rank node parent as the other one
        //why we do this?
        //because the rank shows the depth of that node
        //if high depth already one attach to the lower one then length will inc
        //so what we do is that we try to attach the shorter one to the already longer one
        
        int parentU=findParent(parent,u);
        int parentV=findParent(parent,v);
        
        int rankU=rank[parentU];
        int rankV=rank[parentV];
        
        if (rankU == rankV) {
            parent[parentU] = parentV;
            rank[parentV]++;
        }
        // By adding 'else' here, we guarantee only ONE of these blocks runs.
        else if (rankV > rankU) {
            parent[parentU] = parentV;
        } 
        else { // This now correctly means (rankU > rankV)
            parent[parentV] = parentU;
        }
    }
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        //the algo is simple
        //first we need the two things a parent array to track the parent of each node
        //then we require a rank array to see the rank of the current node
        //the bigger the rank the larger the tree of that node
        //now first we will initialize the two of these arrays for each of these nodes
        vector<int>rank(V);
        vector<int>parent(V);
        
        //initializing the things up
        makeSet(rank,parent,V);
        
        //now the simple Kruskals algo says what
        //first make a data structure that u find accurate storing the two vert and the weight of edge between them
        //here we already have it in this format as edges in the input
        
        
        //lets sort this thing according to the weights
        sort(edges.begin(),edges.end(),[](const vector<int>&a,const vector<int>&b){
            return a[2]<b[2];
        });
        
        //now simply traverse check and make 
        //to get the total value its very simple whereeveer u join or use the makeSet add the weight to ans
        //else skip
        
        int ans=0;
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            //now find the parent for each of them
            
            int parentU=findParent(parent,u);
            int parentV=findParent(parent,v);
            
            //cases
            if(parentU==parentV){
                //they belong to the same component so skip
                continue;
            }
            else{
                ans+=edges[i][2];
                unionSet(rank,parent,u,v);
            }
        }
        
        return ans;
    }
};