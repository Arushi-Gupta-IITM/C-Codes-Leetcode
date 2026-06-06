/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL) return head;
        Node* curr = head;

        while(curr != NULL) {
            if(curr->child == NULL) {
                curr = curr->next;
            } else {
                Node* nextNode = curr->next;
                Node* childList = flatten(curr->child);
                curr->next = childList;
                childList->prev = curr;
                curr->child = NULL;

                Node* tail = childList;
                while(tail->next != NULL) {
                    tail = tail->next;
                }
                tail->next = nextNode;
                if(nextNode != NULL) nextNode->prev = tail;
                curr = nextNode;
            }
        }

        return head;
    }
};