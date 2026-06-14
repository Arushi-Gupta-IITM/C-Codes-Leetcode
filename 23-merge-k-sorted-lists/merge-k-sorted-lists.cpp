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

    ListNode* mergeKListsUtil(vector<ListNode*>& lists, int si, int ei) {
        if(si == ei) {
            return lists[si];
        }

        int mid = si + (ei-si)/2;
        ListNode* head1 = mergeKListsUtil(lists, si, mid);
        ListNode* head2 = mergeKListsUtil(lists, mid+1, ei);

        return merge(head1, head2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;

        if(lists.size() == 1) {
            return lists[0];
        }

        int n = lists.size();
        return mergeKListsUtil(lists, 0, n-1);
    }
};