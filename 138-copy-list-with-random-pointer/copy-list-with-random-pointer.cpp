/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) {
            return NULL;
        }

        unordered_map<Node*, Node*> map; // stores pointers of nodes of linked list and its copy

        Node* newHead = new Node(head->val);
        map[head] = newHead;
        Node* curr1 = head->next;
        Node* curr2 = newHead;

        while(curr1 != NULL) {
            Node* newNode = new Node(curr1->val);
            curr2->next = newNode;

            curr2 = curr2->next;
            map[curr1] = curr2;
            curr1 = curr1->next;
        }

        curr1 = head;
        curr2 = newHead;

        while(curr1 != NULL) {
            if(curr1->random != NULL) {
                curr2->random = map[curr1->random];
            }

            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        return newHead;
    }
};