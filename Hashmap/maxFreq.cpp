#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        //to count the element with the maximum freq
        map<int,int>mp;

       for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
       }
        
        //making another map ans storing the things 
        map<int,int>mp2;

        auto it=mp.begin();

        while(it!=mp.end()){
            mp2[it->second]++;
            it++;
        }

        auto it2=mp2.rbegin();
        return it2->first*it2->second;
    }
};