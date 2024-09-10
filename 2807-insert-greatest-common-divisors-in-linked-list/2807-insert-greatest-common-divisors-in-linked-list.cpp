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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            int GCD = __gcd(temp->val, temp->next->val);
            ListNode* newNode = new ListNode(GCD);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }
        return head;
    }
};