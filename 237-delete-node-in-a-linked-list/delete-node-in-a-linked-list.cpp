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
    void deleteNode(ListNode* node) {
        ListNode* curr = node;
        ListNode* prev = NULL;
        int next = 0;

        while(curr->next != NULL) {
            next = curr->next->val;
            curr->val = next;
            prev = curr;
            curr = curr->next;
        }

        prev->next = NULL;
    }
};