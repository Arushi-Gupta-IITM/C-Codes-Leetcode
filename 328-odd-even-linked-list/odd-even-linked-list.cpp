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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* oddHead = head;
        ListNode* evenHead = head->next;

        ListNode* odd = head;
        ListNode* oddPrev = NULL;
        ListNode* even = head->next;

        while(even != NULL && even->next != NULL) {
            odd->next = odd->next->next;
            even->next = even->next->next;

            oddPrev = odd;
            odd = odd->next;
            even = even->next;
        }

        if(odd != NULL) {
            odd->next = evenHead;
        } else {
            oddPrev->next = evenHead;
        }

        return oddHead;
    }
};