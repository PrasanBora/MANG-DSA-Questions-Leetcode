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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int len =0;
        ListNode* temp =head;
        
        while(head)
        {
            len++;
            head=head->next;
        }
        head = temp;
        
        if( n > len)
            return temp;
        
        if(  n == len )
            return temp->next;
        
        len =len-n;
        len--;
        
        while(head && len--)
        {
            head = head-> next;
        }
        if( head->next->next)
           head->next = head->next->next;
        else 
            head->next = NULL;
        return temp;
        
    }
};