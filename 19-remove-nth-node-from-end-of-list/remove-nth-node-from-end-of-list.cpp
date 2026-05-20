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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int size = 0;
        ListNode* curr = head;

        while(curr != NULL) {
            size++;
            curr = curr->next;
        }

        if(n == size) {
            head = head->next;
            return head;
        }

        int indOfPrev = size - n;
        int ind = 1;
        curr = head;

        while(curr != NULL) {
            if(ind == indOfPrev) {
                curr->next = curr->next->next;
                break;
            }
            ind++;
            curr = curr->next;
        }
        return head;
    }
};