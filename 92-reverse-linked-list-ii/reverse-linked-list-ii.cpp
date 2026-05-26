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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        if(left == right) {
            return head;
        }

        ListNode* prev = NULL;
        ListNode* next = NULL;

        ListNode* temp = head;
        int pos = 1;

        ListNode* newHead = NULL;
        ListNode* newTail = NULL;

        while(temp != NULL) {
            if(pos + 1 == left) {
                prev = temp;
                newHead = prev->next;
            }
            if(pos == right) {
                newTail = temp;
                next = temp->next;
            }
            pos++;
            temp = temp->next;
        }

        if(prev != NULL) {
            prev->next = NULL;
        }
        if(left == 1) {
            newHead = head;
        }
        newTail->next = NULL;

        // reverse linked list from newHead till newTail
        ListNode* prevNode = NULL;
        ListNode* currNode = newHead;
        ListNode* nextNode = NULL;
        
        while(currNode != NULL) {
            nextNode = currNode->next;
            currNode->next = prevNode;

            prevNode = currNode;
            currNode = nextNode;
        }

        if(prev != NULL) {
            prev->next = prevNode;
        }
        if(prev == NULL) {
            head = prevNode;
        }
        if(newHead != NULL) {
            newHead->next = next;
        }
        
        return head;
    }
};