#include <bits/stdc++.h> 
using namespace std;
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<int,vector<int>,greater<int>>pq;

    for(int i=0;i<k;i++){
        for(int j=0;j<kArrays[i].size();j++){
            //adding the element at the top now
            pq.push(kArrays[i][j]);
        }
    } 
    vector<int>ans;
    //now just extract the things but in a not repeated pattern
    while (!pq.empty()) {
        int temp = pq.top();
        pq.pop();

        // This combined condition does the same thing as your if/else block.
        // It adds the element if either the vector is empty OR
        // the new element is different from the last one added.
        ans.push_back(temp);
    }
    
    return ans;
}
