// 1091. Shortest Path in Binary Matrix
// Solved
// Medium
// Topics
// premium lock iconCompanies
// Hint

// Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

//     All the visited cells of the path are 0.
//     All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).

// The length of a clear path is the number of visited cells of this path.

 

// Example 1:

// Input: grid = [[0,1],[1,0]]
// Output: 2

// Example 2:

// Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
// Output: 4

// Example 3:

// Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
// Output: -1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //the algo 
        //make the adj list if req
        //since this is with unit weight so we use simple bfs Shortest path
        //get the current element of the queue
        //see its neighbours
        //if neighbour is unvisited ie intmax dist and also 0 then only update the distance 
        //similarly keep one condition to check that weather its the bottom right or not
        //if it is then its the ans return the current distance

        //start

        //initial check 
        int r=grid.size();
        int c=grid[0].size();
        if(grid[0][0]==1 || grid[r-1][c-1]==1) return -1;

        if(r == 1 && c == 1) return 1;

        //now lets go for the main algo
        vector<vector<int>>dist(r,vector<int>(c,INT_MAX));

        //now lets find the ans
        dist[0][0]=1;
        queue<pair<int,int>>q;
        q.push({0,0});

        int row[]={0,0,1,-1,1,-1,1,-1};
        int col[]={1,-1,0,0,1,1,-1,-1};
        while(!q.empty()){
            pair<int,int>front=q.front();
            q.pop();
            int currentR=front.first;
            int currentC=front.second;
            //there is a good stratergy to have a array for all the 8 dirctn that shows the dirtns
            for(int i=0;i<8;i++){
                if(currentR+row[i]<r && currentR+row[i]>=0 && currentC+col[i]<c && currentC+col[i]>=0 && grid[currentR+row[i]][currentC+col[i]]==0 && dist[currentR+row[i]][currentC+col[i]]==INT_MAX){          
                    
                    if(currentR+row[i]==r-1 && currentC+col[i]==c-1){
                        return dist[currentR][currentC]+1;
                    }
                    dist[currentR+row[i]][currentC+col[i]]=dist[currentR][currentC]+1;
                    q.push({currentR+row[i],currentC+col[i]});
                }
            }

        }

        return -1;
    }
};