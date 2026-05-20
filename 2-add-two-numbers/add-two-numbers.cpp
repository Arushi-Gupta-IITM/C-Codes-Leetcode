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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        int sum = (l1->val + l2->val)%10;
        int carry = (l1->val + l2->val)/10;
        ListNode* head = new ListNode(sum);
        ListNode* curr = head;
        ListNode* temp1 = l1->next;
        ListNode* temp2 = l2->next;

        while(temp1 != NULL && temp2 != NULL) {
            sum = (carry + temp1->val + temp2->val)%10;
            carry = (carry + temp1->val + temp2->val)/10;

            ListNode* newNode = new ListNode(sum);
            curr->next = newNode;
            curr = curr->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while(temp1 != NULL) {
            sum = (carry + temp1->val)%10;
            carry = (carry + temp1->val)/10;
            ListNode* newNode = new ListNode(sum);
            curr->next = newNode;
            curr = curr->next;
            temp1 = temp1->next;
        }

        while(temp2 != NULL) {
            sum = (carry + temp2->val)%10;
            carry = (carry + temp2->val)/10;
            ListNode* newNode = new ListNode(sum);
            curr->next = newNode;
            curr = curr->next;
            temp2 = temp2->next;
        }

        if(carry != 0) {
            ListNode* newNode = new ListNode(carry);
            curr->next = newNode;
        }

        return head;
    }
};