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
    ListNode* reverseKGroupUtil(ListNode* head, int k, ListNode* prevNode) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* curr = head;
        for(int i=1; i<k; i++) {
            if(curr == NULL) return head;
            curr = curr->next;
        }
        if(curr != NULL) {
            ListNode* nextSetHead = curr->next;
            curr = head;
            ListNode* prev = prevNode;
            ListNode* next = NULL;

            while(curr != nextSetHead) {
                next = curr->next;
                curr->next = prev;

                prev = curr;
                curr = next;
            }
            head->next = reverseKGroupUtil(nextSetHead, k, head);
            return prev;
        }      

        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverseKGroupUtil(head, k, NULL);
    }
};