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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
     
        int n=0;
        ListNode* t=head;
        
        while(t){
            t=t->next;
            n++;
        }
        
        vector<ListNode*> result(k,nullptr); 
        
        ListNode* next_node;
        int i=0;
        int rem=(n%k);
        int size=0;
       
        while(head){
         
            size = n/k;
            if(rem) size++;
            ListNode* start = head;
            
            while(--size > 0 && head->next){
                head=head->next;
            }
            
            result[i]=start;
            next_node=head->next;
            head->next=nullptr;
            head=next_node;
            
            if(rem>0) rem--; 
            i++;
        
        }
        
        return result;
    
    }
};