/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        bool loop=false;
        ListNode* fast=head;
        ListNode* slow=head;

        while(slow && fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast)
            {
                loop=true;
                break;
            }
        }

        if(loop)
        {
          slow=head;
          while(slow!=fast)
          {
            slow=slow->next;
            fast=fast->next;
        
          }
          return slow;
        }
        return NULL;
        
    }
};