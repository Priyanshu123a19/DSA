#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;


class graph{
    public:
    unordered_map<int,list<int>> adj;

    //now over here we need fucntioun to add edges
    void addEdge(int u,int v,bool direction){
        adj[u].push_back(v);

        if(direction){
            adj[v].push_back(u);
        }
    }


    //function to print the edges and the nodes of the graph
    void printAdj(){
    for(auto i:adj){
        cout<<i.first<<"->";
        for(auto j:i.second){
            cout<<j<<",";
        }
        cout<<endl;
    }
}
};

//now the main function to tet
int main(){
    graph g;
    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;
    int m;
    cout<<"Enter the number of edges"<<endl;
    cin>>m;

    //now we will make a loop to add the edges
    for(int i=0;i<m;i++){
        int u,v;
        cout<<"Enter the u and v values"<<endl;
        cin>>u>>v;
        g.addEdge(u,v,0); //0 for undirected graph
    }

    //now just printing the adjaceny list
    g.printAdj();

    return 0;
}