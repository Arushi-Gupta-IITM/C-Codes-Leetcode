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

        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = head;

        for(int i=0; i<n; i++) {
            fast = fast->next;
        }

        if(fast == NULL) { //delete head
            ListNode* delNode = head;
            head = head->next;
            delete delNode;
            dummy->next = NULL;
            delete dummy;
            return head;
        }

        while(fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* delNode = slow->next;
        slow->next = delNode->next;
        delete delNode;

        dummy->next = NULL;
        delete dummy;
        return head;
    }
};