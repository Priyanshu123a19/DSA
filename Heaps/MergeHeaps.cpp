// Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

 

// Example 1:

// Input  : 
// n = 4 m = 3
// a[] = {10, 5, 6, 2}, 
// b[] = {12, 7, 9}
// Output : 
// {12, 10, 9, 2, 5, 7, 6}
// Explanation :



 

 

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function mergeHeaps() which takes the array a[], b[], its size n and m, as inputs and return the merged max heap. Since there can be multiple solutions, therefore, to check for the correctness of your solution, your answer will be checked by the driver code and will return 1 if it is correct, else it returns 0.

 

// Expected Time Complexity: O(n.Logn)
// Expected Auxiliary Space: O(n + m)


#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
  public:
    void heapify(vector<int> &arr,int i,int n){
        int largest=i;
        int left=i*2+1;
        int right=i*2+2;
        
        //now we check for the left and the right swap part
        if(left<n && arr[left]>arr[largest]){
            largest=left;
        }
        if(right<n && arr[right]>arr[largest]){
            largest=right;
        }
        
        if(largest!=i){
            //over here we check that changed the value or not
            swap(arr[largest],arr[i]);
            heapify(arr,largest,n);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        for(int i=0;i<m;i++){
            a.push_back(b[i]);
        }
        
        //now over here we will heapify the things
        n=a.size();
        for(int i=n/2-1;i>=0;i--){
            heapify(a,i,n);
        }
        
        return a;
    }
};