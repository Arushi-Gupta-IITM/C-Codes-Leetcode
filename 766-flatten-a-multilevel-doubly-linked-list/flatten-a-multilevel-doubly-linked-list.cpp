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

        Node* nextNode = head->next;
        Node* childList = flatten(head->child);
        Node* nextList = flatten(nextNode);

        Node* tail = childList;
        while(tail != NULL && tail->next != NULL) {
            tail = tail->next;
        }

        if(childList != NULL) {
            head->next = childList;
            childList->prev = head;
            tail->next = nextList;
            if(nextList != NULL) nextList->prev = tail;
        } else {
            head->next = nextList;
            if(nextList != NULL) nextList->prev = head;
        }

        head->child = NULL;
        return head;
    }
};