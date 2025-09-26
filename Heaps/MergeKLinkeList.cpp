// 23. Merge k Sorted Lists
// Solved
// Hard
// Topics
// premium lock iconCompanies

// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

 

// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted linked list:
// 1->1->2->3->4->4->5->6

// Example 2:

// Input: lists = []
// Output: []

// Example 3:

// Input: lists = [[]]
// Output: []

 

// Constraints:

//     k == lists.length
//     0 <= k <= 104
//     0 <= lists[i].length <= 500
//     -104 <= lists[i][j] <= 104
//     lists[i] is sorted in ascending order.
//     The sum of lists[i].length will not exceed 104.

 
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 26,76,100/4.6M
// Acceptance Rate
// 57.7%

#include <bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

// question is a bit special where u have to make a min heap
// here we will insert the nodes so we made a custom comparision function in
// order to arrange the elements in the miin heap
class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        // now overhere just comapre
        return a->val > b->val;
    }
};class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // this is having the vectors containing the lists
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        int k = lists.size();
        if (k == 0) {
            return NULL;
        }

        for (int i = 0; i < k; i++) {
            // over here we will be inserting up the things

            // case 1
            if (lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while (pq.size() > 0) {
            ListNode* temp = pq.top();
            pq.pop();

            if(temp->next != NULL) 
            { pq.push(temp->next); }

            // checking the first condition weahter the List is empty or not
            if (head == NULL) {
                head = temp;
                tail = temp;
                // now over here inserting the ahead elements
            } else {
                tail->next = temp;
                tail = temp;
            }
        }

        return head;
    }
};