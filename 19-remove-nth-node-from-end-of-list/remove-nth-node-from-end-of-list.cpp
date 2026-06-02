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
        // one pass solution
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        for(int i=0; i<n; i++) {
            fast = fast->next;
        }

        while(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        if(slow == dummy) { // delete headNode
            head = head->next;
        }

        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        delete dummy;
        return head;
    }
};