/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
   int numComponents(ListNode* head, vector<int>& nums) {
        ListNode *curr = head;
        unordered_map<int, bool> mpp;
        for(int i=0; i<nums.size(); i++)
            mpp[nums[i]] = true;
        int count = 0, streak = 0;
        while(curr) {
            if(mpp[curr->val]==true) {
                streak++;
            } else {
                if(streak>0) {
                    count++;
                }
                streak = 0;
            }
            curr = curr->next;
        }
        if(streak>0) {
            count++;
        }
        return count;
    }
};