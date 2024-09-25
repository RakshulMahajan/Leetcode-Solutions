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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        ListNode* ntemp = head;
        int count = 0;
        int ans = 0;
        while(temp){
            temp = temp->next;
            count++;
        }
        if(count % 2 != 0){
        ans = count/2;
        while(ans){
            ntemp = ntemp->next;
            ans--;
        }
        }
        else{
            ans = count/2;
            while(ans){
            ntemp = ntemp->next;
            ans--;
        }
            
        }
    return ntemp;
    }
};