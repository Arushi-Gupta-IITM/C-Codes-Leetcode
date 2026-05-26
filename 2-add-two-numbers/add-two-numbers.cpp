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
        
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int sum = (temp1->val + temp2->val)%10;
        int carry = (temp1->val + temp2->val)/10;
        temp1 = temp1->next;
        temp2 = temp2->next;

        ListNode* head = new ListNode(sum);
        ListNode* temp = head;

        while(temp1 != NULL && temp2 != NULL) {
            sum = (temp1->val + temp2->val + carry)%10;
            carry = (temp1->val + temp2->val + carry)/10;

            ListNode* newNode = new ListNode(sum);
            temp->next = newNode;

            temp1 = temp1->next;
            temp2 = temp2->next;
            temp = temp->next;
        }

        while(temp1 != NULL) {
            sum = (temp1->val + carry)%10;
            carry = (temp1->val + carry)/10;
            ListNode* newNode = new ListNode(sum);
            temp->next = newNode;
            temp1 = temp1->next;
            temp = temp->next;
        }

        while(temp2 != NULL) {
            sum = (temp2->val + carry)%10;
            carry = (temp2->val + carry)/10;
            ListNode* newNode = new ListNode(sum);
            temp->next = newNode;
            temp2 = temp2->next;
            temp = temp->next;
        }

        if(carry != 0) {
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
        }

        return head;
    }
};