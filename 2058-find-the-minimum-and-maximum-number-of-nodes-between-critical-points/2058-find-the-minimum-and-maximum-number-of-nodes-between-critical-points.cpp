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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = head;
        ListNode* curr = prev->next;
        ListNode* forw = curr->next;
        
        int cnt = 0;
        vector<int> ind;
        while(forw != NULL){
            cnt++;
            if((curr->val > prev->val && curr->val > forw->val) || 
               (curr->val < prev->val && curr->val < forw->val))
            {
                ind.push_back(cnt);
            }
            prev = prev->next;
            curr = curr->next;
            forw = forw->next;
        }
        if(ind.size() <2 ) return {-1, -1};
        int mini = INT_MAX;
        for( int i = 0; i<ind.size()-1; i++){
            mini = min(ind[i+1] - ind[i], mini);
        }
        return {mini, (ind[ind.size() - 1] - ind[0])};
    }
};