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
    ListNode* merge(ListNode* head1, ListNode* head2) {
        if(head1 == NULL) return head2;
        if(head2 == NULL) return head1;

        ListNode* head;
        if(head1->val <= head2->val) {
            head = head1;
            head->next = merge(head1->next, head2);
        } else {
            head = head2;
            head->next = merge(head1, head2->next);
        }

        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        
        if(lists.size() == 1) {
            return lists[0];
        }

        ListNode* head1 = lists[0];
        ListNode* head2 = lists[1];

        ListNode* head = merge(head1, head2);
        lists[0] = head;
        lists.erase(lists.begin()+1);

        return mergeKLists(lists);
    }
};