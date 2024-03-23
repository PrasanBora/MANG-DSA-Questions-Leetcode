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
    void reorderList(ListNode* h) 
    {
        ListNode* head = h;
       
        ListNode * slow =head;
        ListNode * fast =head;
        
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        
        // cout<<slow->val;
        ListNode * curr=slow;
        ListNode * prev = NULL;
        ListNode * frd=NULL;
        
        while(curr)
        {
            frd=curr->next;
            curr->next=prev;
            prev=curr;
            curr=frd;
        }
         
         ListNode * mid = prev;
         ListNode * st_nxt = NULL;
         ListNode * md_nxt = NULL;
        
        while( mid->next )
        {
            st_nxt = head->next;
            head->next = mid;
            md_nxt = mid->next;
            mid->next = st_nxt;
            head = st_nxt;
            mid = md_nxt;
           
        }
        // if(head && head->next)
        //  head->next->next =NULL;

        
        return ;
    }
};