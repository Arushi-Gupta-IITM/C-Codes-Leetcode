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
    ListNode *detectCycle(ListNode *head) {
        // base case
        if(head == NULL || head->next == NULL) {
            return NULL;
        }

        // cycle detection
        ListNode* slow = head;
        ListNode* fast = head;
        bool isCycle = false;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) { // cycle exists
                isCycle = true;
                break;
            }
        }

        if(isCycle) {
            slow = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        } else {
            return NULL;
        }
    }
};