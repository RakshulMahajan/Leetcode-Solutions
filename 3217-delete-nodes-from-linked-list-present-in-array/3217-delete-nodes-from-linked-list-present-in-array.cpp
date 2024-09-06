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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        ListNode* curr = head;
        while(curr and curr->next){
            if(st.find(curr->next->val) != st.end()){
                ListNode* temp = curr->next;
                curr->next =  curr->next->next;
                delete(temp);
            }else{
                curr = curr->next;
            }
        }
        return st.find(head->val) != st.end() ? head->next:head;
    }
};