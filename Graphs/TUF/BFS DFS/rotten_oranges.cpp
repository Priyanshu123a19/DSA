#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int r=grid.size();
        int c=grid[0].size();
        int count=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    //mark that orange up in the queue
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    count++;
                }else{
                    continue;
                }
            }
        }
        if(count==0)return 0;
        int timer=0;
        //now just the bfs thing with the queue
        while(!q.empty()){
            //now over here get the front element 
            //smash uske aage peeche upar neeche
            int size=q.size();
            bool didRotSomething=false;

            while(size--){

            pair<int,int>front=q.front();
            int localR=front.first;
            int localC=front.second;
            q.pop();
            if(localR+1<r && grid[localR+1][localC]==1){
                grid[localR+1][localC]=2;
                count--;
                q.push({localR+1,localC});
                didRotSomething=true;
            }
            if(localR-1>=0 && grid[localR-1][localC]==1){
                grid[localR-1][localC]=2;
                count--;
                q.push({localR-1,localC});
                didRotSomething=true;
            }
            if(localC+1<c && grid[localR][localC+1]==1){
                grid[localR][localC+1]=2;
                count--;
                q.push({localR,localC+1});
                didRotSomething=true;
            }
            if(localC-1>=0 && grid[localR][localC-1]==1){
                grid[localR][localC-1]=2;
                count--;
                q.push({localR,localC-1});
                didRotSomething=true;
            }
            }
            if(didRotSomething){
            timer++;
            }
            //now the 4 conditions for it
            //also need to check for their existance also 
        }

        if(count==0){
        return timer;
        }
        return -1;

    }
};