// 958. Check Completeness of a Binary Tree
// Solved
// Medium
// Topics
// premium lock iconCompanies

// Given the root of a binary tree, determine if it is a complete binary tree.

// In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

 

// Example 1:

// Input: root = [1,2,3,4,5,6]
// Output: true
// Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.

// Example 2:

// Input: root = [1,2,3,4,5,null,7]
// Output: false
// Explanation: The node with value 7 isn't as far left as possible.



#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
        }
        
        for(int i=k;i<nums.size();i++){
            //now we will add the elements top the top only if they are smaller tan the top
            if(nums[i]>pq.top()){
                //remember the the deletion and the other things act as same as u studied in the normal deletion and insertion fucntins
                pq.pop();
                pq.push(nums[i]);
            }
        }
        
        return pq.top();
    }
};