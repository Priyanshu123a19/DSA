// Given a Binary Search Tree. Convert a given BST into a Special Max Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied on all the nodes in the so converted Max Heap.

// Example 1:

// Input :
//                  4
//                /   \
//               2     6
//             /  \   /  \
//            1   3  5    7  

// Output : 1 2 3 4 5 6 7 
// Exaplanation :
//                7
//              /   \
//             3     6
//           /   \  /   \
//          1    2 4     5
// The given BST has been transformed into a
// Max Heap and it's postorder traversal is
// 1 2 3 4 5 6 7.

// Your task :
// You don't need to read input or print anything. Your task is to complete the function convertToMaxHeapUtil() which takes the root of the tree as input and converts the BST to max heap.
// Note : The driver code prints the postorder traversal of the converted BST.
 
// Expected Time Complexity : O(n)
// Expected Auxiliary Space : O(n)
 
// Constraints :
// 1 ≤ n ≤ 105

#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

struct Node {
    int data;
    Node *left, *right;
};

class Solution {
  public:
    void helper(Node* root,priority_queue<int>&pq){
        //now over here just traverse
        if(root==NULL){
            return;
        }
        
        helper(root->left,pq);
        pq.push(root->data);
        helper(root->right,pq);
    };
    void helper2(Node* &root,priority_queue<int>&pq){
        if(root==NULL){
            return;
        }
        
        int temp=pq.top();
        pq.pop();
        
        root->data=temp;
        //call right then left
        helper2(root->right,pq);
        helper2(root->left,pq);
    }
    void convertToMaxHeapUtil(Node* root) {
        priority_queue<int>pq;
        
        //now we just push the elements in a way they are req
        helper(root,pq);
        
        //now just push them again
        
        helper2(root,pq);
        
    }
};
