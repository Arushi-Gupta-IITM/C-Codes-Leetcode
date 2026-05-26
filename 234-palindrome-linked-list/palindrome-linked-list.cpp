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
        // base case
        if(head == NULL || head->next == NULL) {
            return head;
        }

        // finding mid node
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = NULL;
        ListNode* newHead;
        if(fast == NULL) {
            newHead = slow;
        } else {
            newHead = slow->next;
        }       

        //reverse the 2nd linked list
        prev = NULL;
        ListNode* curr = newHead;
        ListNode* next = NULL;

        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;

        }
        newHead = prev;

        // comparing two linked lists to be same
        ListNode* temp1 = head;
        ListNode* temp2 = newHead;

        while(temp2 != NULL) {
            if(temp1->val != temp2->val) return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return true;
    }
};