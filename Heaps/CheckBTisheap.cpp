// You are given a binary tree, and the task is to determine whether it satisfies the properties of a max-heap.

// A binary tree is considered a max-heap if it satisfies the following conditions:

//     Completeness: Every level of the tree, except possibly the last, is completely filled, and all nodes are as far left as possible.
//     Max-Heap Property: The value of each node is greater than or equal to the values of its children.

// Examples:

// Input: root[] = [97, 46, 37, 12, 3, 7, 31, 6, 9]
 
// Output: true
// Explanation: The tree is complete and satisfies the max-heap property.

// Input: root[] = [97, 46, 37, 12, 3, 7, 31, N, 2, 4] 
 
// Output: false
// Explanation: The tree is not complete and does not follow the Max-Heap Property, hence it is not a max-heap.

// Constraints:
// 1 ≤ number of nodes ≤ 103
// 1 ≤ node->data ≤ 103




#include <bits/stdc++.h>
class Solution {
    class Node {
       public:
        int data;
        Node *left;
        Node *right;
    
        Node(int val) {
            data = val;
            left = right = NULL;
        }
    };
  public:
    int countNode(Node* root){
        if(root==NULL){
            return 0;
        }
        
        return 1+countNode(root->left)+ countNode(root->right);
    }
    bool isCBT(Node* root,int index,int totalNode){
        if(root==NULL){
            return true;
        }
        
        if(index>=totalNode){
            return false;
        }
        //now here us the main crux of the problems that we see
        bool left=isCBT(root->left,index*2+1,totalNode);
        bool right=isCBT(root->right,index*2+2,totalNode);
        
        //now over here we will make a new return accroding to the corrections'
        return left&&right;
    }
    bool isHep(Node* root){
        if(root==NULL){
            return true;
        }
        if(root->right==NULL && root->left==NULL){
            return true;
        }
        
        //last condition is just check the left and the right node accoridng to the conditions
        if(root->right==NULL){
            //this is an optimal step
            //see if its a CBT then if it doesnt have a right then it must have a left or NULL also we dont need to go any further that thats left of right because any one mising means it is the end level node that have only be partially empry
            return (root->data > root->left->data) && isHep(root->left);
        }
        else{
            //means both of them present because if right not null then left must exist due to CBT
            bool left=isHep(root->left);
            bool right=isHep(root->right);
            return (left && right && (root->data>root->left->data)&&(root->right->data<root->data));
            //here we need to explore further down
        }
    }
    bool isHeap(Node* tree) {
        // code here
        int totalNode=countNode(tree);
        
        //nwo over here we need 2 boolians that are the 
        //1. is it a complete binary tree 
        int index=0;
        if(isCBT(tree,index,totalNode)&&isHep(tree)){
            return true;
        }
        else{
            return false;
        }
        
    }
};