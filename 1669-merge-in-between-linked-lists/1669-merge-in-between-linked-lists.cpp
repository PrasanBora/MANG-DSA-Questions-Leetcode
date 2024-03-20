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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        ListNode * temp =list1;
        ListNode * strt ;
        ListNode * end ;
        int count=0;
        while(count <= b)
        {
            if(count==a-1)
            {
                strt=temp;
            }
            if(count==b)
            {
                end=temp->next;
                // temp->next=NULL;
                break;
            }
            temp=temp->next;
            count++;
        }
        
        ListNode * temp2=list2;
        while(temp2->next)
        {
            temp2=temp2->next;
        }
        strt->next=list2;
        temp2->next=end;

        return list1;
    }
};