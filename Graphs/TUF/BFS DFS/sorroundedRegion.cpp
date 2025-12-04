#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int i,int j,vector<vector<char>>& board,const int r,const int c){
        //now over here its a very simple job to do now
        queue<pair<int,int>>q;
        q.push({i,j});
        board[i][j]='#';
        int dr[]={-1,1,0,0};
        int dc[]={0,0,1,-1};

        //now just the normal bfs search bar over here
        while(!q.empty()){
            //now we can make sure that it get the bfs search and the other things
            pair<int,int>front=q.front();
            q.pop();
            int initR=front.first;
            int initC=front.second;

            //now over here just check and destroy

            //now just for its neghbours
            for(int k=0;k<4;k++){
                int newR=initR+dr[k];
                int newC=initC+dc[k];

                //now over here we will make sure that this sees bouindaries
                if(newR<r && newR>=0 && newC>=0 && newC<c){
                //now over here we will make sure that the other things also go well
                if(board[newR][newC]=='O'){
                    board[newR][newC]='#';
                    q.push({newR,newC});
                }
            }
            }
        }

        //now have an initial check over here only 
    }
    void solve(vector<vector<char>>& board) {
        //the algo is simple 
        //use normal bfs logic only
        //here we just push down the elements with 0 in the ans
        //then finally we make sure that this starting one has a 0 connected to it
        //if yes then it starts pushing in queue finding its neighbours and then straight get the element to be x
        int r=board.size();
        int c=board[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                //now just check for the current element
                if((i==0 || i==r-1 || j==0 || j==c-1) && board[i][j] == 'O'){
                    bfs(i,j,board,r,c);
                }
            }
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};