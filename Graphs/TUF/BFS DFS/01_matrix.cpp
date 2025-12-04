#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();

        vector<vector<int>>ans(r,vector<int>(c,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    //just push the initial wave into the queue
                    q.push({i,j});
                }
            }
        }


        //now over here we will make sure that the wave logic is understood
        //first the zeros are pushed to make sure that the immidiate neighbours of it that are unvisited ie1
        //so we make them 1
        //and then push these ones 
        //the again we see that any neighbour of these 1s is still unvisited 
        //then we again make it 2 because it was not any immiadiate neighbour of the 0s

        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};

        //now its classic lemon traversal like earlier

        while(!q.empty()){
            pair<int,int>front=q.front();
            q.pop();
            //now get its initial row and col and then just loop and see all the dirtn
            int initialR=front.first;
            int initialC=front.second;

            for(int i=0;i<4;i++){
                int newR=initialR+dr[i];
                int newC=initialC+dc[i];

                //now lets just see the range check weather its in the range or not
                if(newR<r && newR>=0 && newC>=0 && newC<c){
                    //now just see the neighbour and see weather its unvisited or not
                    if(ans[newR][newC]==-1){
                        ans[newR][newC]=ans[initialR][initialC]+1;
                        //push it in the queue coz these values will be used for the next wave
                        q.push({newR,newC});
                    }
                }
            }
        }
        return ans;
    }
};