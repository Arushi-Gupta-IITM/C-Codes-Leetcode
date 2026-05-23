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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* newHead = NULL;
        ListNode* less = NULL;
        ListNode* more = NULL;
        ListNode* moreHead = NULL;
        ListNode* temp = head;

        while(temp != NULL) {
            int val = temp->val;
            ListNode* newNode = new ListNode(val);
            if(val < x) {                
                if(newHead == NULL) {                    
                    newHead = newNode;
                    less = newNode;
                } else {
                    less->next = newNode;
                    less = less->next;
                }
            } else {
                if(more == NULL) {
                    more = newNode;
                    moreHead = newNode;
                } else {
                    more->next = newNode;
                    more = more->next;
                }
            }
            temp = temp->next;
        }
        if(less != NULL) {
            less->next = moreHead;
        } else {
            newHead = moreHead;
        }        
        return newHead;
    }
};