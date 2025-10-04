#include<bits/stdc++.h>
using namespace std;


//now making up the class 
class graph{
    public :
    unordered_map<int,list<int>> adj;

    void addEdge(int u,int v,bool direction){
        //now first we will add the new edge into the adjecency list
        adj[u].push_back(v);
        //now if the graph is undirected then we will add the edge from v to u
        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void printAdj(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;
    int m;
    cout<<"Enter the number of edges"<<endl;
    cin>>m;

    graph g;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }

    g.printAdj();
}