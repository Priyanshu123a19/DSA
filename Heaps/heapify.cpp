// 912. Sort an Array
// Solved
// Medium
// Topics
// premium lock iconCompanies

// Given an array of integers nums, sort the array in ascending order and return it.

// You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

// Example 1:

// Input: nums = [5,2,3,1]
// Output: [1,2,3,5]
// Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

// Example 2:

// Input: nums = [5,1,1,2,0,0]
// Output: [0,0,1,1,2,5]
// Explanation: Note that the values of nums are not necessarily unique.

 

// Constraints:

//     1 <= nums.length <= 5 * 104
//     -5 * 104 <= nums[i] <= 5 * 104
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void heapify(vector<int>&nums,int i, int n){
        int largest=i;
        int left=i*2+1;
        int right=i*2+2;

        //checking the left and the right side
        if(left<n && nums[largest]<nums[left]){
            largest=left;
        }
        if(right<n && nums[largest]<nums[right]){
            largest=right;
        }

        if(largest!=i){
            //now just swap up and make up for the different things out there
            swap(nums[largest],nums[i]);
            heapify(nums,largest,n);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();


        //first build out the heap so that it may work on the headped already tree
        for(int i=n/2-1;i>=0;i--){
            heapify(nums,i,n);
        }
        for(int i=n-1;i>=0;i--){
            swap(nums[0],nums[i]);
            heapify(nums,0,i);
        }
        return nums;
    }
};