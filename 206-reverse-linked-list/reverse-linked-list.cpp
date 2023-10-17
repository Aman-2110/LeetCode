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
    ListNode* rev(ListNode *head, ListNode *newHead) {
        if(head == NULL)
            return newHead;

        ListNode *nxt = head->next;
        head->next = newHead;
        return rev(nxt, head);
    }

    ListNode* reverseList(ListNode* head) {
        // ListNode* prev = NULL, *curr = head, *nxt;

        // while(curr){
        //     nxt = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = nxt;
        // }

        return rev(head, NULL);
    }
};