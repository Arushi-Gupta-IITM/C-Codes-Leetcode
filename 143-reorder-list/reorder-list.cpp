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
    void reorderList(ListNode* head) {
        // base case
        if(head == NULL || head->next == NULL) {
            return;
        }
        // find mid node 
            ListNode* slow = head;
            ListNode* fast = head;

            while(fast != NULL && fast->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
            }

        // separate two lists 
        ListNode* head2 = slow->next;
        slow->next = NULL;

        // reverse the second list 
        ListNode* prev = NULL;
        ListNode* curr = head2;
        ListNode* next = NULL;

        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        head2 = prev;

        // interweave two list
        ListNode* t1 = head;
        ListNode* t2 = head2;

        ListNode* next1;
        ListNode* next2;

        while(t1 != NULL && t2 != NULL) {
            next1 = t1->next;
            t1->next = t2;

            next2 = t2->next;
            t2->next = next1;

            t1 = next1;
            t2 = next2;
        }
    }
};