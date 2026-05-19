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
    bool isPalindrome(ListNode* head) {
        // base case or edge case
        if(head == NULL || head->next == NULL) {
            return true;
        }

        // finding middle node of the linked list
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = NULL;
        ListNode* head2;
        if(fast == NULL) {      // even
            head2 = slow;
        } else {                // odd
            head2 = slow->next;
}

        // reversing the second half of the linked list
        prev = NULL;
        ListNode* curr = head2;
        ListNode* next = NULL;

        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        head2 = prev;
        
        // comparing both linked lists
        ListNode* temp1 = head;
        ListNode* temp2 = head2;

        while(temp1 != NULL && temp2 != NULL) {
            if(temp1->val != temp2->val) return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return (temp1 == NULL && temp2 == NULL);
    }
};