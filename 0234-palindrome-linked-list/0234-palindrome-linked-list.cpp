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
    bool isPalindrome(ListNode* head) 
    {
        if(head==nullptr)
         return NULL;

        ListNode* slow = head;
        ListNode* fast = head; 

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* start = head;
        ListNode* mid = slow; 

        ListNode * curr = mid;
        ListNode * prev = nullptr, * frwd = nullptr;
        while( curr )
        {
          frwd = curr->next;
          curr->next = prev;
          prev= curr;
          curr= frwd;
        }
        mid =prev;

        while( mid && start)
        {
          if(mid->val != start->val)
           return false;

          mid =mid->next;
          start=start->next; 
        }
         return true;
    }
};